#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "SceneNull.h"
#include "SceneGame.h"
#include "SceneOptions.h"

static SceneNull nullScene;

Game::Game(Camera& camera, EL& EL) : scene_{&nullScene}
{
    LP_.Load();
    MP_.Load();

    AddScene("Options", new SceneOptions(this, EL));
    AddScene("Game", new SceneGame(this, camera));

    scene_ = scenes_["Options"];
    scene_->Init();
}

Game::~Game()
{
    Clear();
}

void Game::Update(float delta_time)
{
    scene_->Update(delta_time);
}

void Game::Draw(Camera& camera) const
{
    scene_->Draw(camera);
}

void Game::AddScene(const std::string& name, Scene* scene)
{
    scenes_[name] = scene;
}

void Game::ChangeScene(const std::string& newScene)
{
    EndScene();
    scene_ = scenes_[newScene];
    scene_->Init();
}

void Game::EndScene()
{
    scene_->End();
    scene_ = &nullScene;
}

LP& Game::GetLP()
{
    return LP_;
}

MP& Game::GetMP()
{
    return MP_;
}

Options* Game::GetOptions()
{
    return &options_;
}

void Game::Clear()
{
    scene_->End();

    for (auto pair : scenes_)
    {
        delete pair.second;
    }
    scenes_.clear();
}
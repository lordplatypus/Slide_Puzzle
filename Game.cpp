#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "SceneNull.h"
#include "SceneGame.h"

static SceneNull nullScene;

Game::Game(Camera* camera) : scene_{&nullScene}, camera_{camera}
{
    loadImage_.Load();

    AddScene("Game", new SceneGame(this));

    scene_ = scenes_["Game"];
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

void Game::Draw()
{
    scene_->Draw();
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

Camera* Game::GetCamera()
{
    return camera_;
}

void Game::PlayMusic(const int musicID, const bool loop)
{
    musicPlayer_.PlayMusic(musicID, loop);
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
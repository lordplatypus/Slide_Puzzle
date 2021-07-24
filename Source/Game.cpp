#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "SceneNull.h"
#include "SceneGame.h"
#include "SceneOptions.h"

static SceneNull nullScene;

Game::Game(Camera& camera, TI* ti) : ti_{ti}, scene_{&nullScene}
{
    loadAssets_.Load();

    AddScene("Options", new SceneOptions(this));
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

void Game::Clear()
{
    scene_->End();

    for (auto pair : scenes_)
    {
        delete pair.second;
    }
    scenes_.clear();
}


//For MiniGames

void Game::SetWin(const bool win)
{
    win_ = win;
}

bool Game::GetWin() const
{
    return win_;
}



Options* Game::GetOptions()
{
    return &options_;
}

TI* Game::GetTI()
{
    return ti_;
}

const bool Game::AddImage(const std::string& filePath)
{
    return loadAssets_.AddImage(filePath);
}
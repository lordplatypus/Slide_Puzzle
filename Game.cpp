#include <SFML/Graphics.hpp>
#include <string>
#include "IP.h"
#include "Game.h"
#include "SceneNull.h"
#include "SceneGame.h"

static SceneNull nullScene;

Game::Game(Camera* camera) : scene_{&nullScene}
{
    loadAssets_.Load();

    AddScene("Game", new SceneGame(this, camera));

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
    IP::Reset();
}

void Game::Draw(sf::RenderWindow& render_window)
{
    scene_->Draw(render_window);
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
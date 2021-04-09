#include "SceneGame.h"
#include "LP.h"
#include "ID.h"

sf::Sprite pic;

SceneGame::SceneGame(Game* game) : game_{game}
{}

SceneGame::~SceneGame()
{}

void SceneGame::Init()
{
    game_->SetWin(false);
    //game_->GetCamera()->SetCameraViewSize(1920, 1080);
    //game_->GetCamera()->SetTarget(sf::Vector2f(1920/2, 1080/2));

    pic = LP::SetSprite(pic_texture_);
    pic.scale(sf::Vector2f(.5f, .5f));
    pic.setPosition(sf::Vector2f(0.0f, 0.0f));

    //game_->GetCamera()->SetTarget(sf::Vector2f(0.0f, 0.0f));
}

void SceneGame::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects
    gom_.Collision(); //check collision between gameobjects
    gom_.Remove(); //remove "dead" gameobjects
}

void SceneGame::Draw(sf::RenderWindow& render_window) const
{
    gom_.Draw(render_window); //Draw all gameobjects

    game_->GetCamera()->SetCurrentView("Main");
    render_window.draw(pic);
    game_->GetCamera()->SetCurrentView("Test");
    render_window.draw(pic);
}

void SceneGame::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject); //add gameobject to the list of gameobjects
}

GameObject* SceneGame::FindGameObject(const std::string& string, const bool byTag, const bool byID)
{
    if (byID)
    {
        return gom_.Find(std::stoi(string));
    }
    else
    {
        if (byTag) return gom_.Find(string);
        else return gom_.Find(string, false);
    }
    return nullptr;
}

void SceneGame::ChangeGameObjectOrder(const std::string& name, const std::string& newPos)
{
    gom_.ChangeListOrder(name, newPos);
}

void SceneGame::OnWin()
{
    game_->SetWin(true);
}

void SceneGame::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneGame::End()
{
    gom_.Clear();
}
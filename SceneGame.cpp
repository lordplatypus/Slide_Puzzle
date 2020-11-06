#include "SceneGame.h"
#include "LP.h"
#include "ID.h"

SceneGame::SceneGame(Game* game) : game_{game}
{}

SceneGame::~SceneGame()
{}

void SceneGame::Init()
{
    game_->SetWin(false);
    //game_->GetCamera()->SetCameraViewSize(1920, 1080);
    //game_->GetCamera()->SetTarget(sf::Vector2f(1920/2, 1080/2));
}

void SceneGame::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects
    gom_.Collision(); //check collision between gameobjects
    gom_.Remove(); //remove "dead" gameobjects
}

void SceneGame::Draw()
{
    gom_.Draw(); //Draw all gameobjects
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
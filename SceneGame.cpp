#include "SceneGame.h"
#include "LP.h"
#include "ID.h"
#include "TestObject.h"

SceneGame::SceneGame(Game* game, Camera* camera) : game_{game}, camera_{camera}
{}

SceneGame::~SceneGame()
{}

void SceneGame::Init()
{
    game_->SetWin(false);

    camera_->SetView("Main");
    camera_->SetView("UI");

    AddGameObject(new TestObject(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.1f, 0.1f), layer_UI_, 2, this));
    AddGameObject(new TestObject(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.25f, 0.25f), layer_main_, 1, this));
    //AddGameObject(new TestObject(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.5f, 0.5f), layer_tilemap_, 0));
    SortGameObjects();
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

void SceneGame::SortGameObjects()
{
    gom_.SortByLayers();
}

sf::View* SceneGame::FindView(const std::string& viewName)
{
    return camera_->GetView(viewName);
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
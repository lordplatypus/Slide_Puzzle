#include "SceneGame.h"
#include "LP.h"
#include "ID.h"
#include "TestObject.h"

SceneGame::SceneGame(Game* game) : game_{game}
{}

SceneGame::~SceneGame()
{}

void SceneGame::Init()
{
    game_->SetWin(false);

    //TEST
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

    //TEST
    FindView("Main")->setCenter(FindGameObject("1", false, false, true)->GetPosition());
}

void SceneGame::Draw(sf::RenderWindow& render_window) const
{
    gom_.Draw(render_window); //Regular draw - Draw GameObjects in order based on position in the list
    gom_.DelayedDraw(render_window); //draw things after Regular draw is finished, helpful for UI or things that should always be drawn last
}

void SceneGame::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject); //add gameobject to the list of gameobjects
}

GameObject* SceneGame::FindGameObject(const std::string& string, const bool byName, const bool byTag, const bool byID)
{//if byTag and byID are both left to default (false), search by name
    return gom_.Find(string, byName, byTag, byID); //returns a GameObject, returns a nullptr if the GameObject is not found
}

void SceneGame::SortGameObjects()
{
    gom_.SortByLayers();
}

sf::View* SceneGame::FindView(const std::string& viewName)
{
    return game_->GetCamera()->GetView(viewName);
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
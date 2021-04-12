#include "SceneGame.h"
#include "LP.h"
#include "ID.h"
#include "ObjectMap.h"
#include "ObjectChar.h"
#include "ObjectUI.h"

SceneGame::SceneGame(Game* game) : game_{game}
{}

SceneGame::~SceneGame()
{}

void SceneGame::Init()
{
    game_->SetWin(false);

    //TEST
    int count = 0;
    AddGameObject(new ObjectUI(sf::Vector2f(960/2, 540-32), count, this));
    count++;
    AddGameObject(new ObjectChar(sf::Vector2f(16, 16), count, this));
    for (int x = 0; x < 960; x += 64)
    {
        for (int y = 0; y < 540; y += 64)
        {
            count++;
            AddGameObject(new ObjectMap(sf::Vector2f(x, y), count, this));   
        }
    }

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
#include "SceneGame.h"
#include "LP.h"
#include "ID.h"
#include "IP.h"
#include "PuzzleManager.h"
#include "Hint.h"

SceneGame::SceneGame(Game* game) : game_{game}
{}

SceneGame::~SceneGame()
{}

void SceneGame::Init()
{
    game_->SetWin(false);

    srand (time(NULL));

    sf::Vector2f textureSize = sf::Vector2f(LP::GetTexture(image_texture_).getSize().x, LP::GetTexture(image_texture_).getSize().y);

    if (textureSize.x < textureSize.x * 9 / 16) FindView("Main")->setSize(sf::Vector2f(textureSize.x, textureSize.x * 9 / 16));
    else if (textureSize.y < textureSize.y * 16 / 9) FindView("Main")->setSize(sf::Vector2f(textureSize.y * 16 / 9, textureSize.y));
    else
    {
        if (textureSize.x > textureSize.y) FindView("Main")->setSize(sf::Vector2f(textureSize.x * 16 / 9, textureSize.y));
        else FindView("Main")->setSize(sf::Vector2f(textureSize.x, textureSize.y * 9 / 16));
    }
    FindView("Main")->setCenter(sf::Vector2f(textureSize.x / 2, textureSize.y / 2));

    AddGameObject(new PuzzleManager(this, game_->GetOptions()->GetRowNum(), game_->GetOptions()->GetColumnNum(), textureSize));
    AddGameObject(new Hint(this));
}

void SceneGame::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects
    gom_.Collision(); //check collision between gameobjects
    gom_.Remove(); //remove "dead" gameobjects

    if (IP::PressX()) ChangeScene("Options");
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
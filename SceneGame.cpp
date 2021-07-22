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

    if (textureSize.x < textureSize.x * 9 / 16) FindView("Game")->setSize(sf::Vector2f(textureSize.x, textureSize.x * 9 / 16));
    else if (textureSize.y < textureSize.y * 16 / 9) FindView("Game")->setSize(sf::Vector2f(textureSize.y * 16 / 9, textureSize.y));
    else
    {
        if (textureSize.x > textureSize.y) FindView("Game")->setSize(sf::Vector2f(textureSize.x * 16 / 9, textureSize.y));
        else FindView("Game")->setSize(sf::Vector2f(textureSize.x, textureSize.y * 9 / 16));
    }
    FindView("Game")->setCenter(sf::Vector2f(textureSize.x / 2, textureSize.y / 2));

    AddGameObject(new PuzzleManager(this, game_->GetOptions(), textureSize));
    AddGameObject(new Hint(this));

    background_.setSize(FindView("Game")->getSize());
    if (textureSize.x < textureSize.x * 9 / 16) background_.setPosition(sf::Vector2f(0.0f, 0.0f - (FindView("Game")->getSize().y / 2 - textureSize.y / 2)));
    else if (textureSize.y < textureSize.y * 16 / 9) background_.setPosition(sf::Vector2f(0.0f - (FindView("Game")->getSize().x / 2 - textureSize.x / 2), 0.0f));
    else background_.setPosition(sf::Vector2f(0.0f, 0.0f));
    background_.setFillColor(sf::Color(game_->GetOptions()->GetBackgroundRed(), game_->GetOptions()->GetBackgroundGreen(), 
                                       game_->GetOptions()->GetBackgroundBlue(), game_->GetOptions()->GetBackgroundAlpha()));
}

void SceneGame::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects
    gom_.Collision(); //check collision between gameobjects
    gom_.Remove(); //remove "dead" gameobjects

    if (IP::PressX()) ChangeScene("Options");
    if (changeScene_) ChangeSceneForReal(changeSceneTo_);
}

void SceneGame::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(background_);
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
    changeSceneTo_ = sceneName;
    changeScene_ = true;
}

void SceneGame::End()
{
    gom_.Clear();
}

void SceneGame::ChangeSceneForReal(const std::string& sceneName)
{
    changeScene_ = false;
    game_->ChangeScene(sceneName);
}
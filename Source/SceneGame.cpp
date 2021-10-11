#include "SceneGame.h"
#include "LP.h"
#include "ID.h"
#include "PuzzleManager.h"
#include "Hint.h"

SceneGame::SceneGame(Game* game, Camera& camera) : game_{game}, camera_{&camera}
{}

SceneGame::~SceneGame()
{}

void SceneGame::Init()
{
    srand (time(NULL));

    sf::Vector2f textureSize = sf::Vector2f(game_->GetLP().GetTexture(image_texture_).getSize().x, game_->GetLP().GetTexture(image_texture_).getSize().y);

    if (textureSize.x < textureSize.x * 9 / 16) camera_->SetViewport("Game", sf::Vector2f(textureSize.x, textureSize.x * 9 / 16));
    else if (textureSize.y < textureSize.y * 16 / 9) camera_->SetViewport("Game", sf::Vector2f(textureSize.y * 16 / 9, textureSize.y));
    else
    {
        if (textureSize.x > textureSize.y) camera_->SetViewport("Game", sf::Vector2f(textureSize.x * 16 / 9, textureSize.y));
        else camera_->SetViewport("Game", sf::Vector2f(textureSize.x, textureSize.y * 9 / 16));
    }
    camera_->SetViewCenter("Game", sf::Vector2f(textureSize.x / 2, textureSize.y / 2));

    AddGameObject(new PuzzleManager(this, game_->GetOptions(), textureSize, game_->GetLP()));
    AddGameObject(new Hint(this, game_->GetLP()));

    background_.setSize(camera_->GetView("Game").getSize());
    if (textureSize.x < textureSize.x * 9 / 16) background_.setPosition(sf::Vector2f(0.0f, 0.0f - (camera_->GetView("Game").getSize().y / 2 - textureSize.y / 2)));
    else if (textureSize.y < textureSize.y * 16 / 9) background_.setPosition(sf::Vector2f(0.0f - (camera_->GetView("Game").getSize().x / 2 - textureSize.x / 2), 0.0f));
    else background_.setPosition(sf::Vector2f(0.0f, 0.0f));
    background_.setFillColor(sf::Color(game_->GetOptions()->GetOption("Background Red"), game_->GetOptions()->GetOption("Background Green"), 
                                       game_->GetOptions()->GetOption("Background Blue"), game_->GetOptions()->GetOption("Background Alpha")));
}

void SceneGame::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects
    gom_.Collision(); //check collision between gameobjects
    gom_.Remove(); //remove "dead" gameobjects

    if (IP_.GetButtonDown(sf::Keyboard::X)) ChangeScene("Options");
    if (changeScene_) ChangeSceneForReal(changeSceneTo_);

    IP_.Update();
}

void SceneGame::Draw(Camera& camera) const
{
    camera.Draw(background_);
    gom_.Draw(camera); //Regular draw - Draw GameObjects in order based on position in the list
    gom_.DelayedDraw(camera); //draw things after Regular draw is finished, helpful for UI or things that should always be drawn last
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
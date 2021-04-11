#ifndef SCENE_GAME_H_
#define SCENE_GAME_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"

class SceneGame : public Scene
{
public:
    SceneGame(Game* game, Camera* camera);
    ~SceneGame();
    virtual void Init() override;
    virtual void Update(float delta_time) override;
    virtual void Draw(sf::RenderWindow& render_window) const override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual GameObject* FindGameObject(const std::string& string, const bool byTag = true, const bool byID = false) override;
    virtual void SortGameObjects() override;
    virtual sf::View* FindView(const std::string& viewName) override;
    virtual void OnWin() override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

private:
    Game* game_{nullptr};
    Camera* camera_{nullptr};
    GameObjectManager gom_;
};

#endif
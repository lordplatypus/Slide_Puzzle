#ifndef SCENE_GAME_H_
#define SCENE_GAME_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"

class SceneGame : public Scene
{
public:
    SceneGame(Game* game);
    ~SceneGame();
    virtual void Init() override;
    virtual void Update(float delta_time) override;
    virtual void Draw() override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

private:
    Game* game_{nullptr};
    GameObjectManager gom_;
};

#endif
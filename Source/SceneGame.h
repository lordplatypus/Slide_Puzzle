#ifndef SCENE_GAME_H_
#define SCENE_GAME_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "ParticleManager.h"
#include "IP.h"

class SceneGame : public Scene
{
public:
    SceneGame(Game* game, Camera& camera);
    ~SceneGame();
    virtual void Init() override;
    virtual void Update(float delta_time) override;
    virtual void Draw(Camera& camera) const override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual GameObject* FindGameObject(const std::string& string, const bool byName = true, const bool byTag = false, const bool byID = false) override;
    virtual void SortGameObjects() override;
    virtual void OnWin() override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

private:
    void ChangeSceneForReal(const std::string& sceneName);

private:
    Game* game_{nullptr};
    Camera* camera_{nullptr};
    GameObjectManager gom_;
    ParticleManager pm_;
    IP IP_;

    sf::RectangleShape background_;

    bool changeScene_{false};
    std::string changeSceneTo_{""};
};

#endif
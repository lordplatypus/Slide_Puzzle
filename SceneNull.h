#ifndef SCENE_NULL_H_
#define SCENE_NULL_H_
#include "Scene.h"

//Null scene, used as a buffer when switching scenes
class SceneNull : public Scene
{
public:
    virtual void Init() override {}
    virtual void Update(float delta_time) override {}
    virtual void Draw() override {}
    virtual void AddGameObject(GameObject* gameObject) override {}
    virtual void OnWin() override;
    virtual void ChangeScene(const std::string& sceneName) override {}
    virtual void End() override {}
};

#endif
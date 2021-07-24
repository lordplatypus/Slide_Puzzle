#ifndef GAME_H_
#define GAME_H_
#include <unordered_map>
#include "Scene.h"
#include "LP.h"
#include "MP.h"
#include "Camera.h"
#include "Options.h"
#include "TI.h"

class Game
{
public:
    Game(Camera& camera, TI* ti);
    ~Game();
    //Update Game
    void Update(float delta_time);
    //Draw Game
    void Draw(Camera& camera) const;
    //Add a Scene to the scene map
    void AddScene(const std::string& name, Scene* scene);
    //Switch to a different scene
    void ChangeScene(const std::string& newScene);
    //End a scene
    void EndScene();

    LP& GetLP();
    MP& GetMP();
    Options* GetOptions();
    TI* GetTI();

    //Called on program shutdown, delete scenes here
    void Clear();

    Game(const Game& other) = delete;
    Game& operator = (const Game& other) = delete;

private:
    //Stores scenes with string key
    std::unordered_map<std::string, Scene*> scenes_;
    //Current loaded scene
    Scene* scene_ {nullptr};
    //load assets
    LP LP_;
    MP MP_;

    //Win status
    bool win_{false};

    //Options
    Options options_;

    //Text Input
    TI* ti_{nullptr};
};

#endif
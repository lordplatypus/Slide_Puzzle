#ifndef GAME_H_
#define GAME_H_
#include <unordered_map>
#include "Scene.h"
#include "LoadAssets.h"
#include "Camera.h"

class Game
{
public:
    Game(Camera* camera);
    ~Game();
    //Update Game
    void Update(float delta_time);
    //Draw Game
    void Draw(sf::RenderWindow& render_window);
    //Add a Scene to the scene map
    void AddScene(const std::string& name, Scene* scene);
    //Switch to a different scene
    void ChangeScene(const std::string& newScene);
    //End a scene
    void EndScene();
    Camera* GetCamera();
    //Called on program shutdown, delete scenes here
    void Clear();

    //For MiniGames
    //need to save win status so that the minigame scene has access to the info
    void SetWin(const bool win);
    //but this must be reset everytime manually before starting the next minigame
    bool GetWin() const;

    Game(const Game& other) = delete;
    Game& operator = (const Game& other) = delete;

private:
    //Stores scenes with string key
    std::unordered_map<std::string, Scene*> scenes_;
    //Current loaded scene
    Scene* scene_ {nullptr};
    Camera* camera_{nullptr};
    //load assets
    LoadAssets loadAssets_;

    //Win status
    bool win_{false};
};

#endif
#ifndef GAME_H_
#define GAME_H_
#include <unordered_map>
#include "Scene.h"
#include "LoadAssets.h"
#include "Camera.h"
#include "Options.h"
#include "TI.h"

class Game
{
public:
    Game(Camera* camera, TI* ti);
    ~Game();
    //Update Game
    void Update(float delta_time);
    //Draw Game
    void Draw(sf::RenderWindow& render_window);
    //Get Camera
    Camera* GetCamera();
    //Add a Scene to the scene map
    void AddScene(const std::string& name, Scene* scene);
    //Switch to a different scene
    void ChangeScene(const std::string& newScene);
    //End a scene
    void EndScene();
    //Called on program shutdown, delete scenes here
    void Clear();

    //For MiniGames
    //need to save win status so that the minigame scene has access to the info
    void SetWin(const bool win);
    //but this must be reset everytime manually before starting the next minigame
    bool GetWin() const;

    Options* GetOptions();
    TI* GetTI();
    const bool AddImage(const std::string& filePath);

    Game(const Game& other) = delete;
    Game& operator = (const Game& other) = delete;

private:
    //Stores scenes with string key
    std::unordered_map<std::string, Scene*> scenes_;
    //Current loaded scene
    Scene* scene_ {nullptr};
    //Camera - view manager
    Camera* camera_{nullptr};
    //load assets
    LoadAssets loadAssets_;

    //Win status
    bool win_{false};

    //Options
    Options options_;

    //Text Input
    TI* ti_{nullptr};
};

#endif
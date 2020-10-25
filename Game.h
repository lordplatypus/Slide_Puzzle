#ifndef GAME_H_
#define GAME_H_
#include <unordered_map>
#include "Scene.h"
#include "LoadImage.h"
#include "MusicPlayer.h"

class Game
{
public:
    Game();
    ~Game();
    //Update Game
    void Update(float delta_time);
    //Draw Game
    void Draw();
    //Add a Scene to the scene map
    void AddScene(const std::string& name, Scene* scene);
    //Switch to a different scene
    void ChangeScene(const std::string& newScene);
    //End a scene
    void EndScene();
    //Play Mmusic
    void PlayMusic(const int musicID, const bool loop);
    //Called on program shutdown, delete scenes here
    void Clear();

    Game(const Game& other) = delete;
    Game& operator = (const Game& other) = delete;

private:
    //Stores scenes with string key
    std::unordered_map<std::string, Scene*> scenes_;
    //Current loaded scene
    Scene* scene_ {nullptr};
    //load images
    LoadImage loadImage_;
    //load music
    MusicPlayer musicPlayer_;
};

#endif
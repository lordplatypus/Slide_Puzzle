#ifndef SCENE_OPTIONS_H_
#define SCENE_OPTIONS_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "ParticleManager.h"
#include "SceneGame.h"
#include "Button.h"
#include "Counter.h"
#include "IP.h"
#include "EL.h"
#include "FileManager.h"

class SceneOptions : public Scene
{
public:
    SceneOptions(Game* game, EL& EL);
    ~SceneOptions();
    virtual void Init() override;
    virtual void Update(float delta_time) override;
    virtual void Draw(Camera& camera) const override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual GameObject* FindGameObject(const std::string& string, const bool byName = true, const bool byTag = false, const bool byID = false) override;
    virtual void SortGameObjects() override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

    void MainMenu();
    void SecondaryMenu();
    void SetColorExample();
    void SetOption();

private:
    Game* game_{nullptr};
    GameObjectManager gom_;
    ParticleManager pm_;
    IP IP_;
    EL* EL_{nullptr};
    FileManager FM_;

    enum State{Main, Secondary};
    State state_{Main};

    int selectedOption_{0};
    int temp_{0};

    std::vector<Button*> buttons_;
    std::vector<Counter*> counters_;

    Button* imagePath_{nullptr};
    std::string oldFilePath_{"image.png"};

    Button* randomEmptyBox_{nullptr};
    bool random_{false};

    sf::Text instructions_;
    std::vector<std::string> instructionsText_;

    sf::RectangleShape exampleColorBox_;

    //For the Image select menu
    std::vector<Button*> imageText_;
    int imageSelect_{0};
};

#endif
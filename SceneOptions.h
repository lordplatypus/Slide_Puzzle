#ifndef SCENE_OPTIONS_H_
#define SCENE_OPTIONS_H_
#include "Scene.h"
#include "Game.h"
#include "GameObjectManager.h"
#include "ParticleManager.h"
#include "SceneGame.h"
#include "Button.h"
#include "Counter.h"

class SceneOptions : public Scene
{
public:
    SceneOptions(Game* game);
    ~SceneOptions();
    virtual void Init() override;
    virtual void Update(float delta_time) override;
    virtual void Draw(sf::RenderWindow& render_window) const override;
    virtual void AddGameObject(GameObject* gameObject) override;
    virtual GameObject* FindGameObject(const std::string& string, const bool byName = true, const bool byTag = false, const bool byID = false) override;
    virtual void SortGameObjects() override;
    virtual sf::View* FindView(const std::string& viewName) override;
    virtual void OnWin() override;
    virtual void ChangeScene(const std::string& sceneName) override;
    virtual void End() override;

    void MainMenu();
    void ImageMenu();
    void RowMenu();
    void ColumnMenu();
    void RedMenu();
    void GreenMenu();
    void BlueMenu();

private:
    Game* game_{nullptr};
    GameObjectManager gom_;
    ParticleManager pm_;

    enum State{Main, Image, Row, Column, Red, Green, Blue};
    State state_{Main};

    int selectedOption_{0};
    int temp_{0};

    std::vector<Button*> buttons_;
    std::vector<Counter*> counters_;

    Button* imagePath_{nullptr};
};

#endif
#ifndef PUZZLE_MANAGER_H_
#define PUZZLE_MANAGER_H_
#include "GameObject.h"
#include "PictureBox.h"
#include "EmptyBox.h"
#include "WinText.h"
#include "Options.h"
#include "IP.h"
#include "LP.h"

class PuzzleManager : public GameObject
{
public:
    PuzzleManager(Scene* scene, Options* options, const sf::Vector2f& textureSize, LP& LP);
    ~PuzzleManager() override;
    void Update(float delta_time) override;
    //void Draw(sf::RenderWindow& render_window) const override;

private:
    void Input();
    void Randomizer();

private:
    IP IP_;
    std::vector<PictureBox*> pictureBox_;
    EmptyBox* emptyBox_;
    WinText* winText_;

    int rowNum_{0};
    int columnNum_{0};
    float width_{0.0f};
    float height_{0.0f};
    bool numDisplay_{false};
    bool outlineDisplay_{false};
    sf::Vector2f textureSize_{0.0f, 0.0f};
};

#endif
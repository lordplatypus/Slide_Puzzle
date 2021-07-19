#ifndef PUZZLE_MANAGER_H_
#define PUZZLE_MANAGER_H_
#include "GameObject.h"
#include "PictureBox.h"
#include "EmptyBox.h"
#include "Options.h"

class PuzzleManager : public GameObject
{
public:
    PuzzleManager(Scene* scene, Options* options, const sf::Vector2f& textureSize);
    ~PuzzleManager() override;
    void Update(float delta_time) override;
    //void Draw(sf::RenderWindow& render_window) const override;

private:
    void Input();
    void Randomizer();

private:
    std::vector<PictureBox*> pictureBox_;
    EmptyBox* emptyBox_;

    int rowNum_{0};
    int columnNum_{0};
    float width_{0.0f};
    float height_{0.0f};
    bool numDisplay_{false};
    sf::Vector2f textureSize_{0.0f, 0.0f};
};

#endif
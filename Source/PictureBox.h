#ifndef PICTURE_BOX_H_
#define PICTURE_BOX_H_
#include "GameObject.h"
#include "Options.h"

class PictureBox : public GameObject
{
public:
    PictureBox(Scene* scene, const sf::Vector2f& position, const int ID, Options* options, const sf::Vector2f& textureSize);
    ~PictureBox() override;
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;

    void SetPosition(const sf::Vector2f& position, const int ID);
    void SetNumDisplay(const bool numDisplay);
    void SetOutlineDisplay(const bool outlineDisplay);

    void IsCorrectPosition();
    void SetIsCorrectPosition(const bool correctPosition);
    const bool GetIsCorrectPosition() const;

private:
    int truePositionID_{0}; //stores it's beggining ID before randomization (correct location)
    bool correctPosition_{false};
    sf::RectangleShape outline_;
    sf::Vector2f outlineOffset_{0.0f, 0.0f};

    sf::Text num_;
    bool numDisplay_{false};
    bool outlineDisplay_{false};
    sf::Vector2f numOffset_{0.0f, 0.0f};
};

#endif
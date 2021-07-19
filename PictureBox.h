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

private:
    sf::Text num_;
    bool numDisplay_{false};
    sf::Vector2f numOffset_{16.0f, 16.0f};
};

#endif
#ifndef FADE_OUT_TEXT_H_
#define FADE_OUT_TEXT_H_
#include "GameObject.h"
#include "LP.h"

class FadeOutText : public GameObject
{
public:
    FadeOutText(const sf::Text& text, const sf::Vector2f& position, const float alpha = 255.0f, const float speed = 100.0f);
    ~FadeOutText() override;
    void Update(float delta_time) override;
    void Draw(Camera& camera) const override;

private:
    sf::Text text_;
    //Fade out variables
    float speed_{100.0f};
    float alpha_{255.0f};
};

#endif
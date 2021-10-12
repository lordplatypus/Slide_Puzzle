#include "FadeOutText.h"
#include "ID.h"

FadeOutText::FadeOutText(const sf::Text& text, const sf::Vector2f& position, const float alpha, const float speed)
{
    name_ = "FadeOutText";
    tag_ = "FadeOut";
    SetActive(false);
    layerID_ = layer_UI_;

    text_ = text;
    position_ = position;
    text_.setPosition(position_);
    alpha_ = alpha;
    speed_ = speed;
}

FadeOutText::~FadeOutText()
{}

void FadeOutText::Update(float delta_time)
{
    alpha_ -= speed_ * delta_time;
    text_.setFillColor(sf::Color(255, 255, 255, alpha_));
    if (alpha_ <= 0.0f) 
        Kill();
}

void FadeOutText::Draw(Camera& camera) const
{
    camera.Draw(text_);
}
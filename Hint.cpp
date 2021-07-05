#include "Hint.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"
#include "Math.h"

Hint::Hint(Scene* scene)
{
    scene_ = scene;
    name_ = "Hint";
    tag_ = "Hint";
    position_ = sf::Vector2f(0.0f, 0.0f);
    layerID_ = layer_UI_;
    SetActive(false);

    //Sprite set up
    sprite_ = LP::SetSprite(image_texture_, position_);
}

Hint::~Hint()
{}

void Hint::Update(float delta_time)
{
}

void Hint::Draw(sf::RenderWindow& render_window) const
{
    //Set view (if using multiple views)
    render_window.setView(*scene_->FindView("Main"));

    //Draw sprite to render window
    if (IP::GetButton(sf::Keyboard::LControl)) render_window.draw(sprite_);
}
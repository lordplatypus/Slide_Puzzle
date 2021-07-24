#include "Hint.h"
#include "ID.h"
#include "Math.h"

Hint::Hint(Scene* scene, LP& LP)
{
    scene_ = scene;
    name_ = "Hint";
    tag_ = "Hint";
    position_ = sf::Vector2f(0.0f, 0.0f);
    layerID_ = layer_UI_;
    SetActive(false);

    //Sprite set up
    sprite_ = LP.SetSprite(image_texture_, position_);
}

Hint::~Hint()
{}

void Hint::Update(float delta_time)
{
    if (IP_.GetButton(sf::Keyboard::LShift)) active_ = true;
    else active_ = false;
    IP_.Update();
}

void Hint::Draw(Camera& camera) const
{
    //Set view (if using multiple views)
    camera.SetCurrentView("Game");

    //Draw sprite to render window
    if (active_) camera.Draw(sprite_);
}
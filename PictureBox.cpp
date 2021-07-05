#include "PictureBox.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"
#include "Math.h"

PictureBox::PictureBox(Scene* scene, const sf::Vector2f& position, const int ID, const int rowNum, const int columnNum, const sf::Vector2f& textureSize)
{
    scene_ = scene;
    name_ = "PictureBox";
    tag_ = "PB";
    position_ = position;
    velocity_ = position_;
    layerID_ = layer_main_;
    ID_ = ID;
    SetActive(false);
    imageWidth_ = textureSize.x / columnNum;
    imageHeight_ = textureSize.y / rowNum;

    //Sprite set up
    sprite_ = LP::SetSprite(image_texture_, imageWidth_, imageHeight_, ID_, position_);

    num_ = LP::SetText(std::to_string(ID_), position_ + numOffset_);
    num_.setFillColor(sf::Color::Black);
}

PictureBox::~PictureBox()
{}

void PictureBox::Update(float delta_time)
{
    velocity_ = Math::Lerp(velocity_, position_, 10.0f * delta_time);
    sprite_.setPosition(velocity_);
    num_.setPosition(velocity_ + numOffset_);
}

void PictureBox::Draw(sf::RenderWindow& render_window) const
{
    //Set view (if using multiple views)
    render_window.setView(*scene_->FindView("Main"));

    //Draw sprite to render window
    render_window.draw(sprite_);
    if (numDisplay_) render_window.draw(num_);
}

void PictureBox::SetPosition(const sf::Vector2f& position, const int ID)
{
    position_ = position;
    ID_ = ID;
}

void PictureBox::SetNumDisplay(const bool numDisplay)
{
    numDisplay_ = numDisplay;
}
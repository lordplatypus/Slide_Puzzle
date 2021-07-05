#include "EmptyBox.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"
#include "Math.h"

EmptyBox::EmptyBox(Scene* scene, const sf::Vector2f& position, const int ID, const int rowNum, const int columnNum, const sf::Vector2f& textureSize)
{
    scene_ = scene;
    name_ = "EmptyBox";
    tag_ = "EB";
    position_ = position;
    velocity_ = position_;
    layerID_ = layer_main_;
    ID_ = ID;
    imageWidth_ = textureSize.x / columnNum;
    imageHeight_ = textureSize.y / rowNum;
    SetActive(false);

    //Sprite set up
    //sprite_ = LP::SetSprite("texture id", position_);
    rect_.setSize(sf::Vector2f(imageWidth_, imageHeight_));
    rect_.setPosition(position_);
    rect_.setFillColor(sf::Color::Black);
}

EmptyBox::~EmptyBox()
{}

void EmptyBox::Update(float delta_time)
{
    velocity_ = Math::Lerp(velocity_, position_, 10.0f * delta_time);
    rect_.setPosition(velocity_);
}

void EmptyBox::Draw(sf::RenderWindow& render_window) const
{
    //Set view (if using multiple views)
    render_window.setView(*scene_->FindView("Main"));

    //Draw sprite to render window
    render_window.draw(rect_);
}

void EmptyBox::SetPosition(const sf::Vector2f& position, const int ID)
{
    position_ = position;
    ID_ = ID;
}
#include "EmptyBox.h"
#include "ID.h"
#include "Math.h"

EmptyBox::EmptyBox(Scene* scene, const sf::Vector2f& position, const int ID, Options* options, const sf::Vector2f& textureSize)
{
    scene_ = scene;
    name_ = "EmptyBox";
    tag_ = "EB";
    position_ = position;
    velocity_ = position_;
    layerID_ = layer_main_;
    ID_ = ID;
    imageWidth_ = textureSize.x / options->GetOption("Column");
    imageHeight_ = textureSize.y / options->GetOption("Row");
    SetActive(false);

    //Sprite set up
    //sprite_ = LP::SetSprite("texture id", position_);
    rect_.setSize(sf::Vector2f(imageWidth_, imageHeight_));
    rect_.setPosition(position_);
    rect_.setFillColor(sf::Color(options->GetOption("Empty Red"), options->GetOption("Empty Green"), 
                                 options->GetOption("Empty Blue"), options->GetOption("Empty Alpha")));
}

EmptyBox::~EmptyBox()
{}

void EmptyBox::Update(float delta_time)
{
    velocity_ = Math::Lerp(velocity_, position_, 10.0f * delta_time);
    rect_.setPosition(velocity_);
}

void EmptyBox::Draw(Camera& camera) const
{
    //Set view (if using multiple views)
    camera.SetCurrentView("Game");

    //Draw sprite to render window
    camera.Draw(rect_);
}

void EmptyBox::SetPosition(const sf::Vector2f& position, const int ID)
{
    position_ = position;
    ID_ = ID;
}
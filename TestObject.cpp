#include "TestObject.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"

TestObject::TestObject(const sf::Vector2f& position, const sf::Vector2f& scale, int layerID, int ID)
{
    name_ = "TestObject";
    tag_ = "Test";
    position_ = position;
    layerID_ = layerID;
    ID_ = ID;

    sprite_ = LP::SetSprite(pic_texture_, position_);
    sprite_.setScale(scale);

    text_ = LP::SetText(std::to_string(layerID_), sf::Vector2f(ID_ * 64.0f, 0.0f));
}

TestObject::~TestObject()
{}

void TestObject::Update(float delta_time)
{
    if (ID_ == 0 && IP::GetButton(sf::Keyboard::Z))
    {
        if (IP::PressUp()) layerID_++;
        else if (IP::PressDown()) layerID_--;
        text_.setString(std::to_string(layerID_));
    }
    else if (ID_ == 1 && IP::GetButton(sf::Keyboard::X))
    {
        if (IP::PressUp()) layerID_++;
        else if (IP::PressDown()) layerID_--;
        text_.setString(std::to_string(layerID_));
    }
    else if (ID_ == 2 && IP::GetButton(sf::Keyboard::C))
    {
        if (IP::PressUp()) layerID_++;
        else if (IP::PressDown()) layerID_--;
        text_.setString(std::to_string(layerID_));
    }
}

void TestObject::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(sprite_);
    render_window.draw(text_);
}
#include "TestObject.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"

TestObject::TestObject(const sf::Vector2f& position, const sf::Vector2f& scale, int layerID, int ID, Scene* scene)
{
    scene_ = scene;
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
    // if (ID_ == 0 && IP::GetButton(sf::Keyboard::Z))
    // {
    //     if (IP::PressUp()) layerID_++;
    //     else if (IP::PressDown()) layerID_--;
    //     text_.setString(std::to_string(layerID_));
    // }
    // else if (ID_ == 1 && IP::GetButton(sf::Keyboard::X))
    // {
    //     if (IP::PressUp()) layerID_++;
    //     else if (IP::PressDown()) layerID_--;
    //     text_.setString(std::to_string(layerID_));
    // }
    // else if (ID_ == 2 && IP::GetButton(sf::Keyboard::C))
    // {
    //     if (IP::PressUp()) layerID_++;
    //     else if (IP::PressDown()) layerID_--;
    //     text_.setString(std::to_string(layerID_));
    // }

    if (layerID_ > layer_main_) return;

    if (IP::PressA())
    {
        position_.x -= 64.0f;
        sprite_.setPosition(position_);
    }
    if (IP::PressD())
    {
        position_.x += 64.0f;
        sprite_.setPosition(position_);
    }
    if (IP::PressW())
    {
        position_.y -= 64.0f;
        sprite_.setPosition(position_);
    }
    if (IP::PressS())
    {
        position_.y += 64.0f;
        sprite_.setPosition(position_);
    }

    scene_->FindView("Main")->setCenter(position_); //target
}

void TestObject::Draw(sf::RenderWindow& render_window) const
{
    if (layerID_ == layer_main_)
    {
        render_window.setView(*scene_->FindView("Main"));
        render_window.draw(sprite_);
        render_window.draw(text_);
    }
    else
    {
        render_window.setView(*scene_->FindView("UI"));
        render_window.draw(sprite_);
        render_window.draw(text_);
    }
    //render_window.draw(sprite_);
    //render_window.draw(text_);
}
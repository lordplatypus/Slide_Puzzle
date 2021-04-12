#include "ObjectChar.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"

ObjectChar::ObjectChar(const sf::Vector2f& position, int ID, Scene* scene)
{
    scene_ = scene;
    name_ = "ObjectChar";
    tag_ = "Char";
    position_ = position;
    layerID_ = layer_main_;
    ID_ = ID;

    rect_.setSize(sf::Vector2f(32.0f, 32.0f));
    rect_.setPosition(position_);
    rect_.setFillColor(sf::Color::Magenta);
}

ObjectChar::~ObjectChar()
{}

void ObjectChar::Update(float delta_time)
{
    if (IP::PressA())
    {
        position_.x -= 64.0f;
        rect_.setPosition(position_);
    }
    if (IP::PressD())
    {
        position_.x += 64.0f;
        rect_.setPosition(position_);
    }
    if (IP::PressW())
    {
        position_.y -= 64.0f;
        rect_.setPosition(position_);
    }
    if (IP::PressS())
    {
        position_.y += 64.0f;
        rect_.setPosition(position_);
    }

    scene_->FindView("Main")->setCenter(position_); //target
}

void ObjectChar::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));

    render_window.draw(rect_);
}
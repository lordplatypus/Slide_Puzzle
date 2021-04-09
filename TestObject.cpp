#include "TestObject.h"
#include "ID.h"
#include "LP.h"

TestObject::TestObject(const sf::Vector2f& position, const sf::Vector2f& scale, int layerID)
{
    name_ = "TestObject";
    tag_ = "Test";
    position_ = position;
    layerID_ = layerID;

    sprite_ = LP::SetSprite(pic_texture_, position_);
    sprite_.setScale(scale);
}

TestObject::~TestObject()
{}

void TestObject::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(sprite_);
}
#include "ObjectMap.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"

ObjectMap::ObjectMap(const sf::Vector2f& position, int ID, Scene* scene)
{
    scene_ = scene;
    name_ = "ObjectMap";
    tag_ = "Map";
    position_ = position;
    layerID_ = layer_tilemap_;
    ID_ = ID;

    rect_.setSize(sf::Vector2f(60.0f, 60.0f));
    rect_.setOrigin(sf::Vector2f(-2.0f, -2.0f));
    rect_.setPosition(position_);
    rect_.setFillColor(sf::Color::White);
}

ObjectMap::~ObjectMap()
{}

void ObjectMap::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("Main"));

    render_window.draw(rect_);
}
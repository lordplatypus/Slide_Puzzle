#include "ObjectUI.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"

ObjectUI::ObjectUI(const sf::Vector2f& position, int ID, Scene* scene)
{
    scene_ = scene;
    name_ = "ObjectUI";
    tag_ = "UI";
    position_ = position;
    layerID_ = layer_UI_;
    ID_ = ID;

    text_ = LP::SetText("This is the UI", position_);
    text_.setFillColor(sf::Color::Red);
    LP::SetTextOriginCenter(&text_);
}

ObjectUI::~ObjectUI()
{}

void ObjectUI::Draw(sf::RenderWindow& render_window) const
{
    render_window.setView(*scene_->FindView("UI"));

    render_window.draw(text_);

    //render_window.setView(*scene_->FindView("Main"));
}
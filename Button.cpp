#include "Button.h"
#include "LP.h"

Button::Button(const std::string& buttonText, const sf::Vector2f& position)
{
    SetPosition(position);
    // buttonText_.setString(buttonText);
    // buttonText_.setPosition(position);

    buttonText_ = LP::SetText(buttonText, position);
}

Button::~Button()
{}

void Button::Draw(sf::RenderWindow& render_window) const
{
    render_window.draw(buttonText_);
}

void Button::SetActive(const bool active)
{
    active_ = active;

    if (!active_) buttonText_.setFillColor(sf::Color(255, 255, 255, 100));
    else buttonText_.setFillColor(sf::Color(255, 255, 255, 255));
}

bool Button::GetActive() const
{
    return active_;
}

void Button::SetPosition(const sf::Vector2f& position)
{
    position_ = position;
    buttonText_.setPosition(position_);
}

const sf::Vector2f& Button::GetPosition() const
{
    return position_;
}

void Button::SetString(const std::string& string)
{
    buttonText_.setString(string);
}

const std::string& Button::GetString()
{
    return buttonText_.getString();
}

void Button::Action()
{}
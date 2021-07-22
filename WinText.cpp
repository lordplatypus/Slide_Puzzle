#include "WinText.h"
#include "LP.h"
#include "IP.h"

WinText::WinText(Scene* scene, Options* options)
{
    scene_ = scene;

    text_ = LP::SetText("You did it!\nGood job I guess.\nPress Enter to\nhide this text.\nPress Enter again to\nreturn to the options menu.", scene_->FindView("Main")->getCenter(), 64);
    LP::SetTextOriginCenter(&text_);
    text_.setFillColor(sf::Color(options->GetNumRed(), options->GetNumGreen(), options->GetNumBlue(), options->GetNumAlpha()));
    text_.setOutlineThickness(1.0f);
    text_.setOutlineColor(sf::Color::White);

    background_.setSize(sf::Vector2f(1920.0f, 540.0f));
    background_.setPosition(sf::Vector2f(0.0f, 270.0f));
    background_.setFillColor(sf::Color(options->GetBackgroundRed(), options->GetBackgroundGreen(), 
                                       options->GetBackgroundBlue(), options->GetBackgroundAlpha()));
}

WinText::~WinText()
{}

void WinText::Update(float delta_time)
{
    if (!active_) return;

    if (IP::PressEnter())
    {
        if (!showText_) scene_->ChangeScene("Options");
        showText_ = false;
    }
}

void WinText::Draw(sf::RenderWindow& render_window) const
{
    if (!active_ || !showText_) return;

    render_window.setView(*scene_->FindView("Main"));
    render_window.draw(background_);
    render_window.draw(text_);
}

void WinText::SetActive(const bool active)
{
    active_ = active;
}

const bool WinText::GetActive() const
{
    return active_;
}
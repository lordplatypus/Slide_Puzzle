#include "WinText.h"
#include "LP.h"

WinText::WinText(Scene* scene, Options* options)
{
    scene_ = scene;

    text_ = LP::SetText("You did it!\nGood job I guess.\nPress Enter to\nhide this text.\nPress Enter again to\nreturn to the options menu.", sf::Vector2f(1920.0f/2, 1080.0f/2), 64);
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

    if (IP_.GetButtonDown(sf::Keyboard::Enter))
    {
        if (!showText_) scene_->ChangeScene("Options");
        showText_ = false;
    }
}

void WinText::Draw(Camera& camera) const
{
    if (!active_ || !showText_) return;

    camera.SetCurrentView("Main");
    camera.Draw(background_);
    camera.Draw(text_);
}

void WinText::SetActive(const bool active)
{
    active_ = active;
}

const bool WinText::GetActive() const
{
    return active_;
}
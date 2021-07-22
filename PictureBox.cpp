#include "PictureBox.h"
#include "ID.h"
#include "LP.h"
#include "IP.h"
#include "Math.h"

PictureBox::PictureBox(Scene* scene, const sf::Vector2f& position, const int ID, Options* options, const sf::Vector2f& textureSize)
{
    scene_ = scene;
    name_ = "PictureBox";
    tag_ = "PB";
    position_ = position;
    velocity_ = position_;
    layerID_ = layer_main_;
    ID_ = ID;
    truePositionID_ = ID;
    SetActive(false);
    imageWidth_ = textureSize.x / options->GetColumnNum();
    imageHeight_ = textureSize.y / options->GetRowNum();

    //Sprite set up
    sprite_ = LP::SetSprite(image_texture_, imageWidth_, imageHeight_, ID_, position_);

    num_ = LP::SetText(std::to_string(ID_), position_ + numOffset_, options->GetNumSize());
    num_.setFillColor(sf::Color(options->GetNumRed(), options->GetNumGreen(), options->GetNumBlue(), options->GetNumAlpha()));

    if (options->GetOutlineSize() == 0)
    {
        float biggerNum = 0.0f;
        if (textureSize.x > textureSize.y) biggerNum = textureSize.x;
        else biggerNum = textureSize.y;
        outlineOffset_ = sf::Vector2f{(biggerNum / 300), (biggerNum / 300)};
    }
    else outlineOffset_ = sf::Vector2f{options->GetOutlineSize(), options->GetOutlineSize()};

    outline_.setSize(sf::Vector2f(imageWidth_ - 2 * outlineOffset_.x, imageHeight_ - 2 * outlineOffset_.y));
    outline_.setFillColor(sf::Color::Transparent);
    outline_.setOutlineThickness(outlineOffset_.x);
    outline_.setOutlineColor(sf::Color(options->GetOutlineRed(), options->GetOutlineGreen(), options->GetOutlineBlue(), options->GetOutlineAlpha()));
}

PictureBox::~PictureBox()
{}

void PictureBox::Update(float delta_time)
{
    velocity_ = Math::Lerp(velocity_, position_, 10.0f * delta_time);
    sprite_.setPosition(velocity_);
    num_.setPosition(velocity_ + numOffset_);
    outline_.setPosition(velocity_ + outlineOffset_);
}

void PictureBox::Draw(sf::RenderWindow& render_window) const
{
    //Set view (if using multiple views)
    render_window.setView(*scene_->FindView("Game"));

    //Draw sprite to render window
    render_window.draw(sprite_);
    if (numDisplay_) render_window.draw(num_);
    if (outlineDisplay_ && correctPosition_) render_window.draw(outline_);
}

void PictureBox::SetPosition(const sf::Vector2f& position, const int ID)
{
    position_ = position;
    ID_ = ID;
}

void PictureBox::SetNumDisplay(const bool numDisplay)
{
    numDisplay_ = numDisplay;
}

void PictureBox::SetOutlineDisplay(const bool outlineDisplay)
{
    outlineDisplay_ = outlineDisplay;
}

void PictureBox::IsCorrectPosition()
{
    if (ID_ == truePositionID_) SetIsCorrectPosition(true);
    else SetIsCorrectPosition(false);
}

void PictureBox::SetIsCorrectPosition(const bool correctPosition)
{
    correctPosition_ = correctPosition;
}

const bool PictureBox::GetIsCorrectPosition() const
{
    return correctPosition_;
}
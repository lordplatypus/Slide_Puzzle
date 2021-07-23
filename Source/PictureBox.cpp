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
    ID_ = ID; //stores the current position of the square
    truePositionID_ = ID; //stores the initial position of the square before it is randomized
    SetActive(false); 
    imageWidth_ = textureSize.x / options->GetColumnNum();
    imageHeight_ = textureSize.y / options->GetRowNum();

    //Sprite setup
    sprite_ = LP::SetSprite(image_texture_, imageWidth_, imageHeight_, ID_, position_);

    //hint number setup
    float numSize = options->GetNumSize();
    if (options->GetNumSize() == 0)
    {//attempt to automaticaly change the size of the numbers depending on the size of the image
        float biggerNum = 0.0f;
        if (textureSize.x > textureSize.y) biggerNum = textureSize.x;
        else biggerNum = textureSize.y;
        numSize = round(biggerNum / 100 * 1.6f);
    }
    num_ = LP::SetText(std::to_string(ID_), position_ + numOffset_, numSize);
    num_.setFillColor(sf::Color(options->GetNumRed(), options->GetNumGreen(), options->GetNumBlue(), options->GetNumAlpha()));
    numOffset_ = sf::Vector2f(numSize / 2, numSize / 2);

    //hint outline setup
    if (options->GetOutlineSize() == 0)
    {//attempt to automaticaly change the size of the outline depending on the size of the image
        float biggerNum = 0.0f;
        if (textureSize.x > textureSize.y) biggerNum = textureSize.x;
        else biggerNum = textureSize.y;
        outlineOffset_ = sf::Vector2f{(biggerNum / 300), (biggerNum / 300)};
    }
    else outlineOffset_ = sf::Vector2f{options->GetOutlineSize(), options->GetOutlineSize()}; //or just use the outline size that was set in the options
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

void PictureBox::Draw(Camera& camera) const
{
    //Set view (if using multiple views)
    camera.SetCurrentView("Game");

    //Draw sprite to render window
    camera.Draw(sprite_);
    if (numDisplay_) camera.Draw(num_);
    if (outlineDisplay_ && correctPosition_) camera.Draw(outline_);
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
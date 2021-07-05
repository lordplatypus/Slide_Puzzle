#include "PuzzleManager.h"
#include "IP.h"
#include <math.h>

PuzzleManager::PuzzleManager(Scene* scene, int rowNum, int columnNum, const sf::Vector2f& textureSize)
{
    scene_ = scene;
    SetActive(false);
    rowNum_ = rowNum;
    columnNum_ = columnNum;
    textureSize_ = textureSize;
    width_ = textureSize_.x / columnNum_;
    height_ = textureSize_.y / rowNum_;

    int i = 0;
    for (int y = 0; y < rowNum; y++)
    {
        for (int x = 0; x < columnNum_; x++)
        {
            if (y == rowNum_ - 1 && x == columnNum_ - 1) emptyBox_ = new EmptyBox(scene_, sf::Vector2f(width_ * x, height_ * y), i, rowNum_, columnNum_, textureSize_);
            else
            {
                pictureBox_.push_back(new PictureBox(scene_, sf::Vector2f(width_ * x, height_ * y), i, rowNum_, columnNum_, textureSize_));
            }
            i++;
        }
    }

    scene_->AddGameObject(emptyBox_);
    for (auto object : pictureBox_) scene_->AddGameObject(object);

    Randomizer();
}

PuzzleManager::~PuzzleManager()
{}

void PuzzleManager::Update(float delta_time)
{
    Input();
}

void PuzzleManager::Input()
{
    sf::Vector2f emptyPosition = emptyBox_->GetPosition();

    if (IP::PressLeft())
    {
        emptyPosition.x += width_;
        if (round(emptyPosition.x) > round(textureSize_.x - width_)) return;
    }
    else if (IP::PressRight())
    {
        emptyPosition.x -= width_;
        if (emptyPosition.x < 0.0f) return;
    }
    else if (IP::PressUp())
    {
        emptyPosition.y += height_;
        if (round(emptyPosition.y) > round(textureSize_.y - height_)) return;
    }
    else if (IP::PressDown())
    {
        emptyPosition.y -= height_;
        if (emptyPosition.y < 0.0f) return;
    }
    else if (IP::PressZ())
    {
        Randomizer();
    }
    else if (IP::PressSpace())
    {
        if (numDisplay_) numDisplay_ = false;
        else numDisplay_ = true;
        for (int i = 0; i < pictureBox_.size(); i++) pictureBox_[i]->SetNumDisplay(numDisplay_);
    }

    if (emptyPosition == emptyBox_->GetPosition()) return;

    int targetID = round(emptyPosition.x / (width_) + emptyPosition.y / (height_) * columnNum_);

    for (auto i : pictureBox_)
    {
        if (i->GetID() == targetID) i->SetPosition(emptyBox_->GetPosition(), emptyBox_->GetID());
    }
    emptyBox_->SetPosition(emptyPosition, targetID);
}

void PuzzleManager::Randomizer()
{
    // for (int i = 0; i < 100; i++)
    // {
    //     int a = rand() % (rowNum_ * columnNum_ - 1);
    //     int b = rand() % (rowNum_ * columnNum_ - 1);
    //     sf::Vector2f tempPosition = pictureBox_[a]->GetPosition();
    //     int tempID = pictureBox_[a]->GetID();
    //     pictureBox_[a]->SetPosition(pictureBox_[b]->GetPosition(), pictureBox_[b]->GetID());
    //     pictureBox_[b]->SetPosition(tempPosition, tempID);
    // }

    for (int i = 0; i < 100; i++)
    {
        sf::Vector2f emptyPosition = emptyBox_->GetPosition();

        bool cont = false;
        int a = rand() % 4;
        switch (a)
        {
            case 0:
            emptyPosition.x += width_;
            if (round(emptyPosition.x) > round(textureSize_.x - width_)) cont = true;
            break;

            case 1:
            emptyPosition.x -= width_;
            if (emptyPosition.x < 0.0f) cont = true;
            break;

            case 2:
            emptyPosition.y += height_;
            if (round(emptyPosition.y) > round(textureSize_.y - height_)) cont = true;
            break;

            case 3:
            emptyPosition.y -= height_;
            if (emptyPosition.y < 0.0f) cont = true;
            break;
        }
        if (cont) continue;

        int targetID = round(emptyPosition.x / (width_) + emptyPosition.y / (height_) * columnNum_);

        for (auto i : pictureBox_)
        {
            if (i->GetID() == targetID) i->SetPosition(emptyBox_->GetPosition(), emptyBox_->GetID());
        }
        emptyBox_->SetPosition(emptyPosition, targetID);
    }
}
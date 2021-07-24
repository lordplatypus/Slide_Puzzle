#include "PuzzleManager.h"
#include <math.h>

PuzzleManager::PuzzleManager(Scene* scene, Options* options, const sf::Vector2f& textureSize)
{
    scene_ = scene;
    SetActive(false);
    rowNum_ = options->GetRowNum();
    columnNum_ = options->GetColumnNum();
    textureSize_ = textureSize;
    width_ = textureSize_.x / columnNum_;
    height_ = textureSize_.y / rowNum_;

    //this is to radomize the empty box, 1 / 1 is the default bottom right corner
    int randomX = 1;
    int randomY = 1;
    if (options->GetRandomEmptyBoxPlacement())
    {
        randomX = rand() % columnNum_ + 1; //these can't be 0, hence the +1
        randomY = rand() % rowNum_ + 1; //otherwise the empty box wouldn't be created
    }

    int i = 0;
    for (int y = 0; y < rowNum_; y++)
    {
        for (int x = 0; x < columnNum_; x++)
        {
            if (y == rowNum_ - randomY && x == columnNum_ - randomX) emptyBox_ = new EmptyBox(scene_, sf::Vector2f(width_ * x, height_ * y), i, options, textureSize_);
            else pictureBox_.push_back(new PictureBox(scene_, sf::Vector2f(width_ * x, height_ * y), i, options, textureSize_));
            i++;
        }
    }

    winText_ = new WinText(scene_, options);

    scene_->AddGameObject(emptyBox_);
    for (auto object : pictureBox_) scene_->AddGameObject(object);
    scene_->AddGameObject(winText_);

    Randomizer();
}

PuzzleManager::~PuzzleManager()
{}

void PuzzleManager::Update(float delta_time)
{
    Input();
    IP_.Update();
}

void PuzzleManager::Input()
{
    sf::Vector2f emptyPosition = emptyBox_->GetPosition();

    if (IP_.GetButtonDown(sf::Keyboard::Left))
    {
        emptyPosition.x += width_;
        if (round(emptyPosition.x) > round(textureSize_.x - width_)) return;
    }
    else if (IP_.GetButtonDown(sf::Keyboard::Right))
    {
        emptyPosition.x -= width_;
        if (round(emptyPosition.x) < 0.0f) return;
    }
    else if (IP_.GetButtonDown(sf::Keyboard::Up))
    {
        emptyPosition.y += height_;
        if (round(emptyPosition.y) > round(textureSize_.y - height_)) return;
    }
    else if (IP_.GetButtonDown(sf::Keyboard::Down))
    {
        emptyPosition.y -= height_;
        if (round(emptyPosition.y) < 0.0f) return;
    }
    else if (IP_.GetButtonDown(sf::Keyboard::Z))
    {
        Randomizer();
    }
    else if (IP_.GetButtonDown(sf::Keyboard::Space))
    {
        if (numDisplay_) numDisplay_ = false;
        else numDisplay_ = true;
        for (int i = 0; i < pictureBox_.size(); i++) pictureBox_[i]->SetNumDisplay(numDisplay_);
    }
    else if (IP_.GetButtonDown(sf::Keyboard::LControl))
    {
        if (outlineDisplay_) outlineDisplay_ = false;
        else outlineDisplay_ = true;
        for (int i = 0; i < pictureBox_.size(); i++) pictureBox_[i]->SetOutlineDisplay(outlineDisplay_);
    }

    if (emptyPosition == emptyBox_->GetPosition()) return;

    int targetID = round(emptyPosition.x / (width_) + emptyPosition.y / (height_) * columnNum_);

    bool isWin = true;
    for (auto i : pictureBox_)
    {
        if (i->GetID() == targetID) 
        {
            i->SetPosition(emptyBox_->GetPosition(), emptyBox_->GetID());
            i->IsCorrectPosition();
        }

        if (!i->GetIsCorrectPosition()) isWin = false;
    }
    emptyBox_->SetPosition(emptyPosition, targetID);

    if (isWin) winText_->SetActive(true);
}

void PuzzleManager::Randomizer()
{
    for (int i = 0; i < 100 * rowNum_ * columnNum_; i++)
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
            if (round(emptyPosition.x) < 0.0f) cont = true;
            break;

            case 2:
            emptyPosition.y += height_;
            if (round(emptyPosition.y) > round(textureSize_.y - height_)) cont = true;
            break;

            case 3:
            emptyPosition.y -= height_;
            if (round(emptyPosition.y) < 0.0f) cont = true;
            break;
        }
        if (cont) continue;

        int targetID = round(emptyPosition.x / (width_) + emptyPosition.y / (height_) * columnNum_);

        for (auto i : pictureBox_)
        {
            if (i->GetID() == targetID) i->SetPosition(emptyBox_->GetPosition(), emptyBox_->GetID());
            i->IsCorrectPosition();
        }
        emptyBox_->SetPosition(emptyPosition, targetID);
    }
}
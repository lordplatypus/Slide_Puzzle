#include "SceneOptions.h"
#include "LP.h"
#include "ID.h"
#include "IP.h"

SceneOptions::SceneOptions(Game* game) : game_{game}
{}

SceneOptions::~SceneOptions()
{}

void SceneOptions::Init()
{
    game_->SetWin(false);

    buttons_.push_back(new Button(sf::Vector2f(0.0f, 0.0f), "Start"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 32.0f), "Image"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 64.0f), "Randomize missing piece location"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 96.0f), "Row"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 128.0f), "Column"));

    buttons_.push_back(new Button(sf::Vector2f(0.0f, 160.0f), "Hole Red"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 192.0f), "Hole Green"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 224.0f), "Hole Blue"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 256.0f), "Hole Alpha"));

    buttons_.push_back(new Button(sf::Vector2f(0.0f, 288.0f), "Number Size"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 320.0f), "Number Red"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 352.0f), "Number Green"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 384.0f), "Number Blue"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 416.0f), "Number Alpha"));

    buttons_.push_back(new Button(sf::Vector2f(0.0f, 448.0f), "Background Red"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 480.0f), "Background Green"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 512.0f), "Background Blue"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 544.0f), "Background Alpha"));
    for (int i = 1; i < buttons_.size(); i++) buttons_[i]->SetActive(false);

    counters_.push_back(new Counter(sf::Vector2f(576.0f, 96.0f), 4, 4, 100)); //row
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 128.0f), 4, 4, 100)); //column

    counters_.push_back(new Counter(sf::Vector2f(576.0f, 160.0f), 0, 0, 255)); //hole red
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 192.0f), 0, 0, 255)); //hole green
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 224.0f), 0, 0, 255)); //hole blue
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 256.0f), 255, 0, 255)); //hole Alpha

    counters_.push_back(new Counter(sf::Vector2f(576.0f, 288.0f), 32, 0, 255)); //num size
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 320.0f), 0, 0, 255)); //num red
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 352.0f), 0, 0, 255)); //num green
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 384.0f), 0, 0, 255)); //num blue
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 416.0f), 255, 0, 255)); //num alpha

    counters_.push_back(new Counter(sf::Vector2f(576.0f, 448.0f), 0, 0, 255)); //background red
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 480.0f), 0, 0, 255)); //background green
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 512.0f), 0, 0, 255)); //background blue
    counters_.push_back(new Counter(sf::Vector2f(576.0f, 544.0f), 255, 0, 255)); //background alpha
    for (auto i : counters_) i->SetActive(false);

    imagePath_ = new Button(sf::Vector2f(576.0f, 32.0f), game_->GetTI()->GetString());
    imagePath_->SetActive(false);

    randomEmptyBox_ = new Button(sf::Vector2f(1088.0f, 64.0f), "False");
    randomEmptyBox_->SetActive(false);

    FindView("Main")->setSize(sf::Vector2f(1920.0f, 1080.0f));
    FindView("Main")->setCenter(sf::Vector2f(1920.0f / 2, 1080.0f / 2));
}

void SceneOptions::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects
    gom_.Collision(); //check collision between gameobjects
    gom_.Remove(); //remove "dead" gameobjects

    if (state_ == Main) MainMenu();
    else if (state_ == Secondary) SecondaryMenu();
}

void SceneOptions::Draw(sf::RenderWindow& render_window) const
{
    gom_.Draw(render_window); //Regular draw - Draw GameObjects in order based on position in the list
    gom_.DelayedDraw(render_window); //draw things after Regular draw is finished, helpful for UI or things that should always be drawn last

    render_window.setView(*game_->GetCamera()->GetView("Main"));

    for (int i = 0; i < buttons_.size(); i++) buttons_[i]->Draw(render_window);
    for (int i = 0; i < counters_.size(); i++) counters_[i]->Draw(render_window);
    imagePath_->Draw(render_window);
    randomEmptyBox_->Draw(render_window);
}

void SceneOptions::AddGameObject(GameObject* gameObject)
{
    gom_.Add(gameObject); //add gameobject to the list of gameobjects
}

GameObject* SceneOptions::FindGameObject(const std::string& string, const bool byName, const bool byTag, const bool byID)
{//if byTag and byID are both left to default (false), search by name
    return gom_.Find(string, byName, byTag, byID); //returns a GameObject, returns a nullptr if the GameObject is not found
}

void SceneOptions::SortGameObjects()
{
    gom_.SortByLayers();
}

sf::View* SceneOptions::FindView(const std::string& viewName)
{
    return game_->GetCamera()->GetView(viewName);
}

void SceneOptions::OnWin()
{
    game_->SetWin(true);
}

void SceneOptions::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneOptions::End()
{
    gom_.Clear();

    for (auto i : buttons_) delete i;
    buttons_.clear();
    for (auto i : counters_) delete i;
    counters_.clear();
    delete imagePath_;
}

void SceneOptions::MainMenu()
{
    if (IP::PressUp() && selectedOption_ > 0)
    {
        selectedOption_--;
        buttons_[selectedOption_]->SetActive(true);
        buttons_[selectedOption_ + 1]->SetActive(false);
    }
    if (IP::PressDown() && selectedOption_ < buttons_.size() - 1)
    {
        selectedOption_++;
        buttons_[selectedOption_]->SetActive(true);
        buttons_[selectedOption_ - 1]->SetActive(false);
    }
    if (IP::PressEnter())
    {
        if (selectedOption_ == 0) ChangeScene("Game");
        else if (selectedOption_ == 1) 
        {
            //state_ = Image;
            state_ = Secondary;
            imagePath_->SetActive(true);
        }
        else if (selectedOption_ == 2) 
        {
            //state_ = Row;
            state_ = Secondary;
            randomEmptyBox_->SetActive(true);
        }
        else
        {
            state_ = Secondary;
            counters_[selectedOption_ - 3]->SetActive(true);
        }
    }
}

void SceneOptions::SecondaryMenu()
{
    if (IP::PressEnter())
    {
        SetOption();
    }

    if (selectedOption_ == 1) 
    {
        if (!game_->GetTI()->GetActive())
        {
            game_->GetTI()->SetActive(true);
            oldFilePath_ = game_->GetTI()->GetString();
        }
        if (IP::PressBackspace()) game_->GetTI()->Backspace();
        imagePath_->SetString(game_->GetTI()->GetString());
    }
    else if (selectedOption_ == 2) 
    {
        if (IP::PressUp() || IP::PressDown())
        {
            if (random_) 
            {
                randomEmptyBox_->SetString("False");
                random_ = false;
            }
            else
            {
                randomEmptyBox_->SetString("True");
                random_ = true;
            }
        }
    }
    else
    {
        if (IP::PressUp())
        {
            counters_[selectedOption_ - 3]->Increment();
        }
        if (IP::PressDown())
        {
            counters_[selectedOption_ - 3]->Decrement();
        }
    }
}

void SceneOptions::SetOption()
{
    switch (selectedOption_)
    {
        case 0:
        break;

        case 1:
        game_->GetTI()->SetActive(false);
        imagePath_->SetActive(false);
        if (!game_->AddImage("./" + game_->GetTI()->GetString())) game_->GetTI()->SetString(oldFilePath_);
        break;

        case 2:
        randomEmptyBox_->SetActive(false);
        game_->GetOptions()->SetRandomEmptyBoxPlacement(random_);
        break;

        case 3:
        game_->GetOptions()->SetRowNum(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 4:
        game_->GetOptions()->SetColumnNum(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 5:
        game_->GetOptions()->SetBoxRed(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 6:
        game_->GetOptions()->SetBoxGreen(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 7:
        game_->GetOptions()->SetBoxBlue(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 8:
        game_->GetOptions()->SetBoxAlpha(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 9:
        game_->GetOptions()->SetNumSize(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 10:
        game_->GetOptions()->SetNumRed(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 11:
        game_->GetOptions()->SetNumGreen(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 12:
        game_->GetOptions()->SetNumBlue(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 13:
        game_->GetOptions()->SetNumAlpha(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 14:
        game_->GetOptions()->SetBackgroundRed(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 15:
        game_->GetOptions()->SetBackgroundGreen(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 16:
        game_->GetOptions()->SetBackgroundBlue(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 17:
        game_->GetOptions()->SetBackgroundAlpha(counters_[selectedOption_ - 3]->GetNum());
        break;
    }
    if (selectedOption_ > 2) counters_[selectedOption_ - 3]->SetActive(false);
    state_ = Main;
}
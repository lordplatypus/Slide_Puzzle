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
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 64.0f), "Row"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 96.0f), "Column"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 128.0f), "Red"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 160.0f), "Green"));
    buttons_.push_back(new Button(sf::Vector2f(0.0f, 192.0f), "Blue"));
    for (int i = 1; i < buttons_.size(); i++) buttons_[i]->SetActive(false);

    counters_.push_back(new Counter(sf::Vector2f(256.0f, 64.0f), 4, 4, 100)); //row
    counters_.push_back(new Counter(sf::Vector2f(256.0f, 96.0f), 4, 4, 100)); //column
    counters_.push_back(new Counter(sf::Vector2f(256.0f, 128.0f), 255, 0, 255)); //red
    counters_.push_back(new Counter(sf::Vector2f(256.0f, 160.0f), 255, 0, 255)); //green
    counters_.push_back(new Counter(sf::Vector2f(256.0f, 192.0f), 255, 0, 255)); //blue
    for (auto i : counters_) i->SetActive(false);

    imagePath_ = new Button(sf::Vector2f(256.0f, 32.0f), game_->GetTI()->GetString());
    imagePath_->SetActive(false);
}

void SceneOptions::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects
    gom_.Collision(); //check collision between gameobjects
    gom_.Remove(); //remove "dead" gameobjects

    if (state_ == Main) MainMenu();
    else if (state_ == Image) ImageMenu();
    else if (state_ == Row) RowMenu();
    else if (state_ == Column) ColumnMenu();
    else if (state_ == Red) RedMenu();
    else if (state_ == Green) GreenMenu();
    else if (state_ == Blue) BlueMenu();
}

void SceneOptions::Draw(sf::RenderWindow& render_window) const
{
    gom_.Draw(render_window); //Regular draw - Draw GameObjects in order based on position in the list
    gom_.DelayedDraw(render_window); //draw things after Regular draw is finished, helpful for UI or things that should always be drawn last

    // for (auto button : buttons_) button->Draw(render_window);
    // for (auto counter : counters_) counter->Draw(render_window);
    for (int i = 0; i < buttons_.size(); i++) buttons_[i]->Draw(render_window);
    for (int i = 0; i < counters_.size(); i++) counters_[i]->Draw(render_window);
    imagePath_->Draw(render_window);
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
    if (IP::PressZ())
    {
        if (selectedOption_ == 0) ChangeScene("Game");
        if (selectedOption_ == 1) 
        {
            state_ = Image;
            imagePath_->SetActive(true);
        }
        if (selectedOption_ == 2) 
        {
            state_ = Row;
            counters_[0]->SetActive(true);
        }
        if (selectedOption_ == 3)
        {
            state_ = Column;
            counters_[1]->SetActive(true);
        }
        if (selectedOption_ == 4)
        {
            state_ = Red;
            counters_[2]->SetActive(true);
        }
        if (selectedOption_ == 5)
        {
            state_ = Green;
            counters_[3]->SetActive(true);
        }
        if (selectedOption_ == 6)
        {
            state_ = Blue;
            counters_[4]->SetActive(true);
        }
    }
}

void SceneOptions::ImageMenu()
{
    if (IP::PressRight())
    {
       
    }
    if (IP::PressLeft())
    {
        
    }
    if (IP::PressZ())
    {
        game_->GetTI()->SetActive(true);
    }

    if (game_->GetTI()->GetActive())
    {
        if (IP::PressEnter())
        {
            game_->GetTI()->SetActive(false);
            imagePath_->SetActive(false);
            if (!game_->AddImage(game_->GetTI()->GetString())) game_->GetTI()->SetString("./image.png");
            state_ = Main;
        }
        if (IP::PressBackspace()) game_->GetTI()->Backspace();
        imagePath_->SetString(game_->GetTI()->GetString());
    }
}

void SceneOptions::RowMenu()
{
    if (IP::PressUp())
    {
        counters_[0]->Increment();
    }
    if (IP::PressDown())
    {
        counters_[0]->Decrement();
    }
    if (IP::PressZ())
    {
        game_->GetOptions()->SetRowNum(counters_[0]->GetNum());
        counters_[0]->SetActive(false);
        state_ = Main;
    }
}

void SceneOptions::ColumnMenu()
{
    if (IP::PressUp())
    {
        counters_[1]->Increment();
    }
    if (IP::PressDown())
    {
        counters_[1]->Decrement();
    }
    if (IP::PressZ())
    {
        game_->GetOptions()->SetColumnNum(counters_[1]->GetNum());
        counters_[1]->SetActive(false);
        state_ = Main;
    }
}

void SceneOptions::RedMenu()
{
    if (IP::PressUp())
    {
        counters_[2]->Increment();
    }
    if (IP::PressDown())
    {
        counters_[2]->Decrement();
    }
    if (IP::PressZ())
    {
        game_->GetOptions()->SetRedNum(counters_[2]->GetNum());
        counters_[2]->SetActive(false);
        state_ = Main;
    }
}

void SceneOptions::GreenMenu()
{
    if (IP::PressUp())
    {
        counters_[3]->Increment();
    }
    if (IP::PressDown())
    {
        counters_[3]->Decrement();
    }
    if (IP::PressZ())
    {
        game_->GetOptions()->SetGreenNum(counters_[3]->GetNum());
        counters_[3]->SetActive(false);
        state_ = Main;
    }
}

void SceneOptions::BlueMenu()
{
    if (IP::PressUp())
    {
        counters_[4]->Increment();
    }
    if (IP::PressDown())
    {
        counters_[4]->Decrement();
    }
    if (IP::PressZ())
    {
        game_->GetOptions()->SetBlueNum(counters_[4]->GetNum());
        counters_[4]->SetActive(false);
        state_ = Main;
    }
}
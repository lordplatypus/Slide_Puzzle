#include "SceneOptions.h"
#include "LP.h"
#include "ID.h"

SceneOptions::SceneOptions(Game* game) : game_{game}
{}

SceneOptions::~SceneOptions()
{}

void SceneOptions::Init()
{
    game_->SetWin(false);

    //Setup the buttons
    buttons_.push_back(new Button("Start"));
    buttons_.push_back(new Button("Image"));
    buttons_.push_back(new Button("Rand Empty"));
    buttons_.push_back(new Button("Row"));
    buttons_.push_back(new Button("Column"));

    buttons_.push_back(new Button("Empty Red"));
    buttons_.push_back(new Button("Empty Green"));
    buttons_.push_back(new Button("Empty Blue"));
    buttons_.push_back(new Button("Empty Alpha"));

    buttons_.push_back(new Button("Number Size"));
    buttons_.push_back(new Button("Number Red"));
    buttons_.push_back(new Button("Number Green"));
    buttons_.push_back(new Button("Number Blue"));
    buttons_.push_back(new Button("Number Alpha"));

    buttons_.push_back(new Button("Background Red"));
    buttons_.push_back(new Button("Background Green"));
    buttons_.push_back(new Button("Background Blue"));
    buttons_.push_back(new Button("Background Alpha"));

    buttons_.push_back(new Button("Outline Size"));
    buttons_.push_back(new Button("Outline Red"));
    buttons_.push_back(new Button("Outline Green"));
    buttons_.push_back(new Button("Outline Blue"));
    buttons_.push_back(new Button("Outline Alpha"));
    for (int i = 0; i < buttons_.size(); i++) 
    {
        buttons_[i]->SetPosition(sf::Vector2f(16.0f, 36.0f * i + 16.0f));
        if (i > 0) buttons_[i]->SetActive(false); //Grey out all buttons
    }

    //Setup the counters
    counters_.push_back(new Counter(game_->GetOptions()->GetRowNum(), 4, 100)); //row
    counters_.push_back(new Counter(game_->GetOptions()->GetColumnNum(), 4, 100)); //column

    counters_.push_back(new Counter(game_->GetOptions()->GetBoxRed(), 0, 255)); //hole red
    counters_.push_back(new Counter(game_->GetOptions()->GetBoxGreen(), 0, 255)); //hole green
    counters_.push_back(new Counter(game_->GetOptions()->GetBoxBlue(), 0, 255)); //hole blue
    counters_.push_back(new Counter(game_->GetOptions()->GetBoxAlpha(), 0, 255)); //hole Alpha

    counters_.push_back(new Counter(game_->GetOptions()->GetNumSize(), 0, 255)); //num size
    counters_.push_back(new Counter(game_->GetOptions()->GetNumRed(), 0, 255)); //num red
    counters_.push_back(new Counter(game_->GetOptions()->GetNumGreen(), 0, 255)); //num green
    counters_.push_back(new Counter(game_->GetOptions()->GetNumBlue(), 0, 255)); //num blue
    counters_.push_back(new Counter(game_->GetOptions()->GetNumAlpha(), 0, 255)); //num alpha

    counters_.push_back(new Counter(game_->GetOptions()->GetBackgroundRed(), 0, 255)); //background red
    counters_.push_back(new Counter(game_->GetOptions()->GetBackgroundGreen(), 0, 255)); //background green
    counters_.push_back(new Counter(game_->GetOptions()->GetBackgroundBlue(), 0, 255)); //background blue
    counters_.push_back(new Counter(game_->GetOptions()->GetBackgroundAlpha(), 0, 255)); //background alpha

    counters_.push_back(new Counter(game_->GetOptions()->GetOutlineSize(), 0, 255)); //outline size
    counters_.push_back(new Counter(game_->GetOptions()->GetOutlineRed(), 0, 255)); //outline red
    counters_.push_back(new Counter(game_->GetOptions()->GetOutlineGreen(), 0, 255)); //outline green
    counters_.push_back(new Counter(game_->GetOptions()->GetOutlineBlue(), 0, 255)); //outline blue
    counters_.push_back(new Counter(game_->GetOptions()->GetOutlineAlpha(), 0, 255)); //outline alpha
    for (int i = 0; i < counters_.size(); i++) 
    {
        counters_[i]->SetPosition(sf::Vector2f(576.0f, 36.0f * (i + 3) + 16.0f));
        counters_[i]->SetActive(false); //Grey out all counters
    }

    //setup image path button
    imagePath_ = new Button(game_->GetTI()->GetString(), sf::Vector2f(576.0f, 48.0f));
    imagePath_->SetActive(false);

    //setup rand empty button
    if (game_->GetOptions()->GetRandomEmptyBoxPlacement()) randomEmptyBox_ = new Button("True", sf::Vector2f(576.0f, 84.0f));
    else randomEmptyBox_ = new Button("False", sf::Vector2f(576.0f, 84.0f));
    randomEmptyBox_->SetActive(false);

    //Setup instruction text
    instructionsText_.push_back("Controls:\n>Use the arrow keys to\nnavigate the menu and\nto move the empty square\n>Press Enter to edit\nand confirm options\n>Hold Left Shift for\nreference Picture\n>Press Left Control for\noutline\n>Press Space for\nID numbers\n>Press Z to re-randomize\n>Press X to return to\nthis menu\n>Press Esc to close\nthe game");
    instructionsText_.push_back("Instructions:\n>Backspace to remove\ncharacters\n>Enter to confirm\n>Have to include\nfile type\n>Only png will work");
    instructionsText_.push_back("Instructions:\n>Randomizes the\nremoved square\n>Default is the\nbottom right square");
    instructionsText_.push_back("Instructions:\n>Number of Rows\n>Min = 4\n>Max = max int");
    instructionsText_.push_back("Instructions:\n>Number of Columns\n>Min = 4\n>Max = max int");
    instructionsText_.push_back("Instructions:\n>Empty square color - Red\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Empty square color - Green\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Empty square color - Blue\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Empty square color - Alpha\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>ID num size\n>Min = 0\n>Max = max int\n>0 = auto");
    instructionsText_.push_back("Instructions:\n>ID num color - Red\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>ID num color - Green\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>ID num color - Blue\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>ID num color - Alpha\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Background color - Red\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Background color - Green\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Background color - Blue\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Background color - Alpha\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Outline size\n>Min = 0\n>Max = max int\n>0 = auto");
    instructionsText_.push_back("Instructions:\n>Outline color - Red\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Outline color - Green\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Outline color - Blue\n>Min = 0\n>Max = 255");
    instructionsText_.push_back("Instructions:\n>Outline color - Alpha\n>Min = 0\n>Max = 255");
    instructions_ = LP::SetText(instructionsText_[0], sf::Vector2f(960.0f, 16.0f));

    //Setup color example
    exampleColorBox_.setSize(sf::Vector2f(100.0f, 100.0f));
    exampleColorBox_.setPosition(sf::Vector2f(1390.0f, 490.0f));
}

void SceneOptions::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects

    if (state_ == Main) MainMenu();
    else if (state_ == Secondary) SecondaryMenu();

    IP_.Update();
}

void SceneOptions::Draw(Camera& camera) const
{
    //gom_.Draw(camera); //Regular draw - Draw GameObjects in order based on position in the list

    camera.SetCurrentView("Main");

    //Drawing the various text, buttons, counters, and example color box things
    for (int i = 0; i < buttons_.size(); i++) buttons_[i]->Draw(camera);
    for (int i = 0; i < counters_.size(); i++) counters_[i]->Draw(camera);
    imagePath_->Draw(camera);
    randomEmptyBox_->Draw(camera);
    camera.Draw(instructions_);
    if (state_ == Secondary && selectedOption_ > 4 && selectedOption_ != 9 && selectedOption_ != 18) camera.Draw(exampleColorBox_);
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

void SceneOptions::OnWin()
{
    game_->SetWin(true);
}

void SceneOptions::ChangeScene(const std::string& sceneName)
{
    game_->ChangeScene(sceneName);
}

void SceneOptions::End()
{//Delete all buttons and counters so that they don't double up when returning to this scene
    gom_.Clear();

    for (auto i : buttons_) delete i;
    buttons_.clear();
    for (auto i : counters_) delete i;
    counters_.clear();
    delete imagePath_;
    delete randomEmptyBox_;
    instructionsText_.clear();
}

void SceneOptions::MainMenu()
{
    if (IP_.GetButtonDown(sf::Keyboard::Up))
    {
        selectedOption_--;
        if (selectedOption_ < 0) 
        {
            selectedOption_ = buttons_.size() - 1;
            buttons_[0]->SetActive(false);
        }
        else buttons_[selectedOption_ + 1]->SetActive(false);
        buttons_[selectedOption_]->SetActive(true);
    }
    if (IP_.GetButtonDown(sf::Keyboard::Down))
    {
        selectedOption_++;
        if (selectedOption_ > buttons_.size() - 1) 
        {
            selectedOption_ = 0;
            buttons_[buttons_.size() - 1]->SetActive(false);
        }
        else buttons_[selectedOption_ - 1]->SetActive(false);
        buttons_[selectedOption_]->SetActive(true); 
    }
    if (IP_.GetButtonDown(sf::Keyboard::Enter))
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
        instructions_.setString(instructionsText_[selectedOption_]);
    }
}

void SceneOptions::SecondaryMenu()
{
    if (IP_.GetButtonDown(sf::Keyboard::Enter))
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
        if (IP_.GetButtonDown(sf::Keyboard::Backspace)) game_->GetTI()->Backspace();
        imagePath_->SetString(game_->GetTI()->GetString());
    }
    else if (selectedOption_ == 2) 
    {
        if (IP_.GetButtonDown(sf::Keyboard::Up) || IP_.GetButtonDown(sf::Keyboard::Down))
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
        if (IP_.GetButtonDown(sf::Keyboard::Up))
        {
            counters_[selectedOption_ - 3]->Increment();
        }
        if (IP_.GetButtonDown(sf::Keyboard::Down))
        {
            counters_[selectedOption_ - 3]->Decrement();
        }
        if (selectedOption_ != 9 && selectedOption_ != 18) SetColorExample();
    }
}

void SceneOptions::SetColorExample()
{
    if (selectedOption_ < 9) exampleColorBox_.setFillColor(sf::Color(counters_[2]->GetNum(), counters_[3]->GetNum(), counters_[4]->GetNum(), counters_[5]->GetNum()));
    else if (selectedOption_ < 14) exampleColorBox_.setFillColor(sf::Color(counters_[7]->GetNum(), counters_[8]->GetNum(), counters_[9]->GetNum(), counters_[10]->GetNum()));
    else if (selectedOption_ < 18) exampleColorBox_.setFillColor(sf::Color(counters_[11]->GetNum(), counters_[12]->GetNum(), counters_[13]->GetNum(), counters_[14]->GetNum()));
    else exampleColorBox_.setFillColor(sf::Color(counters_[16]->GetNum(), counters_[17]->GetNum(), counters_[18]->GetNum(), counters_[19]->GetNum()));
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

        case 18:
        game_->GetOptions()->SetOutlineSize(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 19:
        game_->GetOptions()->SetOutlineRed(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 20:
        game_->GetOptions()->SetOutlineGreen(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 21:
        game_->GetOptions()->SetOutlineBlue(counters_[selectedOption_ - 3]->GetNum());
        break;

        case 22:
        game_->GetOptions()->SetOutlineAlpha(counters_[selectedOption_ - 3]->GetNum());
        break;
    }
    if (selectedOption_ > 2) counters_[selectedOption_ - 3]->SetActive(false);
    instructions_.setString(instructionsText_[0]);
    state_ = Main;
}
#include "SceneOptions.h"
#include "LP.h"
#include "ID.h"

SceneOptions::SceneOptions(Game* game, EL& EL) : game_{game}, EL_{&EL}
{}

SceneOptions::~SceneOptions()
{}

void SceneOptions::Init()
{
    //Find Images in image directory
    SetImages();

    //Setup the buttons
    buttons_.push_back(new Button(game_->GetLP(), "Start"));
    buttons_.push_back(new Button(game_->GetLP(), "Image"));
    buttons_.push_back(new Button(game_->GetLP(), "Rand Empty"));
    buttons_.push_back(new Button(game_->GetLP(), "Row"));
    buttons_.push_back(new Button(game_->GetLP(), "Column"));

    buttons_.push_back(new Button(game_->GetLP(), "Empty Red"));
    buttons_.push_back(new Button(game_->GetLP(), "Empty Green"));
    buttons_.push_back(new Button(game_->GetLP(), "Empty Blue"));
    buttons_.push_back(new Button(game_->GetLP(), "Empty Alpha"));

    buttons_.push_back(new Button(game_->GetLP(), "Number Size"));
    buttons_.push_back(new Button(game_->GetLP(), "Number Red"));
    buttons_.push_back(new Button(game_->GetLP(), "Number Green"));
    buttons_.push_back(new Button(game_->GetLP(), "Number Blue"));
    buttons_.push_back(new Button(game_->GetLP(), "Number Alpha"));

    buttons_.push_back(new Button(game_->GetLP(), "Background Red"));
    buttons_.push_back(new Button(game_->GetLP(), "Background Green"));
    buttons_.push_back(new Button(game_->GetLP(), "Background Blue"));
    buttons_.push_back(new Button(game_->GetLP(), "Background Alpha"));

    buttons_.push_back(new Button(game_->GetLP(), "Outline Size"));
    buttons_.push_back(new Button(game_->GetLP(), "Outline Red"));
    buttons_.push_back(new Button(game_->GetLP(), "Outline Green"));
    buttons_.push_back(new Button(game_->GetLP(), "Outline Blue"));
    buttons_.push_back(new Button(game_->GetLP(), "Outline Alpha"));

    buttons_.push_back(new Button(game_->GetLP(), "Image Directory"));
    buttons_.push_back(new Button(game_->GetLP(), "Save Settings"));
    for (int i = 0; i < buttons_.size(); i++) 
    {
        buttons_[i]->SetPosition(sf::Vector2f(16.0f, 36.0f * i + 16.0f));
        if (i > 0) buttons_[i]->SetActive(false); //Grey out all buttons
    }

    //Setup the counters
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Row"), 4, 100)); //row
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Column"), 4, 100)); //column

    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Empty Red"), 0, 255)); //Empty box red
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Empty Green"), 0, 255)); //Empty box green
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Empty Blue"), 0, 255)); //Empty box blue
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Empty Alpha"), 0, 255)); //Empty box Alpha

    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Number Size"), 0, 255)); //num size
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Number Red"), 0, 255)); //num red
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Number Green"), 0, 255)); //num green
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Number Blue"), 0, 255)); //num blue
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Number Alpha"), 0, 255)); //num alpha

    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Background Red"), 0, 255)); //background red
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Background Green"), 0, 255)); //background green
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Background Blue"), 0, 255)); //background blue
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Background Alpha"), 0, 255)); //background alpha

    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Outline Size"), 0, 255)); //outline size
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Outline Red"), 0, 255)); //outline red
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Outline Green"), 0, 255)); //outline green
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Outline Blue"), 0, 255)); //outline blue
    counters_.push_back(new Counter(game_->GetLP(), game_->GetOptions()->GetOption("Outline Alpha"), 0, 255)); //outline alpha
    for (int i = 0; i < counters_.size(); i++) 
    {
        counters_[i]->SetPosition(sf::Vector2f(576.0f, 36.0f * (i + 3) + 16.0f));
        counters_[i]->SetActive(false); //Grey out all counters
    }

    //setup image path button
    // imagePath_ = new Button(game_->GetLP(), oldFilePath_, sf::Vector2f(576.0f, 48.0f));
    // imagePath_->SetActive(false);
    //setup image directory path button
    oldImagePath_ = game_->GetOptions()->GetImageDirectory();
    EL_->SetTextEntered(oldImagePath_);
    imagePath_ = new Button(game_->GetLP(), oldImagePath_, sf::Vector2f(576.0f, 36.0f * (counters_.size() + 3) + 16.0f));
    imagePath_->SetActive(false);

    //setup rand empty button
    if (game_->GetOptions()->GetOption("Rand Empty") > 0) randomEmptyBox_ = new Button(game_->GetLP(), "True", sf::Vector2f(576.0f, 84.0f));
    else randomEmptyBox_ = new Button(game_->GetLP(), "False", sf::Vector2f(576.0f, 84.0f));
    randomEmptyBox_->SetActive(false);

    //Setup instruction text
    instructionsText_.push_back("Controls:\n>Use the arrow keys to\nnavigate the menu and\nto move the empty square\n>Press Enter to edit\nand confirm options\n>'Save Settings' to\nsave to the config file\n>Hold Left Shift for\nreference Picture\n>Press Left Control for\noutline\n>Press Space for\nID numbers\n>Press Z to re-randomize\n>Press X to return to\nthis menu\n>Press Esc to close\nthe game");
    instructionsText_.push_back("Instructions:\n>Up and Down to\n>cycle through\n>available images\n>Enter to confirm");
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
    instructionsText_.push_back("Instructions:\n>Backspace to remove\ncharacters\n>Enter to confirm\n>Remember to end\nwith a '/'");
    instructions_ = game_->GetLP().SetText(main_font, instructionsText_[0], sf::Vector2f(960.0f, 16.0f));

    //Setup color example
    exampleColorBox_.setSize(sf::Vector2f(100.0f, 100.0f));
    exampleColorBox_.setPosition(sf::Vector2f(1390.0f, 490.0f));
}

void SceneOptions::Update(float delta_time)
{
    gom_.Update(delta_time); //update all gameobjects

    if (state_ == Main) MainMenu();
    else if (state_ == Secondary) SecondaryMenu();

    IP_.Update(delta_time);
}

void SceneOptions::Draw(Camera& camera) const
{
    camera.SetCurrentView("Main");

    //Drawing the various text, buttons, counters, and example color box things
    for (int i = 0; i < buttons_.size(); i++) buttons_[i]->Draw(camera);
    for (int i = 0; i < counters_.size(); i++) counters_[i]->Draw(camera);
    imagePath_->Draw(camera);
    randomEmptyBox_->Draw(camera);
    imageText_[imageSelect_]->Draw(camera);
    camera.Draw(instructions_);
    if (state_ == Secondary && selectedOption_ > 4 &&  selectedOption_ < 23 && selectedOption_ != 9 && selectedOption_ != 18) camera.Draw(exampleColorBox_);
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
    for (auto i : imageText_) delete i;
    imageText_.clear();
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
            state_ = Secondary;
            for (auto text :imageText_) text->SetActive(true);
        }
        else if (selectedOption_ == 2) 
        {
            state_ = Secondary;
            randomEmptyBox_->SetActive(true);
        }
        else if (selectedOption_ == buttons_.size() - 2)
        {
            state_ = Secondary;
            imagePath_->SetActive(true);
        }
        else if (selectedOption_ == buttons_.size() - 1)
        {
            game_->GetOptions()->SaveConfig();
        }
        else
        {
            state_ = Secondary;
            counters_[selectedOption_ - 3]->SetActive(true);
        }
        if (selectedOption_ < instructionsText_.size()) instructions_.setString(instructionsText_[selectedOption_]);
    }
}

void SceneOptions::SecondaryMenu()
{
    if (IP_.GetButtonDown(sf::Keyboard::Enter))
    {//Press Enter to confirm the option
        SetOption();
    }
    else if (selectedOption_ == 1) 
    {
        if (IP_.GetButtonDown(sf::Keyboard::Up))
        {
            imageSelect_--;
            if (imageSelect_ < 0) 
            {
                imageSelect_ = imageText_.size() - 1;
            }
        }
        if (IP_.GetButtonDown(sf::Keyboard::Down))
        {
            imageSelect_++;
            if (imageSelect_ > imageText_.size() - 1) 
            {
                imageSelect_ = 0;
            }
        }
    }
    else if (selectedOption_ == 2) 
    {//True or False
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
    else if (selectedOption_ == buttons_.size() - 2)
    {//Type in a file path
        if (!EL_->GetTextEnteredActive())
        {//Activate once 
            EL_->SetTextEnteredActive(true); //Allow for typing
            oldImagePath_ = EL_->GetTextEntered(); //Save the old filepath in case the new path is wrong
        }
        imagePath_->SetString(EL_->GetTextEntered()); //Display what is being typed
    }
    else
    {//Increases or decreases the counter for the many options that use counters
        if (IP_.GetButtonDown(sf::Keyboard::Up))
        {
            counters_[selectedOption_ - 3]->Increment();
        }
        if (IP_.GetButtonDown(sf::Keyboard::Down))
        {
            counters_[selectedOption_ - 3]->Decrement();
        }
        if (IP_.GetButtonDown(sf::Keyboard::Right))
        {
            counters_[selectedOption_ - 3]->Increment(10);
        }
        if (IP_.GetButtonDown(sf::Keyboard::Left))
        {
            counters_[selectedOption_ - 3]->Decrement(10);
        }
        if (selectedOption_ != 9 && selectedOption_ != 18) SetColorExample(); //change the color of the sample box
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
        // EL_->SetTextEnteredActive(false); //deactive typing
        // imagePath_->SetActive(false); //grey out button
        // if (!game_->GetLP().SetTexture(image_texture_, "./" +  EL_->GetTextEntered()))  EL_->SetTextEntered(oldFilePath_); //set new filepath or revert back to old filepath
        for (auto text :imageText_) text->SetActive(false);
        game_->GetLP().SetTexture(image_texture_, game_->GetOptions()->GetImageDirectory() + imageText_[imageSelect_]->GetString());
        break;

        case 2:
        randomEmptyBox_->SetActive(false);
        //game_->GetOptions()->SetRandomEmptyBoxPlacement(random_);
        game_->GetOptions()->SetOption("Rand Empty", random_);
        break;

        case 3:
        //game_->GetOptions()->SetRowNum(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Row", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 4:
        //game_->GetOptions()->SetColumnNum(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Column", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 5:
        //game_->GetOptions()->SetBoxRed(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Empty Red", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 6:
        //game_->GetOptions()->SetBoxGreen(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Empty Green", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 7:
        //game_->GetOptions()->SetBoxBlue(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Empty Blue", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 8:
        //game_->GetOptions()->SetBoxAlpha(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Empty Alpha", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 9:
        //game_->GetOptions()->SetNumSize(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Number Size", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 10:
        //game_->GetOptions()->SetNumRed(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Number Red", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 11:
        //game_->GetOptions()->SetNumGreen(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Number Green", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 12:
        //game_->GetOptions()->SetNumBlue(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Number Blue", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 13:
        //game_->GetOptions()->SetNumAlpha(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Number Alpha", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 14:
        //game_->GetOptions()->SetBackgroundRed(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Background Red", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 15:
        //game_->GetOptions()->SetBackgroundGreen(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Background Green", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 16:
        //game_->GetOptions()->SetBackgroundBlue(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Background Blue", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 17:
        //game_->GetOptions()->SetBackgroundAlpha(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Background Alpha", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 18:
        //game_->GetOptions()->SetOutlineSize(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Outline Size", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 19:
        //game_->GetOptions()->SetOutlineRed(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Outline Red", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 20:
        //game_->GetOptions()->SetOutlineGreen(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Outline Green", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 21:
        //game_->GetOptions()->SetOutlineBlue(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Outline Blue", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 22:
        //game_->GetOptions()->SetOutlineAlpha(counters_[selectedOption_ - 3]->GetNum());
        game_->GetOptions()->SetOption("Outline Alpha", counters_[selectedOption_ - 3]->GetNum());
        break;

        case 23:
        EL_->SetTextEnteredActive(false); //deactive typing
        imagePath_->SetActive(false); //grey out button
        if (!FM_.CheckDirectory(EL_->GetTextEntered())) 
        {//If the new image directory path fails
            EL_->SetTextEntered(oldImagePath_); //revert to old file path
            imagePath_->SetString(oldImagePath_); //display old file path
            game_->GetOptions()->SetImageDirectory(oldImagePath_); //options are also reverted
        }
        else game_->GetOptions()->SetImageDirectory(EL_->GetTextEntered()); //options is updated
        //Find Images in image directory
        SetImages();
        break;

        default:
        break;
    }
    if (selectedOption_ > 2 && selectedOption_ < 23) counters_[selectedOption_ - 3]->SetActive(false);
    instructions_.setString(instructionsText_[0]); //go back to default instructions
    state_ = Main;
}

void SceneOptions::SetImages()
{
    //Find Images in image directory
    std::vector<std::string> imageNames;
    imageNames = FM_.SearchDirectory(game_->GetOptions()->GetImageDirectory(), ".png");
    for (auto i : imageText_) delete i;
    imageText_.clear();

    if (imageNames.size() == 0) imageText_.push_back(new Button(game_->GetLP(), "No Images", sf::Vector2f(576.0f, 36.0f + 16.0f)));
    else 
    {
        for (int i = 0; i < imageNames.size(); i++)
        {
            imageText_.push_back(new Button(game_->GetLP(), imageNames[i], sf::Vector2f(576.0f, 36.0f + 16.0f)));
            imageText_[i]->SetActive(false);
        }
        game_->GetLP().SetTexture(image_texture_, game_->GetOptions()->GetImageDirectory() + imageNames[imageSelect_]);
    }
}
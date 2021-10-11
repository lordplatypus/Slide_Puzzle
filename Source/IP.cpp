#include "IP.h"

IP::IP()
{}

IP::~IP()
{}

void IP::Update(float delta_time)
{
    bool keyPressed = false;
    for (auto key : pressedKeys_)
    {
        if (!sf::Keyboard::isKeyPressed(key.first)) pressedKeys_[key.first] = false;
        else keyPressed = true;
    }
    if (rapidFlag_)
    {
        if (keyPressed)
        {
            if ((rapidTimer_ += delta_time) >= holdTimeForRapid_) rapidActive_ = true;
        }
        else
        {
            rapidActive_ = false;
            rapidTimer_ = 0.0f;
        }
    }


    for (auto button : pressedButtons_)
    {
        if (!sf::Mouse::isButtonPressed(button.first)) pressedButtons_[button.first] = false;
    }
}

void IP::SetRapidFlag(const bool rapidFlag)
{
    rapidFlag_ = rapidFlag;
}

bool IP::GetButton(sf::Keyboard::Key buttonID)
{
    return sf::Keyboard::isKeyPressed(buttonID);
}

bool IP::GetButton(sf::Mouse::Button buttonID)
{
    return sf::Mouse::isButtonPressed(buttonID);
}

bool IP::GetButtonDown(sf::Keyboard::Key buttonID)
{
    if (sf::Keyboard::isKeyPressed(buttonID) && rapidActive_) return true;
    if (!sf::Keyboard::isKeyPressed(buttonID) || pressedKeys_[buttonID]) return false;
    pressedKeys_[buttonID] = true;
    return true;
}

bool IP::GetButtonDown(sf::Mouse::Button buttonID)
{
    if (!sf::Mouse::isButtonPressed(buttonID) || pressedButtons_[buttonID]) return false;
    pressedButtons_[buttonID] = true;
    return true;
}

//Mouse

sf::Vector2f IP::GetMousePosition(Camera& camera)
{
    //Get mouse position (pixel coordinates)
    sf::Vector2i mousePosition = sf::Mouse::getPosition(camera.GetRenderWindow());
    //return mouse position after converting it to world coordinates
    return camera.GetRenderWindow().mapPixelToCoords(mousePosition);
}

void IP::SetMousePosition(sf::Vector2i position)
{
    sf::Mouse::setPosition(position);
}
#include "IP.h"

Camera* camera_;

IP::IP()
{}

IP::~IP()
{}

void IP::SetCamera(Camera* camera)
{
    camera_ = camera;
}


bool IP::GetButton(sf::Keyboard::Key buttonID)
{
    return sf::Keyboard::isKeyPressed(buttonID);
}


//One Time Activation

bool pressedLeft_{true};
bool IP::PressLeft()
{
    if (!pressedLeft_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pressedLeft_ = true;
        return true;
    }

    return false;
}

bool pressedRight_{true};
bool IP::PressRight()
{
    if (!pressedRight_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pressedRight_ = true;
        return true;
    }

    return false;
}

bool pressedUp_{true};
bool IP::PressUp()
{
    if (!pressedUp_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        pressedUp_ = true;
        return true;
    }

    return false;
}

bool pressedDown_{true};
bool IP::PressDown()
{
    if (!pressedDown_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        pressedDown_ = true;
        return true;
    }

    return false;
}

bool pressedSpace_{true};
bool IP::PressSpace()
{
    if (!pressedSpace_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        pressedSpace_ = true;
        return true;
    }

    return false;
}

bool pressedW_{true};
bool IP::PressW()
{
    if (!pressedW_ && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        pressedW_ = true;
        return true;
    }

    return false;
}

bool pressedA_{true};
bool IP::PressA()
{
    if (!pressedA_ && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        pressedA_ = true;
        return true;
    }

    return false;
}

bool pressedS_{true};
bool IP::PressS()
{
    if (!pressedS_ && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        pressedS_ = true;
        return true;
    }

    return false;
}

bool pressedD_{true};
bool IP::PressD()
{
    if (!pressedD_ && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        pressedD_ = true;
        return true;
    }

    return false;
}

bool pressedZ_{true};
bool IP::PressZ()
{
    if (!pressedZ_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        pressedZ_ = true;
        return true;
    }

    return false;
}

bool pressedX_{true};
bool IP::PressX()
{
    if (!pressedX_ && sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        pressedX_ = true;
        return true;
    }

    return false;
}


//Mouse

bool IP::GetMouseClick(sf::Mouse::Button buttonID)
{
    return sf::Mouse::isButtonPressed(buttonID);
}

bool leftClicked_{true};
bool IP::LeftClick()
{
    if (!leftClicked_ && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        leftClicked_ = true;
        return true;
    }

    return false;
}

bool rightClicked_{true};
bool IP::RightClick()
{
    if (!rightClicked_ && sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
    {
        rightClicked_ = true;
        return true;
    }

    return false;
}

sf::Vector2f IP::GetMousePosition()
{
    //Get mouse position (pixel coordinates)
    sf::Vector2i mousePosition = sf::Mouse::getPosition(camera_->GetRenderWindow());
    //return mouse position after converting it to world coordinates
    return camera_->GetRenderWindow().mapPixelToCoords(mousePosition);
}

void IP::SetMousePosition(sf::Vector2i position)
{
    sf::Mouse::setPosition(position);
}


void IP::Reset()
{
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) pressedLeft_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) pressedRight_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) pressedUp_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) pressedDown_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) pressedSpace_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pressedW_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pressedA_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) pressedS_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pressedD_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) pressedZ_ = false;
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::X)) pressedX_ = false;

    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) leftClicked_ = false;
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) rightClicked_ = false;
}
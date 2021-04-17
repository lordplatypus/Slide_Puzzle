#ifndef IP_H_
#define ID_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Camera.h"

class IP
{
public:
    IP();
    ~IP();

    static void SetCamera(Camera* camera);

    //Keyboard Stuff

    //Returns true if the button given is currently being pressed - constantly active
    static bool GetButton(sf::Keyboard::Key buttonID);

    //Individual buttons - activates 1 per button press
    static bool PressLeft();
    static bool PressRight();
    static bool PressUp();
    static bool PressDown();
    static bool PressSpace();
    static bool PressW();
    static bool PressA();
    static bool PressS();
    static bool PressD();
    static bool PressZ();
    static bool PressX();

    //Mouse Stuff

    static bool GetMouseClick(sf::Mouse::Button buttonID);
    static bool LeftClick();
    static bool RightClick();
    static sf::Vector2f GetMousePosition();
    static void SetMousePosition(sf::Vector2i position);


    //Reset bools used for single button presses
    static void Reset();
};

#endif
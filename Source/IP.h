#ifndef IP_H_
#define IP_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Camera.h"

class IP
{
public:
    IP();
    ~IP();

    //Reset bools used for single button presses
    void Update(float delta_time);

    //Hold button for rapid fire after 1 sec, this is the flag to enable/disable
    void SetRapidFlag(const bool rapidFlag);

    //Keyboard Stuff

    //Returns true if the button given is currently being pressed - constantly active
    bool GetButton(sf::Keyboard::Key buttonID);
    bool GetButton(sf::Mouse::Button buttonID);
    bool GetButtonDown(sf::Keyboard::Key buttonID);
    bool GetButtonDown(sf::Mouse::Button buttonID);

    //Mouse Stuff

    sf::Vector2f GetMousePosition(Camera& camera);
    void SetMousePosition(sf::Vector2i position);

private:
    std::unordered_map<sf::Keyboard::Key, bool> pressedKeys_;
    std::unordered_map<sf::Mouse::Button, bool> pressedButtons_;
    //Rapid fire
    bool rapidFlag_{false}; //set to true for "hold to rapid fire"
    bool rapidActive_{false}; //gets set to true once "rapidTimer" reaches "holdTimeForRapid"
    float rapidTimer_{0.0f}; //keeps track of hold time
    float holdTimeForRapid_{1.0f}; //time needed to activate rapid
};

#endif
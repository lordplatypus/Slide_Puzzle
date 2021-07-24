#ifndef BUTTON_H_
#define BUTTON_H_
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "LP.h"

class Button
{
public:
    Button(LP& LP, const std::string& buttonText, const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f));
    ~Button();
    void Draw(Camera& camera) const;
    
    void SetActive(const bool active);
    bool GetActive() const;
    void SetPosition(const sf::Vector2f& position);
    const sf::Vector2f& GetPosition() const;
    void SetString(const std::string& string);
    std::string GetString();

    void Action();

private:
    bool active_{true};
    sf::Vector2f position_{0.0f, 0.0f};
    sf::Text buttonText_;
};

#endif
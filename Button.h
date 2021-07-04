#ifndef BUTTON_H_
#define BUTTON_H_
#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(const sf::Vector2f& position, const std::string& buttonText);
    ~Button();
    void Draw(sf::RenderWindow& render_window) const;
    
    void SetActive(const bool active);
    bool GetActive() const;
    void SetPosition(const sf::Vector2f& position);
    const sf::Vector2f& GetPosition() const;
    void SetString(const std::string& string);
    const std::string& GetString();

    void Action();

private:
    bool active_{true};
    sf::Vector2f position_{0.0f, 0.0f};
    sf::Text buttonText_;
};

#endif
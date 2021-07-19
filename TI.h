#ifndef TI_H_
#define TI_H_
#include <SFML/Graphics.hpp>

class TI
{
public:
    void SetActive(const bool active);
    const bool GetActive();
    void SetString(const sf::String& string);
    void AddToString(const sf::String& string);
    const sf::String& GetString() const;
    void Backspace();


    void ClearString();

private:
    sf::String string_{"image.png"};
    bool active_{false};
};

#endif
#ifndef COUNTER_H_
#define COUNTER_H_
#include <SFML/Graphics.hpp>

class Counter
{
public:
    Counter(const int startNum = 0, const int min = 0, const int max = 100, const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f));
    ~Counter();
    void Draw(sf::RenderWindow& render_window) const;

    void Increment(const int incrementAmount = 1);
    void Decrement(const int decrementAmount = 1);

    void SetActive(const bool active);
    bool GetActive() const;
    void SetPosition(const sf::Vector2f& position);
    const sf::Vector2f& GetPosition() const;
    void SetNum(const int num);
    int GetNum() const;
    void SetMin(const int min);
    int GetMin() const;
    void SetMax(const int max);
    int GetMax() const;

    void Action();

private:
    void UpdateText();

private:
    bool active_{true};
    sf::Vector2f position_;
    int num_{0};
    int min_{0};
    int max_{0};
    sf::Text numText_;
};

#endif
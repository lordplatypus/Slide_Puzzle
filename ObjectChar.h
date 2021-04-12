#ifndef OBJECT_CHAR_H_
#define OBJECT_CHAR_H_
#include "GameObject.h"

class ObjectChar : public GameObject
{
public:
    ObjectChar(const sf::Vector2f& position, int ID, Scene* scene);
    ~ObjectChar() override;
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    //void DelayedDraw(sf::RenderWindow& render_window) const override;

private:
    //Collision / Perception
    //void ReactOnCollision(GameObject& other) override;
    sf::RectangleShape rect_;
};

#endif
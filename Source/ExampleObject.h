#ifndef EXAMPLE_OBJECT_H_
#define EXAMPLE_OBJECT_H_
#include "GameObject.h"

class ExampleObject : public GameObject
{
public:
    ExampleObject(Scene* scene, const sf::Vector2f& position);
    ~ExampleObject() override;
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    void DelayedDraw(sf::RenderWindow& render_window) const override;

private:
    //Collision / Perception
    void ReactOnCollision(GameObject& other) override;
};

#endif
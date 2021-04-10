#ifndef TEST_OBJECT_H_
#define TEST_OBJECT_H_
#include "GameObject.h"

class TestObject : public GameObject
{
public:
    TestObject(const sf::Vector2f& position, const sf::Vector2f& scale, int layerID, int ID);
    ~TestObject() override;
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    //void DelayedDraw(sf::RenderWindow& render_window) const override;

private:
    //Collision / Perception
    //void ReactOnCollision(GameObject& other) override;
    sf::Text text_;
};

#endif
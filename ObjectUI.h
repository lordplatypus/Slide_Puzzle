#ifndef OBJECT_UI_H_
#define OBJECT_UI_H_
#include "GameObject.h"

class ObjectUI : public GameObject
{
public:
    ObjectUI(const sf::Vector2f& position, int ID, Scene* scene);
    ~ObjectUI() override;
    //void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
    //void DelayedDraw(sf::RenderWindow& render_window) const override;

private:
    //Collision / Perception
    //void ReactOnCollision(GameObject& other) override;
    sf::Text text_;
};

#endif
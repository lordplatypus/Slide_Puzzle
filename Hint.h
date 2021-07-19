#ifndef HINT_H_
#define HINT_H_
#include "GameObject.h"

class Hint : public GameObject
{
public:
    Hint(Scene* scene);
    ~Hint() override;
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;
};

#endif
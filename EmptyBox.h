#ifndef EMPTY_BOX_H_
#define EMPTY_BOX_H_
#include "GameObject.h"

class EmptyBox : public GameObject
{
public:
    EmptyBox(Scene* scene, const sf::Vector2f& position, const int ID, const int rowNum, const int columnNum);
    ~EmptyBox() override;
    void Update(float delta_time) override;
    void Draw(sf::RenderWindow& render_window) const override;

    void SetPosition(const sf::Vector2f& position, const int ID);

private:
    sf::RectangleShape rect_;
};

#endif
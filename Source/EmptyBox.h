#ifndef EMPTY_BOX_H_
#define EMPTY_BOX_H_
#include "GameObject.h"
#include "Options.h"

class EmptyBox : public GameObject
{
public:
    EmptyBox(Scene* scene, const sf::Vector2f& position, const int ID, Options* options, const sf::Vector2f& textureSize);
    ~EmptyBox() override;
    void Update(float delta_time) override;
    void Draw(Camera& camera) const override;

    void SetPosition(const sf::Vector2f& position, const int ID);

private:
    sf::RectangleShape rect_;
};

#endif
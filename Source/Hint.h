#ifndef HINT_H_
#define HINT_H_
#include "GameObject.h"
#include "IP.h"

class Hint : public GameObject
{
public:
    Hint(Scene* scene);
    ~Hint() override;
    void Update(float delta_time) override;
    void Draw(Camera& camera) const override;

private:
    IP IP_;
    bool active_{false};
};

#endif
#ifndef WIN_TEXT_H_
#define WIN_TEXT_H_
#include "GameObject.h"
#include "Options.h"
#include "IP.h"
#include "LP.h"

class WinText : public GameObject
{
public:
    WinText(Scene* scene, Options* options, LP& LP);
    ~WinText() override;
    void Update(float delta_time) override;
    void Draw(Camera& camera) const override;

    void SetActive(const bool active);
    const bool GetActive() const;

private:
    IP IP_;
    sf::Text text_;
    bool active_{false};
    bool showText_{true};
    sf::RectangleShape background_;
};

#endif
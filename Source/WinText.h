#ifndef WIN_TEXT_H_
#define WIN_TEXT_H_
#include "GameObject.h"
#include "Options.h"

class WinText : public GameObject
{
public:
    WinText(Scene* scene, Options* options);
    ~WinText() override;
    void Update(float delta_time) override;
    void Draw(Camera& camera) const override;

    void SetActive(const bool active);
    const bool GetActive() const;

private:
    sf::Text text_;
    bool active_{false};
    bool showText_{true};
    sf::RectangleShape background_;
};

#endif
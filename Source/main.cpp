#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
#include "EL.h"
#include "Camera.h"
#include "Game.h"

int main()
{
    bool isRunning = true;//bool for main game loop
    sf::RenderWindow render_window(sf::VideoMode(960.0f, 540.0f), "Game"); //game window

    Camera camera{&render_window, sf::Vector2f(1920.0f, 1080.0f)};
    camera.SetView("Game");

    EL EL{camera};
    EL.SetTextEntered("");

    DeltaTime deltaTime;

    Game game{camera, EL};

    while (EL.IsRunning())
    {//main game loop
        EL.PollEvent(render_window);
        game.Update(deltaTime.GetDeltaTime());
        render_window.clear();
        game.Draw(camera);
        render_window.display();
    }
    return EXIT_SUCCESS;
}
#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
#include "Camera.h"
#include "Game.h"
#include "LP.h"

int main()
{
    bool isRunning = true;//bool for main game loop
    sf::RenderWindow window(sf::VideoMode(960, 540), "Game"); //game window

    DeltaTime deltaTime;
    Camera camera{&window};
    camera.SetView("Main", window.getSize().x, window.getSize().y);
    Game game{&camera};

    while (isRunning)
    {//main game loop
        sf::Event event; //events
        while (window.pollEvent(event))
        {//
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect viewport(0.f, 0.f, 1.f, 1.f);

                float screenwidth = event.size.width / 960.f;
                float screenheight = event.size.height / 540.f;

                if(screenwidth > screenheight)
                {
                    viewport.width = screenheight / screenwidth;
                    viewport.left = (1.f - viewport.width) / 2.f;
                }
                else if(screenwidth < screenheight)
                {
                    viewport.height = screenwidth / screenheight;
                    viewport.top = (1.f - viewport.height) / 2.f;
                }

                camera.SetViewSize("Main", viewport);
            }
            else if (event.type == sf::Event::Closed)
            {
                isRunning = false;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                isRunning = false;
            }
        }
        game.Update(deltaTime.GetDeltaTime());
        window.clear();
        game.Draw(window);
        window.display();
    }
    return EXIT_SUCCESS;
}
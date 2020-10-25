#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
#include "Game.h"
#include "LP.h"

int main()
{
    bool isRunning = true;//bool for main game loop
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Kiara Loading Game"); //game window

    Game game;
    DeltaTime deltaTime;
    sf::View camera;
    camera.setSize(1920, 1080);
    camera.setCenter(1920/2, 1080/2);

    while (isRunning)
    {//main game loop
        sf::Event event; //events
        while (window.pollEvent(event))
        {//
            if (event.type == sf::Event::Resized)
            {
                window.setSize(sf::Vector2u(event.size.width, event.size.height));
            }
            else if (event.type == sf::Event::Closed)
            {
                isRunning = false;
            }
            else if (event.key.code == sf::Keyboard::Escape)
            {
                isRunning = false;
            }
        }
        game.Update(deltaTime.GetDeltaTime());
        window.setView(camera);
        game.Draw(); //objects are added to the draw maps
        window.clear();
        LP::Draw(&window); //actually draw objects
        window.display();
    }
    return EXIT_SUCCESS;
}
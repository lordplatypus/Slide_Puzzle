#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
#include "Camera.h"
#include "Game.h"
#include "LP.h"

int main()
{
    bool isRunning = true;//bool for main game loop
    Camera camera{sf::Vector2f(960.0f, 540.0f)};
    sf::RenderWindow render_window(sf::VideoMode(camera.GetAspectRatio().x, camera.GetAspectRatio().y), "Game"); //game window

    DeltaTime deltaTime;
    camera.SetView("Main");
    camera.SetView("UI");
    render_window.setView(*camera.GetView("Main"));
    Game game{&camera};

    while (isRunning)
    {//main game loop
        sf::Event event; //events
        while (render_window.pollEvent(event))
        {//
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect viewport(0.0f, 0.0f, 1.0f, 1.0f);

                float screenwidth = event.size.width / camera.GetAspectRatio().x;
                float screenheight = event.size.height / camera.GetAspectRatio().y;

                if(screenwidth > screenheight)
                {
                    viewport.width = screenheight / screenwidth;
                    viewport.left = (1.0f - viewport.width) / 2.0f;
                }
                else if(screenwidth < screenheight)
                {
                    viewport.height = screenwidth / screenheight;
                    viewport.top = (1.0f - viewport.height) / 2.0f;
                }

                for (auto view : camera.GetAllViews())
                {
                    view.second->setViewport(viewport);
                    render_window.setView(*view.second);
                }
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
        render_window.clear();
        game.Draw(render_window);
        render_window.display();
    }
    return EXIT_SUCCESS;
}
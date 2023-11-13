#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window({ 1920u, 1080u }, "CMake SFML Project" );
    ContextSettings settings;

    RectangleShape rectangle(Vector2f(120.f, 50.f));
    
    window.setFramerateLimit(60);
    settings.antialiasingLevel = 8;
    //settings.

    while (window.isOpen())
    {
        for (auto event = Event{}; window.pollEvent(event);)
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }


        window.clear();
        window.draw(rectangle);
        window.display();
    }
}
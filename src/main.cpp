#include <SFML/Graphics.hpp>
#include "gtest/gtest.h"

using namespace sf;

int main(int argc, char *argv[]){

    if (argc >= 1){
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }

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
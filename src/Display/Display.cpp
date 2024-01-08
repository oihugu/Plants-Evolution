#include "include/Display.hpp"

using namespace std;

Point::Point(float x, float y){
    this->x = x;
    this->y = y;
}

Point::~Point(){
}

/*
#####################
###### Display ######
#####################
*/

Display::Display()
{
    this->window.create(sf::VideoMode(800, 600), "Plants Evolution");
    this->window.setFramerateLimit(60);

    while (this->window.isOpen())
    {
        
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                // Invoke the destructor
                this->window.close();
        }

        this->window.clear();
        this->window.display();
    }    
}

vector<float> Display::getSize()
{
    vector<float> size{this->width, this->height};
    return size;
}

Display::~Display()
{
    this->window.close();
}
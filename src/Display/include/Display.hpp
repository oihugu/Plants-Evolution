#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Point{
public:
    float x;
    float y;

    Point(float x, float y);
    ~Point();
};

class Display{
private:
    sf::RenderWindow window;
    float width;
    float height;
public:
    std::vector<float> getSize();
    Display();
    ~Display();
};

#endif // DISPLAY_HPP


#ifndef TURTLE_HPP
#define TURTLE_HPP

#include <string>
#include <vector>

#include "./Display.hpp"

class Turtle{
private:
    Display *window;
    Point position;
    float angle;
    float length;

public:
    Point getInitialPosition();

    void setAngle(float angle);
    void setLength(float length);

    void moveForward();
    void addAngle(float angle);

    void reset(float angle, float length);

    Turtle(Display *window, float angle, float length);
    ~Turtle();
};

#endif // TURTLE_HPP
#include "include/Turtle.hpp"

Turtle::Turtle(Display *window, float angle, float length) : position(0,0)
{
    this->window = window;
    this->position = this->getInitialPosition();
    this->angle = angle;
    this->length = length;
}

Point Turtle::getInitialPosition(){
    float windowWidth = this->window->getSize()[0];
    float windowHeight = this->window->getSize()[1];
    return Point(windowWidth / 2, windowHeight);
}

void Turtle::setAngle(float angle){
    this->angle = angle;
}

void Turtle::setLength(float length){
    this->length = length;
}

void Turtle::moveForward(){
    float x = this->position.x + this->length * cos(this->angle);
    float y = this->position.y + this->length * sin(this->angle);
    this->position = Point(x, y);
}

void Turtle::addAngle(float angle){
    this->angle += angle;
}

void Turtle::reset(float angle, float length){
    this->position = this->getInitialPosition();
    this->angle = angle;
    this->length = length;
}


Turtle::~Turtle(){
    delete this->window;
}

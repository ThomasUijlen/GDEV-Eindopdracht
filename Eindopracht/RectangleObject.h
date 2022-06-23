#pragma once
#include "DrawableObject.h"
class RectangleObject :
    public DrawableObject
{
private:
    Vector2Custom size;
    sf::RectangleShape rect;

    void updateRectangle();

public:
    RectangleObject();
    RectangleObject(sf::Color c);
    RectangleObject(Vector2Custom pos);
    RectangleObject(Vector2Custom pos, sf::Color c);
    RectangleObject(Vector2Custom pos, Vector2Custom s, sf::Color c);
    void process();
};


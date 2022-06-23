#pragma once
#include <SFML/Graphics.hpp>
#include "Object2D.h"

class DrawableObject : 
    public Object2D
{

public:
    sf::Color color = sf::Color(255,255,255,255);

    DrawableObject();
    DrawableObject(sf::Color c);
    DrawableObject(Vector2Custom pos);
    DrawableObject(Vector2Custom pos, sf::Color c);
};


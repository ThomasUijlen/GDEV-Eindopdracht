#pragma once
#include "Character.h"
class Player :
    public Character
{
public:
    Player(Vector2Custom pos, Vector2Custom s, float m, sf::Color c);

    void handleInputs();
};


#pragma once
#include "Character.h"
#include <random>

class Enemy :
    public Character
{
private:
    Vector2Custom moveDirection;

public:
    Enemy(Vector2Custom pos, Vector2Custom s, float m, sf::Color c);

    void process();
};


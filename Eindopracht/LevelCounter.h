#pragma once
#include "Object2D.h"
#include "Text2D.h"

class LevelCounter :
    public Object2D
{
private :
    Text2D* scoreCounter;
    Text2D* livesCounter;

public:
    static int score;
    static int lives;

    LevelCounter();

    static void increaseScore(int amount);
    static void removeLife();
    static void resetCounter();

    void process();
};


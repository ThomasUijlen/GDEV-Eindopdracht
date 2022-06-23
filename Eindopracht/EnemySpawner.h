#pragma once
#include "Object2D.h"
class EnemySpawner :
    public Object2D
{
private:
    int waitCount = 0;
    int spawnDelay = 0;

public:
    EnemySpawner(Vector2Custom pos, int delay);
    void process();
};


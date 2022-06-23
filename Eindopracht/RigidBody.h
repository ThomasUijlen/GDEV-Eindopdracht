#pragma once
#include "CollisionBody.h"
#include <math.h>

class RigidBody :
    public CollisionBody
{
private:
    const float AIR_C = 0.05f;
    float mass = 1.0f;
    Vector2Custom velocity;

    void applyAirResistance();
    void moveBody();

public:
    RigidBody();
    RigidBody(Vector2Custom pos, Vector2Custom s);
    RigidBody(Vector2Custom pos, Vector2Custom s, float m);
    void process();
    void addForce(Vector2Custom f);
};


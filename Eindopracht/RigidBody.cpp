#include "RigidBody.h"

RigidBody::RigidBody() : CollisionBody()
{
}

RigidBody::RigidBody(Vector2Custom pos, Vector2Custom s) : CollisionBody(pos, s)
{
}

RigidBody::RigidBody(Vector2Custom pos, Vector2Custom s, float m) : CollisionBody(pos, s)
{
	mass = m;
}

void RigidBody::process()
{
	applyAirResistance();
	moveBody();
}

void RigidBody::applyAirResistance()
{
	Vector2Custom airForce = Vector2Custom(AIR_C * pow(velocity.x, 2), AIR_C * pow(velocity.y, 2));
	if (velocity.x < 0) airForce.x *= -1;
	if (velocity.y < 0) airForce.y *= -1;
	velocity -= airForce;
}

void RigidBody::moveBody()
{
	position += velocity;
}

void RigidBody::addForce(Vector2Custom f)
{
	velocity += f / mass;
}

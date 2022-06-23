#include "Character.h"

Character::Character(Vector2Custom pos, Vector2Custom s, float m, sf::Color c) : RigidBody(pos, s, m)
{
	rect = new RectangleObject(Vector2Custom(), s, c);
	addAsChild(rect);
}

void Character::destroyObject()
{
	CollisionBody::destroyObject();
	rect = nullptr;
}

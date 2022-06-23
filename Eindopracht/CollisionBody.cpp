#include "CollisionBody.h"
#include "GameEngine.h"
#include "Vector2Custom.h"
#include <iostream>

using namespace std;

CollisionBody::CollisionBody() : Object2D()
{
	size = Vector2Custom();

	auto* self = this;
	GameEngine::addCollisionBody(self);
}

CollisionBody::CollisionBody(Vector2Custom pos, Vector2Custom s) : Object2D(pos)
{
	position = pos;
	size = s;

	auto* self = this;
	GameEngine::addCollisionBody(self);
}

void CollisionBody::clearColliders()
{
	colliding = false;
	colliders.clear();
}

void CollisionBody::collisionCheck(CollisionBody* other)
{
	bool canCollide = false;
	for (int mask : masks) {
		for (int layer : other->layers) {
			if (mask == layer) {
				canCollide = true;
				break;
			}
		}
	}

	if (!canCollide) return;

	Vector2Custom ownGlobalPosition = getGlobalPosition();
	Vector2Custom ownTopLeft = ownGlobalPosition - (size / 2.0f);
	Vector2Custom ownBottomRight = ownGlobalPosition + (size / 2.0f);

	Vector2Custom otherGlobalPosition = other->getGlobalPosition();
	Vector2Custom otherTopLeft = otherGlobalPosition - (other->size / 2.0f);
	Vector2Custom otherBottomRight = otherGlobalPosition + (other->size / 2.0f);

	if (ownTopLeft.x > otherBottomRight.x || otherTopLeft.x > ownBottomRight.x) { return; }
	if (ownTopLeft.y > otherBottomRight.y || otherTopLeft.y > ownBottomRight.y) { return; }

	addCollider(other);
}

void CollisionBody::addCollider(CollisionBody* collider)
{
	std::cout << "colliding!" << "\n";
	colliding = true;
	colliders.push_back(collider);
}

void CollisionBody::addLayer(int layer)
{
	layers.push_back(layer);
}

void CollisionBody::addMask(int mask)
{
	masks.push_back(mask);
}

bool CollisionBody::isColliding()
{
	return colliding;
}

void CollisionBody::destroyObject()
{
	Object2D::destroyObject();
	auto* self = this;
	GameEngine::removeCollisionBody(self);
}

#pragma once
#include "Object2D.h"

class CollisionBody :
	public Object2D
{
private:
	bool colliding = false;
	std::vector<CollisionBody*> colliders;

public:
	std::vector<int> layers;
	std::vector<int> masks;
	Vector2Custom size;

	CollisionBody();
	CollisionBody(Vector2Custom pos, Vector2Custom s);

	void clearColliders();
	void collisionCheck(CollisionBody* other);
	void addCollider(CollisionBody* collider);
	void addLayer(int layer);
	void addMask(int mask);
	bool isColliding();
	virtual void destroyObject();
};


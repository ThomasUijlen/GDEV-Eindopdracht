#include "Enemy.h"
#include "GameEngine.h"
#include "LevelCounter.h"
#include <cstdlib>
#include <iostream>

Enemy::Enemy(Vector2Custom pos, Vector2Custom s, float m, sf::Color c) : Character(pos, s, m, c)
{
	if (std::rand() % 100 > 50) {
		moveDirection = Vector2Custom(-1, 0.1 + (std::rand() % 10) / 20.0);
	}
	else {
		moveDirection = Vector2Custom(1, 0.1 + (std::rand() % 10) / 20.0);
	}
}

void Enemy::process()
{
	RigidBody::process();

	//Wall bouncing
	Vector2Custom globalPosition = getGlobalPosition();
	if (globalPosition.x < 50) {
		moveDirection.x = 1;
	}
	if (globalPosition.x > GameEngine::renderWindow.getSize().x-50) {
		moveDirection.x = -1;
	}

	addForce(moveDirection);

	//Interaction
	if (isColliding()) {
		LevelCounter::increaseScore(1);
		destroyObject();
	}

	if (globalPosition.y > GameEngine::renderWindow.getSize().y + size.y / 2) {
		LevelCounter::removeLife();
		destroyObject();
	}
}

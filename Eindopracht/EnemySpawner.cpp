#include "EnemySpawner.h"
#include "Enemy.h"
#include "GameEngine.h"

EnemySpawner::EnemySpawner(Vector2Custom pos, int delay) : Object2D(pos)
{
	spawnDelay = delay;
}

void EnemySpawner::process()
{
	waitCount += 1;
	if (waitCount >= spawnDelay) {
		waitCount = 0;
		Enemy* enemy = new Enemy(Vector2Custom(rand() % GameEngine::renderWindow.getSize().x, 0), Vector2Custom(100, 100), 0.5f, sf::Color(255, 0, 0, 255));
		enemy->addMask(1);
		addAsChild(enemy);
	}
}

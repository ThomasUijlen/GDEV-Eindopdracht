#include "LevelCounter.h"
#include "GameEngine.h"

int LevelCounter::score = 0;
int LevelCounter::lives = 3;

LevelCounter::LevelCounter() : Object2D()
{
	livesCounter = new Text2D(Vector2Custom(GameEngine::renderWindow.getSize().x/4, 20), "", sf::Color(0, 255, 0, 255));
	addAsChild(livesCounter);
	scoreCounter = new Text2D(Vector2Custom(GameEngine::renderWindow.getSize().x - GameEngine::renderWindow.getSize().x/4, 20), "", sf::Color(0, 255, 0, 255));
	addAsChild(scoreCounter);
}

void LevelCounter::increaseScore(int amount)
{
	score += amount;
}

void LevelCounter::removeLife()
{
	lives -= 1;

	if (lives <= 0) {
		GameEngine::createScene(2);
	}
}

void LevelCounter::process()
{
	scoreCounter->text = "Score : " + std::to_string(score);
	livesCounter->text = "Lives : " + std::to_string(lives);
}

void LevelCounter::resetCounter()
{
	score = 0;
	lives = 3;
}



#include "Player.h"
#include "GameEngine.h"

Player::Player(Vector2Custom pos, Vector2Custom s, float m, sf::Color c) : Character(pos, s, m, c)
{
	addLayer(1);
}

void Player::handleInputs()
{
	Vector2Custom globalPosition = getGlobalPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && globalPosition.x > 50) {
		addForce(Vector2Custom(-1, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && globalPosition.x < GameEngine::renderWindow.getSize().x - 50) {
		addForce(Vector2Custom(1, 0));
	}
}
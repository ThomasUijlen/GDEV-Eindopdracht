#include "RectangleObject.h"
#include "SFML/Graphics.hpp"
#include "GameEngine.h"
#include <iostream>


RectangleObject::RectangleObject() : DrawableObject()
{
}

RectangleObject::RectangleObject(sf::Color c) : DrawableObject(c)
{
}

RectangleObject::RectangleObject(Vector2Custom pos) : DrawableObject(pos)
{
}

RectangleObject::RectangleObject(Vector2Custom pos, sf::Color c) : DrawableObject(pos, c)
{
}

RectangleObject::RectangleObject(Vector2Custom pos, Vector2Custom s, sf::Color c) : DrawableObject(pos, c)
{
	size = s;
}

void RectangleObject::process() {
	updateRectangle();
	GameEngine::renderWindow.draw(rect);
}

void RectangleObject::updateRectangle()
{
	rect.setSize(sf::Vector2f(size.x, size.y));
	rect.setFillColor(color);

	Vector2Custom globalPosition = getGlobalPosition() - size/2.0;
	rect.setPosition(sf::Vector2f(globalPosition.x, globalPosition.y));
}
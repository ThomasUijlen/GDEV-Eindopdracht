#include "DrawableObject.h"

DrawableObject::DrawableObject() : Object2D()
{
}

DrawableObject::DrawableObject(sf::Color c)
{
	color = c;
}

DrawableObject::DrawableObject(Vector2Custom pos) : Object2D(pos)
{
}

DrawableObject::DrawableObject(Vector2Custom pos, sf::Color c) : Object2D(pos)
{
	color = c;
}

#pragma once
#include "RigidBody.h"
#include "RectangleObject.h"
#include <SFML/Graphics.hpp>

class Character : 
	public RigidBody
{
private:
	RectangleObject* rect;

public:
	Character(Vector2Custom pos, Vector2Custom s, float m, sf::Color c);
	virtual void destroyObject();
};


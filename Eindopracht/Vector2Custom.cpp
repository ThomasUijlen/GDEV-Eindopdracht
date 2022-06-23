#include "Vector2Custom.h"
#include <math.h>

Vector2Custom::Vector2Custom()
{
	x = y = 0.0f;
}

Vector2Custom::Vector2Custom(float xValue, float yValue)
{
	x = xValue;
	y = yValue;
}

Vector2Custom::Vector2Custom(const Vector2Custom& vector)
{
	x = vector.x;
	y = vector.y;
}

Vector2Custom::Vector2Custom(const Vector2Custom* vector)
{
	x = vector->x;
	y = vector->y;
}

float Vector2Custom::distanceTo(const Vector2Custom& vector) const
{
	return sqrt(pow(vector.x - x, 2) + pow(vector.y - y, 2));
}

float Vector2Custom::dot(const Vector2Custom& vector) const
{
	return sqrt(x * vector.x + y*vector.y);
}

float Vector2Custom::getLength() const
{
	return 0.0f;
}

void Vector2Custom::normalize()
{
	float length = getLength();
	x /= length;
	y /= length;
}

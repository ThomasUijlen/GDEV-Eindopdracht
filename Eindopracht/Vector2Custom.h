#pragma once

class Vector2Custom
{
public:
	float x, y;

	Vector2Custom();
	Vector2Custom(float xValue, float yValue);
	Vector2Custom(const Vector2Custom& vector);
	Vector2Custom(const Vector2Custom* vector);

	//Functions
	float distanceTo(const Vector2Custom& vector) const;
	float dot(const Vector2Custom& vector) const;
	float getLength() const;
	void normalize();

	//Assignment operator
	inline Vector2Custom& operator= (const Vector2Custom& vector) { x = vector.x; y = vector.y; return *this; };

	//Booleans
	inline bool operator== (const Vector2Custom& vector) const { return (x == vector.x) && (y == vector.y); };
	inline bool operator!= (const Vector2Custom& vector) const { return (x != vector.x) || (y != vector.y); };

	//Vector with Vector interactions
	inline const Vector2Custom operator+ (const Vector2Custom& vector) const { return Vector2Custom(x + vector.x, y + vector.y); };
	inline const Vector2Custom operator- (const Vector2Custom& vector) const { return Vector2Custom(x - vector.x, y - vector.y); };
	inline const Vector2Custom operator* (const Vector2Custom& vector) const { return Vector2Custom(x * vector.x, y * vector.y); };
	inline const Vector2Custom operator/ (const Vector2Custom& vector) const { return Vector2Custom(x / vector.x, y / vector.y); };
	inline Vector2Custom& operator+= (const Vector2Custom& vector) { x += vector.x; y += vector.y; return *this; };
	inline Vector2Custom& operator-= (const Vector2Custom& vector) { x -= vector.x; y -= vector.y; return *this; };
	inline Vector2Custom& operator*= (const Vector2Custom& vector) { x *= vector.x; y *= vector.y; return *this; };
	inline Vector2Custom& operator/= (const Vector2Custom& vector) { x /= vector.x; y /= vector.y; return *this; };

	//Scalar operations
	inline const Vector2Custom operator* (float value) const { return Vector2Custom(x * value, y * value); };
	inline const Vector2Custom operator/ (float value) const { return Vector2Custom(x / value, y / value); };
	inline Vector2Custom& operator+= (float value) { x += value; y += value; return *this; };
	inline Vector2Custom& operator-= (float value) { x -= value; y -= value; return *this; };
	inline Vector2Custom& operator*= (float value) { x *= value; y *= value; return *this; };
	inline Vector2Custom& operator/= (float value) { x /= value; y /= value; return *this; };
};


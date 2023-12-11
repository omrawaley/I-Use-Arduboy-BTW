#include "vector2.h"

Vector2& Vector2::operator+=(Vector2 &vector2)
{
	this->x += vector2.x;
	this->y += vector2.y;

	return *this;
}

Vector2& Vector2::operator/=(const float &factor)
{
	this->x /= factor;
	this->y /= factor;

	return *this;
}
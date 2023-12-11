#pragma once

class Vector2
{
	public:
		float x;
		float y;

	public:
		Vector2& operator+=(Vector2 &vector2);
		Vector2& operator/=(const float &factor);
};
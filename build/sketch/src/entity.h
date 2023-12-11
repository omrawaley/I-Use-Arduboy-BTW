#line 1 "/Users/om/Arduboy/IUseArduboyBTW/src/entity.h"
#pragma once

#include <stdint.h>

#include "vector2.h"

class Entity
{
	public:
		Vector2 pos;
		Vector2 vel;

		uint8_t width;
		uint8_t height;

	public:
		Entity(float x, float y, uint8_t width, uint8_t height);
};
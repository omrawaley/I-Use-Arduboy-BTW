#line 1 "/Users/om/Arduboy/IUseArduboyBTW/src/entity.cpp"
#include "entity.h"

Entity::Entity(float x, float y, uint8_t width, uint8_t height) : width{width}, height{height}
{
	this->pos.x = x;
	this->pos.y = y;
}
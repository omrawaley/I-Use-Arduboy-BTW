#include "npc.h"

NPC::NPC() : Entity(0, 0, 8, 12)
{

}

void NPC::position(uint8_t row)
{
	uint8_t directionInt = random(0, 2);
	this->direction = static_cast<NPCDirection>(directionInt);

	switch(this->direction)
	{
		case NPCDirection::Left:
			this->pos.x = Arduboy2::width();
			break;

		case NPCDirection::Right:
			this->pos.x = (0 - this->width);
			break;
	}

	this->pos.y = row;
}

void NPC::update(Vector2 playerPos, uint8_t row)
{
	if(!this->isActive)
	{
		this->isCreeped = false;

		double delay = random(60, 181);

		if(Arduboy2::everyXFrames(delay))
		{
			this->position(row);

			this->isActive = true;
		}
	}

	switch(this->direction)
	{
		case NPCDirection::Left:
			this->vel.x -= Physics::speed;
			break;

		case NPCDirection::Right:
			this->vel.x += Physics::speed;
			break;
	}

	if(this->pos.x >= (Arduboy2::width() + this->width))
	{
		this->isActive = false;
	}

	if(this->pos.x <= (0 - (this->width * 2)))
	{
		this->isActive = false;
	}

	if(this->isCreeped)
	{
		if(this->pos.x <= -this->width || this->pos.x >= Arduboy2::width() || this->pos.y <= -this->height || this->pos.y >= Arduboy2::height())
		{
			this->isActive = false;
		}

		if(playerPos.x < this->pos.x)
		{
			this->vel.x += Physics::speed;
		}

		if(playerPos.x > this->pos.x)
		{
			this->vel.x -= Physics::speed;
		}

		if(playerPos.y < this->pos.y)
		{
			this->vel.y += Physics::speed;
		}

		if(playerPos.y > this->pos.y)
		{
			this->vel.y -= Physics::speed;
		}
	}

	if(!this->hasMessage)
	{
		this->message = nullptr;
	}

	this->vel /= Physics::friction;
	this->pos += this->vel;
}

void NPC::draw()
{
	Arduboy2::fillRect(this->pos.x, this->pos.y, this->width, this->height, WHITE);

	Arduboy2::drawRect(this->pos.x + 2, this->pos.y + 3, 1, 2, BLACK);

	Arduboy2::drawRect(this->pos.x + 5, this->pos.y + 3, 1, 2, BLACK);
}
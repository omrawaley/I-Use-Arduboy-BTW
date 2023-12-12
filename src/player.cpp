#include "player.h"

Player::Player() : Entity((Arduboy2::width() - 8) / 2, (Arduboy2::height() - 12) / 2, 8, 12)
{

}

void Player::input()
{
	if (Arduboy2::pressed(UP_BUTTON))
	{
		this->vel.y -= Physics::speed;
	}

	if (Arduboy2::pressed(DOWN_BUTTON))
	{
		this->vel.y += Physics::speed;
	}

	if (Arduboy2::pressed(LEFT_BUTTON))
	{
		this->vel.x -= Physics::speed;

		this->isRight = false;
	}

	if (Arduboy2::pressed(RIGHT_BUTTON))
	{
		this->vel.x += Physics::speed;

		this->isRight = true;
	}
}

void Player::update()
{
	this->input();

	if(this->pos.y < 0)
	{
		this->pos.y = 0;
	}

	if(this->pos.y > (Arduboy2::height() - this->height))
	{
		this->pos.y = (Arduboy2::height() - this->height);
	}

	if(this->pos.x < 0)
	{
		this->pos.x = 0;
	}

	if(this->pos.x > (Arduboy2::width() - this->width))
	{
		this->pos.x = (Arduboy2::width() - this->width);
	}

	this->vel /= Physics::friction;
	this->pos += this->vel;
}

void Player::draw()
{
	Arduboy2::drawRect(this->pos.x, this->pos.y, this->width, this->height, WHITE);

	Arduboy2::drawRect(this->pos.x + 2, this->pos.y + 3, 1, 2, WHITE);

	Arduboy2::drawRect(this->pos.x + 5, this->pos.y + 3, 1, 2, WHITE);
}
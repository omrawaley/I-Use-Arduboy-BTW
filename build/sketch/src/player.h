#line 1 "/Users/om/Arduboy/IUseArduboyBTW/src/player.h"
#pragma once

#include <Arduboy2.h>
#include "entity.h"

class Player : public Entity
{
	private:
		struct Physics
		{
			static constexpr float speed = 0.2f;
			static constexpr float friction = 1.2f;
		};

	private:
		void input();

	public:	
		Player();

		void update();
		void draw();
};
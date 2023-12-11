#pragma once

#include <Arduboy2.h>

#include "entity.h"

class NPC : public Entity
{
	public:
		struct Physics
		{
			static constexpr float speed = 0.08f;
			static constexpr float friction = 1.2f;
		};

		enum class NPCDirection : uint8_t
		{
			Left,
			Right,
		};

		NPCDirection direction;

	public:
		bool isActive;

		bool isCreeped;

	public:
		NPC();

		void position(uint8_t row);
		void update(Vector2 playerPos, uint8_t row);
		void draw();
};
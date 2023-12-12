#pragma once

#include <Arduboy2.h>
#include <stdint.h>

#include "fonts/Font3x5.h"
#include "assets.h"
#include "slowPrint.h"
#include "player.h"
#include "npc.h"

constexpr char missionMessageText[] PROGMEM = "After years of\ninstalling and\nconfiguring, you are\nnow ready. Go and\ntell the world that\nthey cannot\ncomprehend your\nultimate power.            ";

constexpr char *playerMessage = "I use Arduboy BTW";

constexpr char *npcMessages[] = {"Weirdo", "Nerd", "Bro WTF", "Okay?", "Stop!"};

class Game
{
	public:

		void start();
		void update();
		void gameState();

		enum class State : uint8_t
		{
			Splashscreen,
			Intro,
			IntroMessage,
			IntroFlash,
			Neofetch,
			MissionMessage,
			Game,
		};

	private:

		friend Game::State& operator++(Game::State &state);

		bool intersect(Vector2 posA, uint8_t widthA, uint8_t heightA, Vector2 posB, uint8_t widthB, uint8_t heightB);

		void activateNextState(uint8_t button);

		void updateSplashscreen();
		void drawSplashscreen();

		void updateIntro();
		void drawIntro();

		void updateIntroMessage();
		void drawIntroMessage();

		void updateIntroFlash();

		void updateNeofetch();
		void drawNeofetch();

		void updateGame();
		void drawGame();

		void updateMissionMessage();

	private:

		double weirdoLevel;

	private:

		State state;

		Arduboy2 arduboy;

		Font3x5 font3x5;

		SlowPrint slowPrinter;

		Player player;

		const uint8_t rows[4] = {7, 22, 37, 52};

		NPC npcs[4];
};
#include "game.h"

Game::State& operator++(Game::State &state)
{
	uint8_t stateInt = static_cast<uint8_t>(state);

	++stateInt;

	state = static_cast<Game::State>(stateInt);

	return state;
}

bool Game::intersect(Vector2 posA, uint8_t widthA, uint8_t heightA, Vector2 posB, uint8_t widthB, uint8_t heightB)
{
	if(posA.x <= posB.x + widthB)
		if(posA.x + widthA >= posB.x)
			if(posA.y <= posB.y + heightB)
				if(posA.y + heightA >= posB.y)
					return true;

	return false;
}

void Game::activateNextState(uint8_t button)
{
	if(this->arduboy.justPressed(button))
	{
		++this->state;
	}
}

void Game::updateSplashscreen()
{
	if(this->arduboy.everyXFrames(180))
		this->state = State::Intro;
}

void Game::drawSplashscreen()
{
	Sprites::drawOverwrite(0, 0, Assets::splashScreenSpecialSprite, 0);
}

void Game::updateIntro()
{
	this->activateNextState(A_BUTTON);
}

void Game::drawIntro()
{
	Sprites::drawOverwrite(0, 0, Assets::pokittoInstallationSprite, 0);
}

void Game::updateIntroMessage()
{
	this->activateNextState(A_BUTTON);
}

void Game::drawIntroMessage()
{
	Sprites::drawOverwrite(0, 0, Assets::introMessageSprite, 0);
}

void Game::updateIntroFlash()
{
	if(this->arduboy.everyXFrames(5))
	{
		this->arduboy.fillScreen(WHITE);
	}

	if(this->arduboy.everyXFrames(10))
	{
		this->arduboy.fillScreen(BLACK);
	}

	if(this->arduboy.everyXFrames(120))
	{
		this->state = State::Neofetch;
	}
}

void Game::updateNeofetch()
{
	this->activateNextState(A_BUTTON);
}

void Game::drawNeofetch()
{
	Sprites::drawOverwrite(0, 0, Assets::arduboyNeofetchSprite, 0);
}

void Game::updateMissionMessage()
{
	if(this->arduboy.everyXFrames(5))
	{
		this->slowPrinter.update();
	}

	this->slowPrinter.print(this->arduboy);

	if(this->slowPrinter.isFinished())
	{
		this->state = State::Game;
	}
}

void Game::updateGame()
{
	this->player.update();
	
	for(uint8_t i = 0; i < sizeof(this->npcs) / sizeof(this->npcs[0]); ++i)
	{
		this->npcs[i].update(this->player.pos, this->rows[i]);
	}
}

void Game::drawGame()
{
	this->font3x5.setCursor(0, 0);

	this->font3x5.print("Weirdo Level ");
	this->font3x5.print(static_cast<size_t>(weirdoLevel));
	
	for(auto & npc : this->npcs)
	{
		npc.draw();

		if(this->intersect(npc.pos, 8, 12, this->player.pos, 8, 12))
		{
			if(this->arduboy.pressed(A_BUTTON))
			{
				this->font3x5.setCursor(this->player.pos.x - 24, this->player.pos.y - 8);

				this->font3x5.print(playerMessage);

				this->font3x5.setCursor(npc.pos.x - 8, npc.pos.y - 8);

				this->font3x5.print(npcMessage);	

				npc.isCreeped = true;	

				weirdoLevel += 0.35;
			}
		}
	}

	this->player.draw();
}

void Game::gameState()
{
	switch(this->state)
	{
		case State::Splashscreen:
			this->updateSplashscreen();
			this->drawSplashscreen();
			break;

		case State::Intro:
			this->updateIntro();
			this->drawIntro();
			break;

		case State::IntroMessage:
			this->updateIntroMessage();
			this->drawIntroMessage();
			break;

		case State::IntroFlash:
			this->updateIntroFlash();
			break;

		case State::Neofetch:
			this->updateNeofetch();
			this->drawNeofetch();
			break;

		case State::MissionMessage:
			this->updateMissionMessage();
			break;

		case State::Game:
			this->updateGame();
			this->drawGame();
			break;
	}
}

void Game::start()
{
	this->arduboy.begin();

	this->arduboy.initRandomSeed();

	this->slowPrinter.setText(missionMessageText);
}

void Game::update()
{
	if(!this->arduboy.nextFrame())
		return;

	this->arduboy.pollButtons();

	this->arduboy.clear();
	this->gameState();
	this->arduboy.display();
}
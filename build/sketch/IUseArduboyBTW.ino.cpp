#include <Arduino.h>
#line 1 "/Users/om/Arduboy/IUseArduboyBTW/IUseArduboyBTW.ino"
#include "src/game.h"

Game game;

#line 5 "/Users/om/Arduboy/IUseArduboyBTW/IUseArduboyBTW.ino"
void setup();
#line 10 "/Users/om/Arduboy/IUseArduboyBTW/IUseArduboyBTW.ino"
void loop();
#line 5 "/Users/om/Arduboy/IUseArduboyBTW/IUseArduboyBTW.ino"
void setup()
{
	game.start();
}

void loop()
{
	game.update();
}


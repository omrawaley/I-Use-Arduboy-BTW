#line 1 "/Users/om/Arduboy/IUseArduboyBTW/src/slowPrint.h"
#pragma once

#include <stdint.h>

#include <Arduboy2.h>

class SlowPrint
{
	private:
		const char *text {nullptr};

		uint8_t length {0};

	public:

		void reset();
		void setText(const char *text);
		void update();
		void print(Arduboy2 &arduboy);
		
		bool isFinished();
};
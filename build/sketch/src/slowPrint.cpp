#line 1 "/Users/om/Arduboy/IUseArduboyBTW/src/slowPrint.cpp"
#include "slowPrint.h"

void SlowPrint::reset()
{
	this->length = 0;
}

void SlowPrint::setText(const char *text)
{
	this->reset();

	this->text = text;
}

void SlowPrint::update()
{
	if(this->isFinished())
		return;

	++this->length;
}

void SlowPrint::print(Arduboy2 &arduboy)
{
	for(uint8_t i = 0; i < this->length; ++i)
	{
		arduboy.print(static_cast<char>(pgm_read_byte(&text[i])));
	}
}

bool SlowPrint::isFinished()
{
	// check if the last character is a null character i.e. if we are at the end of the cstring
	return(pgm_read_byte(&this->text[this->length]) == '\0');
}
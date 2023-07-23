#pragma once
#include "SDL.h"
#include <iostream>

class KeyTest
{
public:
	KeyTest();
	~KeyTest();

	void checkKey();

	void PrintKeyInfo(SDL_KeyboardEvent* key);


private:
	SDL_Event event;

};


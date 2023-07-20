#pragma once
#include "SDL.h"
#include <cstdio>

class Renderer
{
public:
	bool initSurface();
	void quitSurface();

private:
	SDL_Surface* screen;
};


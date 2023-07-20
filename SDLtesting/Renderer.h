#pragma once
#include "SDL.h"
#include <cstdio>

class Renderer
{
public:
	bool initSurface();
	bool init_window_with_renderer();

	void quitSurface();

private:
	SDL_Surface* screen;
};


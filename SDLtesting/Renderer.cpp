#include "Renderer.h"


bool Renderer::initSurface()
{
    /* Initialize the SDL library */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr,
            "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    /* Clean up on exit */
    //SDL_Quit();

    /*
     * Initialize the display in a 640x480 8-bit palettized mode,
     * requesting a software surface
     */
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    window = SDL_CreateWindow("Sphere Rendering",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        640, 480, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        fprintf(stderr, "Window could not be created: %s\n", SDL_GetError());
        return 1;
    }

    screenSurface = SDL_GetWindowSurface(window);

    if (!screenSurface) {
        fprintf(stderr, "Screen surface could not be created: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

}

void Renderer::quitSurface()
{
    /* Clean up on exit */
    SDL_Quit();
}

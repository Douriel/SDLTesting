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

bool Renderer::init_window_with_renderer()
{
    SDL_Event event;
    SDL_Renderer* renderer;
    SDL_Window* window;
    int i;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr,
            "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    if (SDL_CreateWindowAndRenderer(640, 640, 0, &window, &renderer) < 0) {
        fprintf(stderr,
            "Window with Renderer could not be created: %s\n", SDL_GetError());
        exit(1);
    }

    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (i = 0; i < 640; ++i)
        SDL_RenderDrawPoint(renderer, i, i);
    SDL_RenderPresent(renderer);
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }

    return false;
}

void Renderer::quitSurface()
{
    /* Clean up on exit */
    SDL_Quit();
}

// SDLtesting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Renderer.h"
#include "KeyTest.h"


int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    Renderer m_renderer;
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Key Press Check", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        // Handle window creation error
        SDL_Quit();
        return 1;
    }

    // Event loop
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true; // Exit the loop if the window is closed
            }
            else if (event.type == SDL_KEYDOWN) {
                // Check which key is pressed
                switch (event.key.keysym.sym) {
                case SDLK_UP:
                    std::cout << "arriba" << std::endl;
                    break;
                case SDLK_DOWN:
                    // Handle the DOWN key press
                    std::cout << "abajo" << std::endl;
                    break;
                case SDLK_LEFT:
                    // Handle the LEFT key press
                    std::cout << "izquieda" << std::endl;
                    break;
                case SDLK_RIGHT:
                    // Handle the RIGHT key press
                    std::cout << "derecha" << std::endl;
                    break;
                    // Add more cases as needed for other keys
                default:
                    break;
                }
            }
        }

        // Your game loop code here...
    }

    // Cleanup and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

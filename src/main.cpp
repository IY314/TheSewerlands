#include <iostream>
#include <string>
#include "SDL_render.h"

#include <SDL.h>
#include <SDL_image.h>

void error_and_exit(const std::string& msg, const char* error = "") {
    std::cerr << "TheSewerlands: " << msg << error << '\n';
    std::exit(1);
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        error_and_exit("Unable to start SDL", SDL_GetError());
    else if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        error_and_exit("Unable to start SDL_image", IMG_GetError());

    SDL_Window* win = SDL_CreateWindow("TheSewerlands", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!win) error_and_exit("Unable to create window", SDL_GetError());

    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!rend) error_and_exit("Unable to create renderer", SDL_GetError());

    SDL_Event e;

    bool running = true;

    while (running) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
    }
}

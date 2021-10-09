#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>

//variables

//const variables
const int ScreenWidth = 1920;
const int ScreenHeight = 1080;
const int center = SDL_WINDOWPOS_CENTERED;

//SDL instances
SDL_Window* window = nullptr;
SDL_Surface* surface = nullptr;

int main(int argc, char* args[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cout << "Unable to init SDL";
        return -1;
    }

    window = SDL_CreateWindow("Breakout",center,center,ScreenWidth,ScreenHeight,1);
    surface = SDL_GetWindowSurface(window);

    SDL_Delay(2000);
    return 0;
}


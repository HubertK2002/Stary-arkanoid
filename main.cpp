#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "Ball.h"
#include "Vec2D.h"

//variables
bool quit = false;

//const variables
const int ScreenWidth = 1280;
const int ScreenHeight = 720;
const int center = SDL_WINDOWPOS_CENTERED;

//Game instances
Ball* ball = nullptr;

//SDL instances
SDL_Window* window = nullptr;
SDL_Surface* surface = nullptr;
SDL_Surface* ballTexture = nullptr;
SDL_Event event;

int main(int argc, char* args[])
{
    std::cout <<"Start Program" <<std::endl;
    if(SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cout << "Unable to init SDL";
        return -1;
    }
    int imgflag = IMG_INIT_PNG;
    if(!(IMG_Init(imgflag)&imgflag))
    {
        std::cout <<"Unable to init SDL_image";
        return -1;
    }

    window = SDL_CreateWindow("Breakout",center,center,ScreenWidth,ScreenHeight,SDL_WINDOW_SHOWN);
    surface = SDL_GetWindowSurface(window);
    ball = new Ball({ScreenWidth/2,ScreenHeight/2,16,16},{10,10});

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) quit = true;
            else if(event.type == SDL_KEYDOWN)
            {
                std::cout << "Key was pressed";
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        std::cout<< "q was pressed";
                    break;
                }
            }
        }
        SDL_FillRect(surface, NULL, 0x000000);
        SDL_Rect ballPos = ball->getPos();
        ballTexture = IMG_Load("src/Ball.png");
        SDL_BlitScaled(ballTexture,NULL,surface,&ballPos);
        SDL_UpdateWindowSurface(window);
        ball->Update(ScreenWidth,ScreenHeight);


    }

    SDL_FreeSurface(surface);
    SDL_FreeSurface(ballTexture);
    surface = NULL;
    ballTexture = NULL;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


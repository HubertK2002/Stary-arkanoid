#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "Ball.h"
#include "Vec2D.h"
#include "Bumper.h"
#include "Brick.h"

//variables
bool quit = false;
float frameTime = 0;
float prevTime = 0;
float currentTime = 0;
float deltaTime = 0;

//const variables
const int ScreenWidth = 1280;
const int ScreenHeight = 720;
const int center = SDL_WINDOWPOS_CENTERED;
const int brickWidth = 64;
const int brickHeight = 32;
const int brickSurfaceWidth = 64;
const int brickSurfaceHeight = 32;
const int row = 5;
const int columns = 20;
const int numBricks = row*columns;

//Game instances
Ball* ball = nullptr;
Bumper* bumper = nullptr;
Brick* brick[numBricks] = {};
Brick* testBrick = nullptr;

//SDL instances
SDL_Window* window = nullptr;
SDL_Surface* surface = nullptr;
SDL_Surface* ballTexture = nullptr;
SDL_Surface* brickSurface = nullptr;
SDL_Texture* bricktexture = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;

//brickTextures
SDL_Rect brickColor[row] = {};

void DrawBricks();
void CheckBricks();
void ClearBricks();
void Init();

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

    Init();

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
                    case SDLK_q:
                        quit = true;
                    break;
                }
            }
        }
        prevTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = (currentTime - prevTime) / 1000.0f;
        frameTime += deltaTime;

        if(frameTime >= 0.003f)
        {
            frameTime = 0;
            SDL_Rect ballPos = ball->getPos();
            SDL_Rect bumperPos = bumper->getPos();

            //Clear screen
            SDL_FillRect(surface, NULL, 0x000000);
            //Draw
            SDL_FillRect(surface, &bumperPos, 0x00FF00);
            SDL_RenderCopy(renderer,bricktexture,NULL,&ballPos);
            SDL_BlitScaled(ballTexture,NULL,surface,&ballPos);
            DrawBricks();
            //Update Surface
            SDL_UpdateWindowSurface(window);

            //Update
            ball->Update(ScreenWidth,ScreenHeight, bumperPos, deltaTime);
            CheckBricks();
            bumper->Update(ScreenWidth, deltaTime * 5000);
        }


    }

    SDL_FreeSurface(surface);
    SDL_FreeSurface(ballTexture);
    SDL_FreeSurface(brickSurface);
    surface = NULL;
    ballTexture = NULL;
    brickSurface = NULL;
    ClearBricks();
    ball = NULL;
    bumper = NULL;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void DrawBricks()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            brick[i* columns + j]->Draw(surface,brickSurface);
        }
    }
    testBrick->Draw(surface,brickSurface);
}
void CheckBricks()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            ball->CheckBrick(brick[i* columns + j]);
        }
    }
    ball->CheckBrick(testBrick);
}
void ClearBricks()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            brick[i*columns + j] = NULL;
        }
    }
    delete testBrick;
}
void Init()
{
    brickColor[0] = {0,0,brickSurfaceWidth,brickSurfaceHeight};
    brickColor[1] = {brickWidth*1,0,brickSurfaceWidth,brickSurfaceHeight};
    brickColor[2] = {brickWidth*2,0,brickSurfaceWidth,brickSurfaceHeight};
    brickColor[3] = {brickWidth*3,0,brickSurfaceWidth,brickSurfaceHeight};
    brickColor[4] = {brickWidth*4,0,brickSurfaceWidth,brickSurfaceHeight};

    window = SDL_CreateWindow("Breakout",center,center,ScreenWidth,ScreenHeight,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    bricktexture = SDL_CreateTextureFromSurface(renderer,brickSurface);
    surface = SDL_GetWindowSurface(window);
    ball = new Ball({ScreenWidth/2,ScreenHeight/2,16,16},{2000,2000});
    bumper = new Bumper({ScreenWidth/2,ScreenHeight-50,100,15});
    //brick = new Brick({600,200,brickWidth,brickHeight},orangeBrick);
    ballTexture = IMG_Load("src/Ball.png");
    brickSurface = IMG_Load("src/Bricks.png");

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            brick[i* columns + j] = new Brick({j*brickWidth,i*brickHeight,brickWidth,brickHeight},brickColor[i]);
        }
    }
    testBrick = new Brick({ball->getPos().x + 230, ball->getPos().y + 200,brickWidth,brickHeight},brickColor[1]);
}

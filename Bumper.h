#pragma once
#include <SDL2/SDL.h>
#include "Vec2D.h"

class Bumper
{
public:
    Bumper():pos({0,0,0,0}){}
    Bumper(SDL_Rect pos):pos(pos){posX = (float)pos.x; posY = (float)pos.y;}
    inline SDL_Rect getPos() {return pos;}
    void Update(int width, int vel);

private:
    float posX;
    float posY;
    SDL_Rect pos;

};

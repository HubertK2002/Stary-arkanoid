#pragma once
#include <SDL2/SDL.h>
#include "Vec2D.h"
class Ball{
public:
    Ball(): pos(NULL),vel(NULL){}
    Ball(SDL_Rect& pos, Vec2D& vel): pos(pos),vel(vel){}
    Ball(SDL_Rect pos, Vec2D vel): pos(pos),vel(vel){}

    void Update();
    void ReverseXVel() {vel.x = -vel.x;}
    void ReverseYVel() {vel.y = -vel.y;}
    inline SDL_Rect getPos()const {return pos;}

private:
    SDL_Rect pos;
    Vec2D vel;

}

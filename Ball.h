#pragma once
#include <SDL2/SDL.h>
#include "Vec2D.h"
class Ball{
public:
    Ball(): pos({0,0,0,0}),vel({0,0}){}
    Ball(SDL_Rect& pos, Vec2D& vel): pos(pos),vel(vel){}
    Ball(SDL_Rect pos, Vec2D vel): pos(pos),vel(vel){}

    void Update(int width, int height);
    void ReverseXVel() {vel.x = -vel.x;}
    void ReverseYVel() {vel.y = -vel.y;}
    inline SDL_Rect getPos() {return pos;}

private:
    SDL_Rect pos;
    Vec2D vel;

};

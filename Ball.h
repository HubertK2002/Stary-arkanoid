#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "Vec2D.h"
#include "Brick.h"

class Ball{
public:
    Ball(): pos({0,0,0,0}),vel({0,0}){}
    Ball(SDL_Rect& pos, Vec2D& vel): pos(pos),vel(vel){posX = float(pos.x); posY = float(pos.y);}
    Ball(SDL_Rect pos, Vec2D vel): pos(pos),vel(vel){posX = float(pos.x); posY = float(pos.y);}

    void Update(int width, int height, SDL_Rect& bumper, float deltaTime);
    void ReverseXVel() {vel.x = -vel.x;}
    void ReverseYVel() {vel.y = -vel.y;}
    inline SDL_Rect getPos() {return pos;}
    int collide(SDL_Rect& rect) const;
    bool CheckBrick(Brick* brick);

private:
    float posX;
    float posY;
    SDL_Rect pos;
    Vec2D vel;

};

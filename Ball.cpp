#include "Ball.h"

void Ball::Update(int width, int height, SDL_Rect& bumper, float deltaTime)
{
    if((pos.x <= 0 && vel.x < 0)|| (pos.x >= width && vel.x > 0)) ReverseXVel();
    if((pos.y <= 0 && vel.y < 0) || (pos.y >= height && vel.y > 0)) ReverseYVel();
    if(collide(bumper)) ReverseYVel();

    posX += vel.x * deltaTime;
    posY += vel.y * deltaTime;
    pos.x = (int)posX;
    pos.y = (int)posY;
}

int Ball::collide(SDL_Rect& rect) const
{
    int rectRight = rect.x + rect.w;
    int rectBottom = rect.y + rect.h;
    int ballRight = pos.x + pos.w;
    int ballBottom = pos.y + pos.h;
    int ballHCenter = (ballBottom + pos.y)/2;
    int ballWCenter = (ballRight + pos.x)/2;

    if(ballWCenter >= rect.x && ballWCenter <= rectRight)
    {
        if(ballHCenter > rect.y && ballHCenter < rectBottom) return 1;
        else if(ballHCenter <= rectBottom && ballHCenter >= rect.y) return 1;
    }

    if(ballHCenter >= rect.y && ballHCenter <= rectBottom)
    {
        if(ballRight >= rect.x && ballRight < rectRight) return 2;
        else if(pos.x <= rectRight && pos.x > rect.x) return 2;
    }





    return 0;

}

bool Ball::CheckBrick(Brick* brick)
{
    SDL_Rect brickPos = brick->getPos();
    int v = collide(brickPos);
    if( v && brick->isActive())
    {
        brick->Disable();
        if(v == 2) ReverseXVel();
        if(v == 1) ReverseYVel();
        return true;
    }
    return false;
}


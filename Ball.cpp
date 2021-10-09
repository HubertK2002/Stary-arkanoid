#include "Ball.h"

void Ball::Update(int width, int height)
{
    if(pos.x <= 0 || pos.x >= width) ReverseXVel();
    if(pos.y <= 0 || pos.y >= height) ReverseYVel();
    pos.x += vel.x;
    pos.y += vel.y;
}


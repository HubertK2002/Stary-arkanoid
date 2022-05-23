#include "Bumper.h"

void Bumper::Update(int width, int vel)
{
    const Uint8 * keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_LEFT] && pos.x >= 10) posX -= vel;
    if(keystate[SDL_SCANCODE_RIGHT] && pos.x <= (width - pos.w - 10)) posX += vel;

    pos.x = (int)posX;
}

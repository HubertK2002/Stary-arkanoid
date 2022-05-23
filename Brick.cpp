#include "Brick.h"

void Brick::Draw(SDL_Surface* surface, SDL_Surface* textureSurface)
{
    if(isVisible)
    SDL_BlitScaled(textureSurface,&texture, surface, &pos);
}

#pragma once
#include <SDL2/SDL.h>

class Brick{
public:
    Brick(SDL_Rect pos, SDL_Rect texture):pos(pos),texture(texture){};
    inline SDL_Rect getPos(){return pos;}
    inline bool isActive() {return isVisible;}
    void Draw(SDL_Surface* surface, SDL_Surface* textureSurface);
    void Disable(){isVisible = false;}

private:
    SDL_Rect pos;
    SDL_Rect texture;
    bool isVisible = true;

};

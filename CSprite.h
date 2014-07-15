#ifndef _CSPRITE_H_
    #define _CSPRITE_H_

#include "SDL.h"
#include "SDL_image.h"
//#include "CGame.h"
class CGame;

class CSprite
{
    public:
        CSprite();

    public:
        void Load(const char* cPath, int R, int G, int B);
        void Render ();

    private:
        SDL_Rect rcDest;
        SDL_Surface* sImage;
        SDL_Texture* tImage;

        CGame* Game; //<-- Creates error message no 1)

};


#endif // _CSPRITE_H_

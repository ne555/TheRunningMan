#include "CSprite.h"
#include "CGame.h"
#include <iostream>

CSprite::CSprite()
{
    sImage = NULL;
    tImage = NULL;
}


void CSprite::Load (const char* cPath, int R, int G, int B)
{
    sImage = IMG_Load(cPath);
    if (sImage == NULL)
    {
        std::cout << "Fehler beim Laden von " << cPath << "! SDL_Error: " << SDL_GetError() << "\n";
    }
    else
    {
        SDL_SetColorKey(sImage, SDL_TRUE, SDL_MapRGB(sImage-> format, R, G, B));
        tImage = SDL_CreateTextureFromSurface(Game->GetRenderer(), sImage); //<-- Creates error message no 2)
        if (tImage == NULL)
        {
            std::cout << "Fehler beim Umwandeln von einer Surface in eine Textur der Grafik " << cPath << "! SDL_Error: " << SDL_GetError() <<"\n";
        }
        SDL_FreeSurface (sImage);
    }
}



void CSprite::Render()
{
    SDL_RenderCopy (Game->GetRenderer(),tImage,NULL,&rcDest); //<-- Creates error message no 3)
}

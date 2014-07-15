#ifndef _CPLAYER_H_
    #define _CPLAYER_H_


#include "CSprite.h"
//#include "CGame.h"
#include <string>


class CPlayer
{
    public:
        CPlayer();

    public:
        void Init();
        void Render();


    private:

        CSprite SpritePlayer; //<-- Creates error message no 4)


};


#endif // _CPLAYER_H_

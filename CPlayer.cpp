#include "CPlayer.h"
#include "CGame.h"



CPlayer::CPlayer()
{

}

void CPlayer::Init()
{
    SpritePlayer.Load("data/imgs/player/Ash_Player.bmp", 255, 0, 255); //<-- Creates error message no 5)
}



void CPlayer::Render()
{
    SpritePlayer.Render(); //<-- Creates error message no 6)

}

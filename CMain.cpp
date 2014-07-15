#include "CGame.h"

CGame game;


int main (int argc, char* argv [])
{
    if(game.OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while(game.bRunning)
    {
        while(SDL_PollEvent(&Event))
        {
            game.OnEvent(&Event);
        }

        game.OnLoop(); //Update
        game.OnRender();
    }

    game.OnCleanup();


    return 0;
}

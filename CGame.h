#ifndef _CGAME_H_
    #define _CGAME_H_


#include "SDL.h"
#include "SDL_image.h"
#include "CPlayer.h"


class CGame
{
    public:
        CGame();


    public:

        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop(); //Data Updates
        void OnRender();
        void OnCleanup();

        int GetScreenWidth();
        int GetScreenHeight();

        SDL_Renderer* GetRenderer();

        bool bRunning;

    private:
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;
        SDL_Window* MainWindow;
        SDL_Renderer* MainRenderer;
        SDL_Surface* MainWindowSurface;

};


#endif // _CGAME_H_

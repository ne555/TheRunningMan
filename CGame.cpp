#include "CGame.h"
#include "CSprite.h"

#include <iostream>

CGame::CGame()
{
    bRunning = true;

    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 480;

    MainWindow = NULL;
    MainRenderer = NULL;
    MainWindowSurface = NULL;

}



bool CGame::OnInit()
{
    CSprite sprite;

    if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not be initialized! SDL_Error: " << SDL_GetError ();
    }
    else
    {
        MainWindow = SDL_CreateWindow ("The Running Man",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if (MainWindow == NULL)
        {
            std::cout << "SDL could not create the window! SDL_Error: " << SDL_GetError () << "\n";
        }
        else
        {
            MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
            if (MainRenderer == NULL)
            {
                std::cout << "SDL could not create the renderer! SDL_Error: " << SDL_GetError() << "\n";
            }
            else
            {
                MainWindowSurface = SDL_GetWindowSurface(MainWindow);
                if (MainWindowSurface == NULL)
                {
                    std::cout << "SDL could not get the window surface! SDL_Error: " << SDL_GetError() << "\n";
                }
            }
        }
    }
    return true;
}


void CGame::OnEvent(SDL_Event* Event)
{
    if(Event->type == SDL_QUIT)
    {
        bRunning = false;
    }
}


void CGame::OnLoop()
{

}

void CGame::OnRender()
{

    SDL_SetRenderDrawColor(MainRenderer,0,0,255,255);

    SDL_RenderPresent(MainRenderer);

}

void CGame::OnCleanup()
{
    SDL_FreeSurface (MainWindowSurface);
    SDL_DestroyWindow (MainWindow);
    SDL_DestroyRenderer (MainRenderer);

    SDL_Quit ();
}

int CGame::GetScreenHeight()
{
    return SCREEN_HEIGHT;
}

int CGame::GetScreenWidth()
{
    return SCREEN_WIDTH;
}

SDL_Renderer* CGame::GetRenderer()
{
    return MainRenderer;
}


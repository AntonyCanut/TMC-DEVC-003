//
//  Main.c
//  Space Invader
//
//  Created by Antony Canut on 19/07/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

SDL_Window *Window;
SDL_Renderer *Renderer;

SDL_Surface *sBackground;
SDL_Texture *tBackground;

SDL_Rect bPos;

char *srcBackgroundPicture = "fond_4800x4800.png";

void Init()
{
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("Init error\n");
        exit(1);
    }
    Window = SDL_CreateWindow("Space Invader", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    Renderer = SDL_CreateRenderer(Window, -1, 0);
    
    bPos.x = 0;
    bPos.y = 0;
    bPos.w = SCREEN_WIDTH;
    bPos.h = SCREEN_HEIGHT;
}

void Load()
{
    sBackground = SDL_LoadBMP(srcBackgroundPicture);
    tBackground = SDL_CreateTextureFromSurface(Renderer, sBackground);
    // Charger le vaisseau
}

void Destroy()
{
    // boucle for
    // sprite.destroy
    SDL_DestroyTexture(tBackground);
    SDL_FreeSurface(sBackground);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void Update()
{
    // boucle
    // sprite.update
    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, tBackground, 0, &bPos);
    SDL_RenderPresent(Renderer);
}

int main()
{
    int isRunning = 1;
    
    Init();
    Load();
    while(isRunning == 1)
    {
        Uint32 toWait;
        Uint32 time = SDL_GetTicks();
        Update();
        toWait = SDL_GetTicks() - time;
        if (toWait < 16)
            SDL_Delay(16 - toWait);
    }
    Destroy();
    return (0);
}
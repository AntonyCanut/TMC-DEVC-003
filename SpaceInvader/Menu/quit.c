//
//  Quit.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "../Headers/header.h"


void LoadContentQuit(){
    Quit->Texture = IMG_LoadTexture(Renderer, "img/decor/exit_500x2000_P_1000.png");
}

void UnLoadQuit(){
    SDL_DestroyTexture(Quit->Texture);
}

void DrawQuit(){
    SDL_RenderCopy(Renderer, Quit->Texture, &Quit->Part, &Quit->Quit);
}

void UpdateQuit(){
    if (isUp == true)
    {
        Play->Selected();
        Quit->Deselected();
    }
    else
    {
        Play->Deselected();
        Quit->Selected();
    }
}

void DestroyQuit(){
    Quit->UnLoad();
    free(Quit);
}

void SelectedQuit(){
    Quit->Part.x = 1000;
}

void DeselectedQuit()
{
     Quit->Part.x = 0;
}



void InitQuit(){
    Quit = malloc(sizeof(*Quit));
    Quit->Quit.x = 525;
    Quit->Quit.y = 630;
    Quit->Quit.w = 250;
    Quit->Quit.h = 125;

    Quit->Part.x = 0;
    Quit->Part.y = 0;
    Quit->Part.w = 1000;
    Quit->Part.h = 500;


    Quit->Load = LoadContentQuit;
    Quit->UnLoad = UnLoadQuit;
    Quit->Selected = SelectedQuit;
    Quit->Deselected = DeselectedQuit;
    Quit->Draw = DrawQuit;
    Quit->Update = UpdateQuit;
    Quit->Destroy = DestroyQuit;
}
//
//  Quit.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "header.h"


void LoadContentQuit(){
    tQuit= IMG_LoadTexture(Renderer, "img/decor/Quit_500x2000_P_1000.png");
}

void UnLoadQuit(){
    SDL_DestroyTexture(tQuit);
}

void DrawQuit(){
    SDL_RenderCopy(Renderer, tQuit, 0, &Quit->Quit);
}

void UpdateQuit(){

}

void DestroyQuit(){
    Quit->UnLoad();
    free(Quit);
}


void InitQuit(){
    Quit = (struct QuitStruct *) malloc(sizeof(struct QuitStruct) + 1);
    Quit->Quit.x = 400;
    Quit->Quit.y = 0;
    Quit->Quit.w = 500;
    Quit->Quit.h = 500;

    Quit->Load = LoadContentQuit;
    Quit->UnLoad = UnLoadQuit;
    Quit->Draw = DrawQuit;
    Quit->Update = UpdateQuit;
    Quit->Destroy = DestroyQuit;
}
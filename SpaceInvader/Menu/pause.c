//
//  pause.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "../Headers/header.h"

void LoadContentPause(){
    Pause->Texture = IMG_LoadTexture(Renderer, "img/decor/pause_500x1000.png");
}

void UnLoadContentPause(){
    SDL_DestroyTexture(Pause->Texture);
}

void DrawPause(){
    SDL_RenderCopy(Renderer, Pause->Texture, 0, &Pause->PauseMenu);
}

void UpdatePause(){
    
}

void UpdateInputPause(){
    
}

void DestroyPause(){
    Pause->UnLoad();
    free(Pause);
}


void InitPause(){
    Pause = malloc(sizeof(*Pause));
    Pause->PauseMenu.x = 400;
    Pause->PauseMenu.y = 0;
    Pause->PauseMenu.w = 500;
    Pause->PauseMenu.h = 500;

    Pause->Load = LoadContentPause;
    Pause->UnLoad = UnLoadContentPause;
    Pause->Draw = DrawPause;
    Pause->Update = UpdatePause;
    Pause->UpdateInput = UpdateInputPause;
    Pause->Destroy = DestroyPause;
}
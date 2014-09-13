//
//  Play.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "header.h"


void LoadContentPlay(){
    tPlay= IMG_LoadTexture(Renderer, "img/decor/play_500x2000_P_1000.png");
}

void UnLoadPlay(){
    SDL_DestroyTexture(tPlay);
}

void DrawPlay(){
    SDL_RenderCopy(Renderer, tPlay, 0, &Play->Play);
}

void UpdatePlay(){

}

void DestroyPlay(){
    Play->UnLoad();
    free(Play);
}


void InitPlay(){
    Play = (struct PlayStruct *) malloc(sizeof(struct PlayStruct) + 1);
    Play->Play.x = 400;
    Play->Play.y = 0;
    Play->Play.w = 500;
    Play->Play.h = 500;

    Play->Load = LoadContentPlay;
    Play->UnLoad = UnLoadPlay;
    Play->Draw = DrawPlay;
    Play->Update = UpdatePlay;
    Play->Destroy = DestroyPlay;
}
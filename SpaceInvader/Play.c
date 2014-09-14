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
    SDL_RenderCopy(Renderer, tPlay, &Play->Part, &Play->Play);
}

void UpdatePlay(){
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

void DestroyPlay(){
    Play->UnLoad();
    free(Play);
}

void SelectedPlay(){
    Play->Part.x = 1000;
}

void DeselectedPlay()
{
     Play->Part.x = 0;
}

void InitPlay(){
    Play = (struct PlayStruct *) malloc(sizeof(struct PlayStruct) + 1);
    Play->Play.x = 525;
    Play->Play.y = 500;
    Play->Play.w = 250;
    Play->Play.h = 125;

    Play->Part.x = 1000;
    Play->Part.y = 0;
    Play->Part.w = 1000;
    Play->Part.h = 500;

    Play->Load = LoadContentPlay;
    Play->UnLoad = UnLoadPlay;
    Play->Draw = DrawPlay;
    Play->Update = UpdatePlay;
    Play->Destroy = DestroyPlay;
    Play->Selected = SelectedPlay;
    Play->Deselected = DeselectedPlay;
}
//
//  background.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "header.h"

void LoadContentBackground(){
    tEarth = IMG_LoadTexture(Renderer, "img/decor/earth_1700x3800.png");
    tStar = IMG_LoadTexture(Renderer, "img/decor/fond_1920x1080.png");
}

void UnLoadBackground(){
    SDL_DestroyTexture(tStar);
    SDL_DestroyTexture(tEarth);
}

void DrawBackground(){
    SDL_RenderCopy(Renderer, tEarth, 0, &Background->PositionEarth);
    SDL_RenderCopy(Renderer, tStar, 0, &Background->PositionStar);
}

void UpdateBackground(){
    if (Background->PositionEarth.y < 600)
    {
        Background->PositionEarth.y += 1;
    }else{
        Background->PositionEarth.y = 0;
    }
}

void DestroyBackground(){
    UnLoadBackground();
    free(Background);
}


void InitBackground(){
    Background = (struct BackgroundStruct *) malloc(sizeof(struct BackgroundStruct) + 1);
    Background->PositionStar.x = 0;
    Background->PositionStar.y = 0;
    Background->PositionStar.w = SCREEN_WIDTH;
    Background->PositionStar.h = SCREEN_HEIGHT;

    Background->PositionEarth.x = 0;
    Background->PositionEarth.y = 0;
    Background->PositionEarth.w = SCREEN_WIDTH;
    Background->PositionEarth.h = SCREEN_HEIGHT;

    Background->Load = LoadContentBackground;
    Background->UnLoad = UnLoadBackground;
    Background->Draw = DrawBackground;
    Background->Update = UpdateBackground;
    Background->Destroy = DestroyBackground;
}
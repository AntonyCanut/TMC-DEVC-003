//
//  background.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "../Headers/header.h"

void LoadContentBackground(){
    Background->TextureEarth = IMG_LoadTexture(Renderer, "img/decor/earth_1700x3800.png");
    Background->TextureStar = IMG_LoadTexture(Renderer, "img/decor/fond_1920x1080.png");
}

void UnLoadContentBackground(){
    SDL_DestroyTexture(Background->TextureStar);
    SDL_DestroyTexture(Background->TextureEarth);
}

void DrawBackground(){
    SDL_RenderCopy(Renderer, Background->TextureEarth, 0, &Background->PositionEarth);
    SDL_RenderCopy(Renderer, Background->TextureStar, 0, &Background->PositionStar);
}

void UpdateBackground(){
    if (Background->PositionEarth.y < SCREEN_HEIGHT - 200)
    {
        Background->PositionEarth.y += 1;
    }else{
        Background->PositionEarth.y = -2062;
    }
}

void DestroyBackground(){
    Background->UnLoad();
    free(Background);
}


void InitBackground(){
    Background = malloc(sizeof(*Background));
    Background->PositionStar.x = 0;
    Background->PositionStar.y = 0;
    Background->PositionStar.w = SCREEN_WIDTH;
    Background->PositionStar.h = SCREEN_HEIGHT;

    Background->PositionEarth.x = 0;
    Background->PositionEarth.y = -2062;
    Background->PositionEarth.w = SCREEN_WIDTH;
    Background->PositionEarth.h = 2862;

    Background->Load = LoadContentBackground;
    Background->UnLoad = UnLoadContentBackground;
    Background->Draw = DrawBackground;
    Background->Update = UpdateBackground;
    Background->Destroy = DestroyBackground;
    Background->Load();
}

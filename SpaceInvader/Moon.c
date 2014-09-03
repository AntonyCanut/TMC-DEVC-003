//
//  Moon.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "header.h"

void LoadContentMoon(){
    tMoon= IMG_LoadTexture(Renderer, "img/decor/lune_3200x16000_P_3200.png");
}

void UnLoadMoon(){
    SDL_DestroyTexture(tMoon);
}

void DrawMoon(){
    SDL_RenderCopy(Renderer, tMoon, 0, &Moon->Position);
}

void UpdateMoon(){}

void DeadMoon(){}

void DestroyMoon(){
    UnLoadMoon();
    free(Moon);
}


void InitMoon(){
    Moon = (struct MoonStruct *) malloc(sizeof(struct MoonStruct) + 1);
    Moon->Position.x = 0;
    Moon->Position.y = 0;
    Moon->Position.w = 500;
    Moon->Position.h = 500;

    // Moon->LoadContent = LoadContentMoon();
    // Moon->UnLoadContent = UnLoadContentMoon();
    // Moon->Draw = DrawMoon();
    // Moon->Update = UpdateMoon();
    // Moon->Dead = DeadMoon();
}
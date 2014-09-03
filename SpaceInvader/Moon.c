//
//  Moon.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include "SpriteFunc.h"

struct Moon *Moon;

SDL_Surface* LoadMoon(){
    SDL_Surface *sMoon;
    sMoon= SDL_LoadBMP("img/decor/lune_3200x16000_P_3200.png");
    return sMoon;
}

void UnLoadMoon(){
    SDL_FreeSurface(LoadMoon());
}

void DrawMoon();

void UpdateMoon();

void DeadMoon();


void InitMoon(Coordonnees position){
    Moon->Position.x = -100;
    Moon->Position.y = 800;
    Moon->Position.w = 100;
    Moon->Position.h = 100;
    
    Moon->LoadContent = LoadContentMoon();
    Moon->UnLoadContent = UnLoadContentMoon();
    Moon->Draw = DrawMoon();
    Moon->Update = UpdateMoon();
    Moon->Dead = DeadMoon();
}
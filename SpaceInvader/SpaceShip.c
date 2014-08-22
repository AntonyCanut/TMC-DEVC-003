//
//  SpaceShip.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include "SpriteFunc.h"

struct Player *Ship;

SDL_Surface* LoadContentShip(){
    SDL_Surface *sShip;
    sShip = SDL_LoadBMP("joueur_600x3000_P_600.png");
    return sShip;
}

void UnLoadContentShip(){
    SDL_FreeSurface(LoadContentShip());
}

void DrawShip();

void UpdateShip();

void UpdateInputShip();

void ShotShip();

void DeadShip();


void InitShip(Coordonnees position){
    Ship->Position.x = 640;
    Ship->Position.y = 20;

    
    Ship->LoadContent = LoadContentShip();
    Ship->UnLoadContent = UnLoadContentShip();
    Ship->Draw = DrawShip();
    Ship->Update = UpdateShip();
    Ship->UpdateInput = UpdateInputShip();
    Ship->Shot = ShotShip();
    Ship->Dead = DeadShip();
}
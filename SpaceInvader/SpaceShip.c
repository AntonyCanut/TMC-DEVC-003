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


void LoadContentShip(){
    SDL_Surface *sShip;
    sShip = SDL_LoadBMP("img/player/joueur_600x3000_P_600.png");
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
    Ship = (struct ShipStruct *) malloc(sizeof(struct ShipStruct) + 1);
    Ship->Position.x = 640;
    Ship->Position.y = 20;
    Ship->Position.w = 30;
    Ship->Position.h = 50;
    
    Ship->LoadContent = LoadContentShip();
    Ship->UnLoadContent = UnLoadContentShip();
    Ship->Draw = DrawShip();
    Ship->Update = UpdateShip();
    Ship->UpdateInput = UpdateInputShip();
    Ship->Shot = ShotShip();
    Ship->Dead = DeadShip();
}

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
struct Ennemi *EnnemyShip1;

SDL_Surface* LoadContentShip(){
    SDL_Surface *sShip;
    sShip = SDL_LoadBMP("joueur_600x3000_P_600.png");
    return sShip;
}

SDL_Surface* LoadContentEShip1(){
    SDL_Surface *eShip1;
    eShip1 = SDL_LoadBMP("invader1_600x3600_P_600.png");
    return eShip1;
}

void UnLoadContentShip(){
    SDL_FreeSurface(LoadContentShip());
}

void UnLoadContentEnnemyShip1(){
    SDL_FreeSurface(LoadContentShip1());
}

void DrawShip();

void UpdateShip();

void UpdateInputShip();

void ShotShip();

void DeadShip();

void DrawEShip1();

void UpdateEShip1();

void ShotEShip1();

void DeadEShip1();


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

void InitEShip1(Coordonnees position){
    EnnemyShip1->Position.x = 20;
    EnnemyShip1->Position.y = 800;
    
    EnnemyShip1->LoadContent = LoadContentEShip1();
    EnnemyShip1->UnLoadContent = UnLoadContentEShip1();
    EnnemyShip1->Draw = DrawEShip1();
    EnnemyShip1->Update = UpdateEShip1();
    EnnemyShip1->Shot = ShotEShip1();
    EnnemyShip1->Dead = DeadEShip1();
}

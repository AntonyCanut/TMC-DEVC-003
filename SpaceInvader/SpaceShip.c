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
struct Ennemi *EnnemyShip;

struct Ennemi *EnnemyShip;


SDL_Surface* LoadContentShip(){
    SDL_Surface *sShip;
    sShip = SDL_LoadBMP("img/player/joueur_600x3000_P_600.png");
    return sShip;
}

SDL_Surface* LoadContentEShip(){
    SDL_Surface *eShip;
    eShip = SDL_LoadBMP("img/invader/invader1_600x3600_P_600.png");
    return eShip;
}

void UnLoadContentShip(){
    SDL_FreeSurface(LoadContentShip());
}

void UnLoadContentEnnemyShip(){
    SDL_FreeSurface(LoadContentEShip());


void DrawShip();

void UpdateShip();

void UpdateInputShip();

void ShotShip();

void DeadShip();


void DrawEShip();

void UpdateEShip();

void ShotEShip();

void DeadEShip();



void InitShip(Coordonnees position){
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

void InitEShip(Coordonnees position){
    EnnemyShip->Position.x = 20;
    EnnemyShip->Position.y = 800;
    EnnemyShip->Position.w = 30;
    EnnemyShip->Position.h = 50;
    
    EnnemyShip->LoadContent = LoadContentEShip();
    EnnemyShip->UnLoadContent = UnLoadContentEShip();
    EnnemyShip->Draw = DrawEShip();
    EnnemyShip->Update = UpdateEShip();
    EnnemyShip->Shot = ShotEShip();
    EnnemyShip->Dead = DeadEShip();
}

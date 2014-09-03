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
<<<<<<< HEAD
<<<<<<< HEAD
struct Ennemi *EnnemyShip1;
=======
struct Ennemi *EnnemyShip;
>>>>>>> FETCH_HEAD
=======

struct Ennemi *EnnemyShip;

>>>>>>> FETCH_HEAD

SDL_Surface* LoadContentShip(){
    SDL_Surface *sShip;
    sShip = SDL_LoadBMP("img/player/joueur_600x3000_P_600.png");
    return sShip;
}

<<<<<<< HEAD
<<<<<<< HEAD
SDL_Surface* LoadContentEShip1(){
    SDL_Surface *eShip1;
    eShip1 = SDL_LoadBMP("img/invader/invader1_600x3600_P_600.png");
    return eShip1;
=======
=======

>>>>>>> FETCH_HEAD
SDL_Surface* LoadContentEShip(){
    SDL_Surface *eShip;
    eShip = SDL_LoadBMP("img/invader/invader1_600x3600_P_600.png");
    return eShip;
<<<<<<< HEAD
>>>>>>> FETCH_HEAD
=======

>>>>>>> FETCH_HEAD
}

void UnLoadContentShip(){
    SDL_FreeSurface(LoadContentShip());
}

<<<<<<< HEAD
<<<<<<< HEAD
void UnLoadContentEnnemyShip1(){
    SDL_FreeSurface(LoadContentShip1());
=======
void UnLoadContentEnnemyShip(){
    SDL_FreeSurface(LoadContentShip());
>>>>>>> FETCH_HEAD
=======

void UnLoadContentEnnemyShip(){
    SDL_FreeSurface(LoadContentShip());

>>>>>>> FETCH_HEAD
}

void DrawShip();

void UpdateShip();

void UpdateInputShip();

void ShotShip();

void DeadShip();

<<<<<<< HEAD
<<<<<<< HEAD
void DrawEShip1();
=======
>>>>>>> FETCH_HEAD

void DrawEShip();

void UpdateEShip();

void ShotEShip();

void DeadEShip();
<<<<<<< HEAD
>>>>>>> FETCH_HEAD
=======

>>>>>>> FETCH_HEAD


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

<<<<<<< HEAD
<<<<<<< HEAD
void InitEShip1(Coordonnees position){
    EnnemyShip1->Position.x = 20;
    EnnemyShip1->Position.y = 800;
    
    EnnemyShip1->LoadContent = LoadContentEShip1();
    EnnemyShip1->UnLoadContent = UnLoadContentEShip1();
    EnnemyShip1->Draw = DrawEShip1();
    EnnemyShip1->Update = UpdateEShip1();
    EnnemyShip1->Shot = ShotEShip1();
    EnnemyShip1->Dead = DeadEShip1();
=======
=======

>>>>>>> FETCH_HEAD
void InitEShip(Coordonnees position){
    EnnemyShip->Position.x = 20;
    EnnemyShip->Position.y = 800;
    
    EnnemyShip->LoadContent = LoadContentEShip();
    EnnemyShip->UnLoadContent = UnLoadContentEShip();
    EnnemyShip->Draw = DrawEShip();
    EnnemyShip->Update = UpdateEShip();
    EnnemyShip->Shot = ShotEShip();
    EnnemyShip->Dead = DeadEShip();
<<<<<<< HEAD
>>>>>>> FETCH_HEAD
=======

>>>>>>> FETCH_HEAD
}

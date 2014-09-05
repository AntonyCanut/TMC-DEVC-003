  //
//  SpaceShipShoot.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "header.h"
int countUpdateShipShoot = 0;

void LoadContentShipShoot(){
    tShipShoot= IMG_LoadTexture(Renderer, "img/player/joueur_tire_300x480_P_120.png");
}

void UnLoadShipShoot(){
    SDL_DestroyTexture(tShipShoot);
}

void DrawShipShoot(){
    SDL_RenderCopy(Renderer, tShipShoot, &ShipShoot->Part, &ShipShoot->Position);
}

void UpdateShipShoot(){
    countUpdateShipShoot += 1;
}

void DeadShipShoot(){

}

void DestroyShipShoot(){
    UnLoadShipShoot();
    free(ShipShoot);
}

void InitShipShoot(){
    ShipShoot = (struct ShipShootStruct *) malloc(sizeof(struct ShipShootStruct) + 1);
    ShipShoot->Position.x = Ship->Position.x + 23;
    ShipShoot->Position.y = Ship->Position.y + 10;
    ShipShoot->Position.w = 15;
    ShipShoot->Position.h = 37;
    
    ShipShoot->Part.x = 0;
    ShipShoot->Part.y = 0;
    ShipShoot->Part.w = 120;
    ShipShoot->Part.h = 300;
}

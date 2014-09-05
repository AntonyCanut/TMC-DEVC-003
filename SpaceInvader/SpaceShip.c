  //
//  SpaceShip.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "header.h"

int countUpdateShip = 0;
int deadShip=0;

void LoadContentShip(){
    tShip= IMG_LoadTexture(Renderer, "img/player/joueur_600x3000_P_600.png");
}

void UnLoadShip(){
    SDL_DestroyTexture(tShip);
}

void DrawShip(){
    SDL_RenderCopy(Renderer, tShip, &Ship->Part, &Ship->Position);
}

void UpdateShip(){

}

void UpdateInputShip(){}

void ShotShip(){}

void DeadShip(){
    if(deadShip == 1){
        Ship->Part.x = 600;
        deadShip = 2;
    }else if (deadShip == 2)
    {
        Ship->Part.x = 1200;
        deadShip = 3;
    }else if (deadShip == 3)
    {
        Ship->Part.x = 1800;
        deadShip = 4;
    }else if (deadShip == 4)
    {
        Ship->Part.x = 2400;
        deadShip = 5;
    }else if (deadShip == 5)
    {
        deadShip=0;
        DestroyShip();
    }
}

void DestroyShip(){
    UnLoadShip();
    free(Ship);
}

void InitShip(){
    Ship = (struct ShipStruct *) malloc(sizeof(struct ShipStruct) + 1);
    Ship->Position.x = (SCREEN_WIDTH/2) - 35;
    Ship->Position.y = SCREEN_HEIGHT - 200;
    Ship->Position.w = 70;
    Ship->Position.h = 70;

    Ship->Part.x = 0;
    Ship->Part.y = 0;
    Ship->Part.w = 600;
    Ship->Part.h = 600;

}

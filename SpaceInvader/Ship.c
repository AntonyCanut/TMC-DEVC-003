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

void UnLoadContentShip(){
    SDL_DestroyTexture(tShip);
}

void DrawShip(){
    SDL_RenderCopy(Renderer, tShip, &Ship->Part, &Ship->Position);
}

void UpdateShip(){
    
    // if (countUpdateShip==30)
    // {
    //     deadShip=1;
    // }
    if (shoot==true)
    {
        Ship->Shot();
    }
    //DeadShip();
    countUpdateShip += 1;
}

void UpdateInputShip(){
    if(Ship->Position.x <= (SCREEN_WIDTH - 80) && right == true){
        Ship->Position.x += 5;
    }else if( Ship->Position.x >= 10 && left == true){
        Ship->Position.x -= 5;
    }  
}

void ShotShip(){
    // /* On crée un nouvel élément */
    // ShipShootElement* newShoot = (struct ShipShootStruct *) malloc(sizeof(struct ShipShootStruct) + 1);
 
    //  On assigne la valeur au nouvel élément 
    // newShoot->val = InitShipShoot();
 
    // /* On assigne l'adresse de l'élément suivant au nouvel élément */
    // newShoot->nxt = ShipShootList;
}

void DeadShip(){
    if(countUpdateShip%5==0 && deadShip == 1){
        Ship->Part.x = 600;
        deadShip = 2;
    }else if(countUpdateShip%5==0 && deadShip == 2){
        Ship->Part.x = 1200;
        deadShip = 3;
    }else if(countUpdateShip%5==0 && deadShip == 3){
        Ship->Part.x = 1800;
        deadShip = 4;
    }else if(countUpdateShip%5==0 && deadShip == 4){
        Ship->Part.x = 2400;
        deadShip = 5;
    }else if(countUpdateShip%5==0 && deadShip == 5){
        deadShip=0;
        Ship->Destroy();
    }
}

void DestroyShip(){
    Ship->UnLoad();
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

    Ship->Draw = DrawShip;
    Ship->Update = UpdateShip;
    Ship->Shot = ShotShip;
    Ship->Dead = DeadShip;
    Ship->UpdateInput = UpdateInputShip;
    Ship->Load = LoadContentShip;
    Ship->UnLoad = UnLoadContentShip;
    Ship->Destroy = DestroyShip;
}

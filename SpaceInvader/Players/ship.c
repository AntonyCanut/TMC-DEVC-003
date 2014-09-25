//
//  SpaceShip.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "../Headers/header.h"

int countUpdateShip = 0;

void LoadContentShip(){
    Ship->Texture = IMG_LoadTexture(Renderer, "img/player/joueur_800x3800_P_600_bonus_P_800.png");
}

void UnLoadContentShip(){
    SDL_DestroyTexture(Ship->Texture);
}

void DrawShip(){
    SDL_RenderCopy(Renderer, Ship->Texture, &Ship->Part, &Ship->Position);
}

void UpdateShip(){

    if (Ship->Shield == 1)
    {
        Ship->Position.w = 94;
        Ship->Position.h = 94;
        Ship->Part.x = 3000;
        Ship->Part.h = 800;
        Ship->Part.w = 800;
    }
    else if (Ship->IsAlive == 0 && Ship->Shield == 0)
    {
        Ship->Position.w = 70;
        Ship->Position.h = 70;
        Ship->Part.x = 0;
        Ship->Part.h = 600;
        Ship->Part.w = 600;
    }

    if(countUpdateShip%5==0 && Ship->IsAlive == 6){
        Ship->IsAlive = 0;
        Mix_PlayChannel(7, sonExplosion, 0);
    }

    Ship->Dead();
    countUpdateShip += 1;
}

void UpdateInputShip(){
    Uint32 ShootTmp=0;

    if(Ship->Position.x <= (SCREEN_WIDTH - 80) && right == true){
        Ship->Position.x += 5;
    }else if( Ship->Position.x >= 10 && left == true){
        Ship->Position.x -= 5;
    }
    Bullets *ShotListInput = ShipShootList;
    while (ShotListInput != NULL)
    {
        if (ShotListInput->Current->Direction==0 && ShotListInput->Current->ShootTime > ShootTmp)
        {
            ShootTmp=ShotListInput->Current->ShootTime;
        }
        ShotListInput = ShotListInput->Next;
    }
    if (shoot==true && (SDL_GetTicks() - ShootTmp) > 300){
        Ship->Shot();
        Mix_PlayChannel(8, sonTir, 0);
    }
}

void ShotShip(){
    BulletStruct *MyBullet = InitBullet(&Ship->Position, 0, 0);
    ShipShootList = AddAtFrontBulletList(ShipShootList, MyBullet);
}

void DeadShip(){

    if ( Ship->Shield == 1 && Ship->IsAlive == 1 )
    {
        Ship->Shield = 0;
        Ship->IsAlive = 0;
    }

    if(countUpdateShip%5==0 && Ship->IsAlive == 1){
        Ship->Part.x = 600;
        Ship->IsAlive = 2;
    }else if(countUpdateShip%5==0 && Ship->IsAlive== 2){
        Ship->Part.x = 1200;
        Ship->IsAlive = 3;
    }else if(countUpdateShip%5==0 && Ship->IsAlive == 3){
        Ship->Part.x = 1800;
        Ship->IsAlive = 4;
    }else if(countUpdateShip%5==0 && Ship->IsAlive == 4){
        Ship->Part.x = 2400;
        Ship->IsAlive = 5;
    }else if(countUpdateShip%5==0 && Ship->IsAlive == 5){
        Ship->Life -= 1;
        if(Ship->Life <= 0){
            Ship->IsAlive=10;
            Mix_PlayChannel(24, sonGameOver, -1);
            lose = true;
        }else{
            Ship->IsAlive=6;
        }
    }
}

void DestroyShip(){
    Ship->UnLoad();
    free(Ship);
}

void InitShip(){
    Ship = malloc(sizeof(*Ship));
    Ship->Position.x = (SCREEN_WIDTH/2) - 35;
    Ship->Position.y = SCREEN_HEIGHT - 200;
    Ship->Position.w = 70;
    Ship->Position.h = 70;

    Ship->Part.x = 0;
    Ship->Part.y = 0;
    Ship->Part.w = 600;
    Ship->Part.h = 600;
    Ship->IsAlive = 0;
    Ship->Life = 3;
    Ship->Shield = 0;

    Ship->Draw = DrawShip;
    Ship->Update = UpdateShip;
    Ship->Shot = ShotShip;
    Ship->Dead = DeadShip;
    Ship->UpdateInput = UpdateInputShip;
    Ship->Load = LoadContentShip;
    Ship->UnLoad = UnLoadContentShip;
    Ship->Destroy = DestroyShip;
}

//
//  BossBullet.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "../Headers/header.h"

void LoadContentBossBullet(){
    BossBullet->Texture = IMG_LoadTexture(Renderer, "img/boss/boss_tire_1200x4800_P_1200.png");
}

void UnLoadContentBossBullet(){
    SDL_DestroyTexture(BossBullet->Texture);
}

void DrawBossBullet(){
    SDL_RenderCopy(Renderer, BossBullet->Texture, &BossBullet->PartBody, &BossBullet->PositionBody);
    SDL_RenderCopy(Renderer, BossBullet->Texture, &BossBullet->PartTail, &BossBullet->PositionTail);
    SDL_RenderCopy(Renderer, BossBullet->Texture, &BossBullet->PartHead, &BossBullet->PositionHead);
}

void UpdateBossBullet(){
    if(BossBullet->IsAlive==0){
        BossBullet->PositionTail.x = 0;
        BossBullet->PositionTail.y = 0;
        BossBullet->PositionBody.x = 0;
        BossBullet->PositionBody.y = 0;
        BossBullet->PositionBody.h = 0;
        BossBullet->PositionHead.x = 0;
        BossBullet->PositionHead.y = 0;
    }else{
        if((SDL_GetTicks() - BossBullet->ShootTime) > 770){
            Boss->Shoot=0;
            BossBullet->PositionTail.y += 10;
            BossBullet->PositionBody.y += 10;
            BossBullet->PositionHead.y += 10;
        }else{
            BossBullet->PositionTail.x = Boss->Position.x;
            BossBullet->PositionBody.x = Boss->Position.x;
            BossBullet->PositionHead.x = Boss->Position.x;
            BossBullet->PositionBody.y -= 22;
            BossBullet->PositionBody.h += 57;
            BossBullet->PositionHead.y += 10;
        }

    }
    if (BossBullet->PositionTail.y >= SCREEN_HEIGHT)
    {
       BossBullet->IsAlive=0;
       Boss->Shoot=0;
    }
    if ( Ship->IsAlive == 0 && collision(BossBullet->PositionHead, Ship->Position) == 1){
        Ship->IsAlive=1;
        BossBullet->IsAlive=0;
        Boss->Shoot=0;
    }
}

void DestroyBossBullet(){
    BossBullet->UnLoad();
    free(BossBullet);
}

void InitBossBullet(){
    BossBullet = malloc(sizeof(*BossBullet));

    BossBullet->PositionHead.x = 0;
    BossBullet->PositionHead.y = 0;
    BossBullet->PositionHead.w = 220;
    BossBullet->PositionHead.h = 220;

    BossBullet->PositionBody.x = 0;
    BossBullet->PositionBody.y = 0;
    BossBullet->PositionBody.w = 220;
    BossBullet->PositionBody.h = 220;

    BossBullet->PositionTail.x = 0;
    BossBullet->PositionTail.y = 0;
    BossBullet->PositionTail.w = 220;
    BossBullet->PositionTail.h = 220;

    BossBullet->PartHead.x = 3600;
    BossBullet->PartHead.y = 0;
    BossBullet->PartHead.w = 1200;
    BossBullet->PartHead.h = 1200;

    BossBullet->PartBody.x = 2400;
    BossBullet->PartBody.y = 0;
    BossBullet->PartBody.w = 1200;
    BossBullet->PartBody.h = 1200;

    BossBullet->PartTail.x = 1200;
    BossBullet->PartTail.y = 0;
    BossBullet->PartTail.w = 1200;
    BossBullet->PartTail.h = 1200;

    BossBullet->IsAlive=0;
    BossBullet->ShootTime=0;

    BossBullet->Draw = DrawBossBullet;
    BossBullet->Update = UpdateBossBullet;
    BossBullet->Load = LoadContentBossBullet;
    BossBullet->UnLoad = UnLoadContentBossBullet;
    BossBullet->Destroy = DestroyBossBullet;
}

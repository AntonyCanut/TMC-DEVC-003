  //
//  SpaceBoss.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "../Headers/header.h"

int countUpdateBoss = 0;
bool tir;

void LoadContentBoss(){
    Boss->Texture = IMG_LoadTexture(Renderer, "img/boss/boss2_1200x8400_P_1200.png");
}

void UnLoadContentBoss(){
    SDL_DestroyTexture(Boss->Texture);
}

void DrawBoss(){
    SDL_RenderCopy(Renderer, Boss->Texture, &Boss->Part, &Boss->Position);
}

void UpdateBoss(){
    if (Boss->Shoot<=0)
    {
        if(countUpdateBoss%17==0 && Boss->Part.x == 0){
            Boss->Part.x = 1200;
        }else if(countUpdateBoss%17==0 && Boss->Part.x == 1200){
            Boss->Part.x = 0;
        }
        if (countUpdateBoss % 2 == 0) {
            if (Boss->Direction <= 0) {
                if (Boss->Position.x >= (SCREEN_WIDTH - 230)) {
                    Boss->Direction= 1;
                    Boss->Position.x -= 15;
                }else{
                    Boss->Position.x += 15;
                }
            } else {
                if (Boss->Position.x <= 10) {
                    Boss->Direction = 0;
                    Boss->Position.x += 15;
                }else{
                    Boss->Position.x -= 15;
                }
            }
        }
        if (BossBullet->IsAlive <=0 && countUpdateBoss % 2 == 0 && random_number(0, 5)==2 && ((Boss->Position.x + 110) >= (Ship->Position.x - 200) || (Boss->Position.x + 110) <= (Ship->Position.x + 200)))
        {
           Boss->Shoot=1;
           Boss->Shot();
           tir = true;
        }
    }else{
        Boss->Part.x = 7200;
    }
    if (BossBullet->IsAlive <= 0)
    {
        if (tir == true)
        {
            Boss->Part.x = 0;
            countUpdateBoss = 0;
            tir = false;
        }
    }
    Boss->Dead();
    countUpdateBoss+=1;
}

void ShotBoss(){
    BossBullet->IsAlive=1;
    BossBullet->ShootTime=SDL_GetTicks();
}

void DeadBoss(){
    if(countUpdateBoss%5==0 && Boss->IsAlive == 1){
        Boss->Part.x = 2400;
        Boss->IsAlive = 2;
    }else if(countUpdateBoss%5==0 && Boss->IsAlive== 2){
        Boss->Part.x = 3600;
        Boss->IsAlive = 3;
    }else if(countUpdateBoss%5==0 && Boss->IsAlive == 3){
        Boss->Part.x = 4800;
        Boss->IsAlive = 4;
    }else if(countUpdateBoss%5==0 && Boss->IsAlive == 4){
        Boss->Part.x = 6000;
        Boss->IsAlive = 5;
    }else if(countUpdateBoss%5==0 && Boss->IsAlive == 5){
        Boss->Life -= 1;
        if(Boss->Life <= 0){
            Boss->IsAlive=10;
        }else{
            Boss->Part.x = 0;
            Boss->IsAlive = 0;
        }
    }
}

void DestroyBoss(){
    Boss->UnLoad();
    free(Boss);
}

void InitBoss(){
    Boss = malloc(sizeof(*Boss));
    Boss->Position.x = (SCREEN_WIDTH/2) - 110;
    Boss->Position.y = 20;
    Boss->Position.w = 220;
    Boss->Position.h = 220;

    Boss->Part.x = 0;
    Boss->Part.y = 0;
    Boss->Part.w = 1200;
    Boss->Part.h = 1200;
    Boss->IsAlive = 10;
    Boss->Initialisation = 0;
    Boss->Life = 30;
    Boss->Direction=0;
    Boss->Shoot=0;
    tir = false;
    Boss->Draw = DrawBoss;
    Boss->Update = UpdateBoss;
    Boss->Shot = ShotBoss;
    Boss->Dead = DeadBoss;
    Boss->Load = LoadContentBoss;
    Boss->UnLoad = UnLoadContentBoss;
    Boss->Destroy = DestroyBoss;
}

  //
//  SpaceBoss.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "../Headers/header.h"

int countUpdateBoss = 0;

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
	if(countUpdateBoss%11==0 && Boss->Part.x == 0){}
		Boss->Part.x = 1200;
	}else if(countUpdateBoss%11==0 &&Boss->Part.x == 1200){}
		Boss->Part.x = 0;
	}

}

void ShotBoss(){
    // /* On crée un nouvel élément */
    // BossShootElement* newShoot = (struct BossShootStruct *) malloc(sizeof(struct BossShootStruct) + 1);
 
    //  On assigne la valeur au nouvel élément 
    // newShoot->val = InitBossShoot();
 
    // /* On assigne l'adresse de l'élément suivant au nouvel élément */
    // newShoot->nxt = BossShootList;
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
        }
        Boss->IsAlive=6;
    }
}

void DestroyBoss(){
    Boss->UnLoad();
    free(Boss);
}

void InitBoss(){
    Boss = malloc(sizeof(*Boss));
    Boss->Position.x = (SCREEN_WIDTH/2) - 120;
    Boss->Position.y = 20;
    Boss->Position.w = 120;
    Boss->Position.h = 120;
    
    Boss->Part.x = 0;
    Boss->Part.y = 0;
    Boss->Part.w = 1200;
    Boss->Part.h = 1200;
    Boss->IsAlive = 0;
    Boss->Life = 10;

    Boss->Draw = DrawBoss;
    Boss->Update = UpdateBoss;
    Boss->Shot = ShotBoss;
    Boss->Dead = DeadBoss;
    Boss->Load = LoadContentBoss;
    Boss->UnLoad = UnLoadContentBoss;
    Boss->Destroy = DestroyBoss;
}

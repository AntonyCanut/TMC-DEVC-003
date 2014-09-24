//
//  Bonus.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "../Headers/header.h"


void LoadContentBonus(){
    Bonus->Texture = IMG_LoadTexture(Renderer, "img/player/bonus_800x3200_P_800.png");
}

void UnLoadContentBonus(){
    SDL_DestroyTexture(Bonus->Texture);
}

void DrawBonus(){
    SDL_RenderCopy(Renderer, Bonus->Texture, &Bonus->Part, &Bonus->Position);
}

void UpdateBonus(){
	Bonus->Position.y += 4;
    if (collision(Bonus->Position, Ship->Position) == 1){
        Ship->Shield = 1;
		Bonus->Position.x = 0;
    	Bonus->Position.y = 0;
    	Bonus->IsAlive=0;
    }
	if (Bonus->Position.y > SCREEN_HEIGHT)
	{
		Bonus->Position.x = 0;
    	Bonus->Position.y = 0;
    	Bonus->IsAlive=0;
	}
}

void DestroyBonus(){
    Bonus->UnLoad();
    free(Bonus);
}

void InitBonus(){
    Bonus = malloc(sizeof(*Bonus));
    Bonus->Position.x = 0;
    Bonus->Position.y = 0;
    Bonus->Position.w = 70;
    Bonus->Position.h = 70;

    Bonus->Part.x = 0;
    Bonus->Part.y = 0;
    Bonus->Part.w = 800;
    Bonus->Part.h = 800;
    Bonus->IsAlive=0;

    Bonus->Draw = DrawBonus;
    Bonus->Update = UpdateBonus;
    Bonus->Load = LoadContentBonus;
    Bonus->UnLoad = UnLoadContentBonus;
    Bonus->Destroy = DestroyBonus;
    Bonus->Load();
}

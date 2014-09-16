//
//  Life.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "../Headers/header.h"


void LoadContentLife(){
    Life->Texture = IMG_LoadTexture(Renderer, "img/player/bonus_800x3200_P_800.png");
}

void UnLoadContentLife(){
    SDL_DestroyTexture(Life->Texture);
}

void DrawLife(){
    if (Ship->Shield == 1){
        Life->Part.x = 0;
        Life->Position.x = SCREEN_WIDTH - 280;
        if(Ship->Life < 3){
            Life->Position.x = SCREEN_WIDTH - 210;
        }
        if(Ship->Life < 2){
            Life->Position.x = SCREEN_WIDTH - 140;
        }
        SDL_RenderCopy(Renderer, tLife, &Life->Part, &Life->Position);
        Life->Part.x = 800;
    }

	if(Ship->Life >= 3){
		Life->Position.x = SCREEN_WIDTH - 210;
		SDL_RenderCopy(Renderer, Life->Texture, &Life->Part, &Life->Position);
	}
	if(Ship->Life >= 2){
		Life->Position.x = SCREEN_WIDTH - 140;
		SDL_RenderCopy(Renderer, Life->Texture, &Life->Part, &Life->Position);
	}
	if(Ship->Life>= 1){
		Life->Position.x = SCREEN_WIDTH - 70;
		SDL_RenderCopy(Renderer, Life->Texture, &Life->Part, &Life->Position);
	}
}

void UpdateLife(){

}

void DestroyLife(){
    Life->UnLoad();
    free(Life);
}

void InitLife(){
    Life = malloc(sizeof(*Life));
    Life->Position.x = SCREEN_WIDTH - 70;
    Life->Position.y = 0;
    Life->Position.w = 70;
    Life->Position.h = 70;
    
    Life->Part.x = 800;
    Life->Part.y = 0;
    Life->Part.w = 800;
    Life->Part.h = 800;

    Life->Draw = DrawLife;
    Life->Update = UpdateLife;
    Life->Load = LoadContentLife;
    Life->UnLoad = UnLoadContentLife;
    Life->Destroy = DestroyLife;
}

//
//
//  game_over.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "../Headers/header.h"

void LoadContentVictory(){
    Victory->Texture = IMG_LoadTexture(Renderer, "img/decor/victory_500x1800.png");
}

void UnLoadContentVictory(){
    SDL_DestroyTexture(Victory->Texture);
}

void DrawVictory(){
    SDL_RenderCopy(Renderer, Victory->Texture, 0, &Victory->VictoryText);
}

void UpdateVictory(){

}

void UpdateInputVictory(){

}

void DestroyVictory(){
    Victory->UnLoad();
    free(Victory);
}


void InitVictory(){
    Victory = malloc(sizeof(*Victory));
    Victory->VictoryText.x = 400;
    Victory->VictoryText.y = 0;
    Victory->VictoryText.w = 500;
    Victory->VictoryText.h = 500;

    Victory->Load = LoadContentVictory;
    Victory->UnLoad = UnLoadContentVictory;
    Victory->Draw = DrawVictory;
    Victory->Update = UpdateVictory;
    Victory->UpdateInput = UpdateInputVictory;
    Victory->Destroy = DestroyVictory;
}
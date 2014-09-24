//
//
//  game_over.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "../Headers/header.h"

void LoadContentGameOver(){
    GameOver->Texture = IMG_LoadTexture(Renderer, "img/decor/game_over_500x1800.png");
}

void UnLoadContentGameOver(){
    SDL_DestroyTexture(GameOver->Texture);
}

void DrawGameOver(){
    SDL_RenderCopy(Renderer, GameOver->Texture, 0, &GameOver->GameOverText);
}

void UpdateGameOver(){

}

void UpdateInputGameOver(){

}

void DestroyGameOver(){
    GameOver->UnLoad();
    free(GameOver);
}


void InitGameOver(){
    GameOver = malloc(sizeof(*GameOver));
    GameOver->GameOverText.x = 400;
    GameOver->GameOverText.y = 0;
    GameOver->GameOverText.w = 500;
    GameOver->GameOverText.h = 500;

    GameOver->Load = LoadContentGameOver;
    GameOver->UnLoad = UnLoadContentGameOver;
    GameOver->Draw = DrawGameOver;
    GameOver->Update = UpdateGameOver;
    GameOver->UpdateInput = UpdateInputGameOver;
    GameOver->Destroy = DestroyGameOver;
}
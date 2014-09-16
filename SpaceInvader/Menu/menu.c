//
//  menu.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "../Headers/header.h"

void LoadContentMenu(){
    Menu->Texture = IMG_LoadTexture(Renderer, "img/decor/fond_1920x1080.png");
}

void UnLoadContentMenu(){
    SDL_DestroyTexture(Menu->Texture);
}

void DrawMenu(){
    SDL_RenderCopy(Renderer, Menu->Texture, 0, &Menu->PositionStarMenu);
}

void UpdateMenu(){
    
}

void UpdateInputMenu(){
    
}

void DestroyMenu(){
    Menu->UnLoad();
    free(Menu);
}


void InitMenu(){
    Menu = malloc(sizeof(*Menu));
    Menu->PositionStarMenu.x = 0;
    Menu->PositionStarMenu.y = 0;
    Menu->PositionStarMenu.w = SCREEN_WIDTH;
    Menu->PositionStarMenu.h = SCREEN_HEIGHT;

    Menu->Load = LoadContentMenu;
    Menu->UnLoad = UnLoadContentMenu;
    Menu->Draw = DrawMenu;
    Menu->Update = UpdateMenu;
    Menu->UpdateInput = UpdateInputMenu;
    Menu->Destroy = DestroyMenu;
}

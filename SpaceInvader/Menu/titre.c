//
//  Titre.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "../Headers/header.h"


void LoadContentTitre(){
    Titre->Texture = IMG_LoadTexture(Renderer, "img/decor/titre_1500x2800.png");
}

void UnLoadTitre(){
    SDL_DestroyTexture(Titre->Texture);
}

void DrawTitre(){
    SDL_RenderCopy(Renderer, Titre->Texture, 0, &Titre->Titre);
}

void UpdateTitre(){

}

void DestroyTitre(){
    Titre->UnLoad();
    free(Titre);
}


void InitTitre(){
    Titre = malloc(sizeof(*Titre));
    Titre->Titre.x = 400;
    Titre->Titre.y = 0;
    Titre->Titre.w = 500;
    Titre->Titre.h = 500;

    Titre->Load = LoadContentTitre;
    Titre->UnLoad = UnLoadTitre;
    Titre->Draw = DrawTitre;
    Titre->Update = UpdateTitre;
    Titre->Destroy = DestroyTitre;
}
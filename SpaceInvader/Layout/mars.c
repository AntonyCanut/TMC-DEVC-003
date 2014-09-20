//
//  Mars.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "../Headers/header.h"

int countUpdateMars = 0;

void LoadContentMars(){
    Mars->Texture = IMG_LoadTexture(Renderer, "/img/decor/mars_1200x1200.png");
}

void UnLoadContentMars(){
    SDL_DestroyTexture(Mars->Texture);
}

void DrawMars(){
    SDL_RenderCopy(Renderer, Mars->Texture, 0, &Mars->Position);
}

void UpdateMars(){
    if (Mars->Position.x <= - 1000)
    {
        Mars->Position.x = SCREEN_WIDTH + 200;
        Mars->Position.y = 250;
        countUpdateMars = 0;
    }
    else
    {
        if (countUpdateMars % 3 == 0)
        {
            Mars->Position.x -= 2;
        }
        if (countUpdateMars % 7 == 0)
        {
            Mars->Position.y += 1;
        }
        countUpdateMars++;
    }

}

void DestroyMars(){
    Mars->UnLoad();
    free(Mars);
}


void InitMars(){
    Mars = malloc(sizeof(*Mars));
    Mars->Position.x = SCREEN_WIDTH + 200;
    Mars->Position.y = 250;
    Mars->Position.w = 70;
    Mars->Position.h = 70;

    Mars->Load = LoadContentMars;
    Mars->UnLoad = UnLoadContentMars;
    Mars->Draw = DrawMars;
    Mars->Update = UpdateMars;
    Mars->Destroy = DestroyMars;
}

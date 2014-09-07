//
//  Mars.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "header.h"

int countUpdateMars = 0;

void LoadContentMars(){
    tMars= IMG_LoadTexture(Renderer, "img/decor/mars_1200x1200.png");
}

void UnLoadContentMars(){
    SDL_DestroyTexture(tMars);
}

void DrawMars(){
    SDL_RenderCopy(Renderer, tMars, 0, &Mars->Position);
}

void UpdateMars(){
    if (Mars->Position.x <= - 1000)
        {
            Mars->Position.x = SCREEN_WIDTH + 200;
            Mars->Position.y = 250;
            countUpdateMars=0;
    }else{
        if (countUpdateMars%3 == 0)
        {
           Mars->Position.x -= 2;
        }
        if (countUpdateMars%7 == 0)
        {
            Mars->Position.y += 1;
        }
        countUpdateMars+=1;
    }

}

void DestroyMars(){
    Mars->UnLoad();
    free(Mars);
}


void InitMars(){
    Mars = (struct MarsStruct *) malloc(sizeof(struct MarsStruct) + 1);
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
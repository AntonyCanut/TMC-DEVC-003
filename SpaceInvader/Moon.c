//
//  Moon.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "header.h"

void LoadContentMoon(){
    tMoon= IMG_LoadTexture(Renderer, "img/decor/lune_3200x16000_P_3200.png");
}

void UnLoadMoon(){
    SDL_DestroyTexture(tMoon);
}

void DrawMoon(){
    SDL_RenderCopy(Renderer, tMoon, &Moon->Part, &Moon->Position);
}

void UpdateMoon(){
    if (Moon->Position.x < ((SCREEN_WIDTH / 2) - 150))
    {
            Moon->Position.x += 4;
            Moon->Position.y -= 1;
    }else if (Moon->Position.x > SCREEN_WIDTH + 400)
    {
        Moon->Position.x = -400;
        Moon->Position.y = 400;
    }else{
        Moon->Position.x += 4;
        Moon->Position.y += 1;
    }
}

void DeadMoon(){
    Moon->Part.x = 12800;
    Moon->Part.y = 0;
    Moon->Part.w = 3200;
    Moon->Part.h = 3200;
}

void DestroyMoon(){
    UnLoadMoon();
    free(Moon);
}


void InitMoon(){
    Moon = (struct MoonStruct *) malloc(sizeof(struct MoonStruct) + 1);
    Moon->Position.x = -400;
    Moon->Position.y = 400;
    Moon->Position.w = 300;
    Moon->Position.h = 300;

    Moon->Part.x = 0;
    Moon->Part.y = 0;
    Moon->Part.w = 3200;
    Moon->Part.h = 3200;

    // Moon->LoadContent = LoadContentMoon();
    // Moon->UnLoadContent = UnLoadContentMoon();
    // Moon->Draw = DrawMoon();
    // Moon->Update = UpdateMoon();
    // Moon->Dead = DeadMoon();
}
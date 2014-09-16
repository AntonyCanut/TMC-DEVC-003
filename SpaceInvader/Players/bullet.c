//
//  SpaceShipShoot.c
//  SpaceInvader
//
//  Created by Antony Canut on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#include "../Headers/header.h"
int countUpdateShipShoot = 0;

void LoadContentBullet(BulletStruct *Bullet){
    Bullet->Texture = IMG_LoadTexture(Renderer, "img/player/joueur_tire_300x480_P_120.png");
}

void UnLoadContentBullet(BulletStruct *Bullet){
    SDL_DestroyTexture(Bullet->Texture);
}

void DrawBullet(BulletStruct *Bullet){
    SDL_RenderCopy(Renderer, Bullet->Texture, &Bullet->Part, &Bullet->Position);
}

void UpdateBullet(BulletStruct *Bullet){
    if (Bullet->Direction == 0)
    {
        if (countUpdateShipShoot%3 ==0)
        {
            if(Bullet->Part.x >=360){
                Bullet->Part.x = 0;
            }else{
                Bullet->Part.x += 120;
            }
        }
        Bullet->Position.y -= 6;
        if(Bullet->Position.y <= 0)
            //DestroyShipShoot();
        countUpdateShipShoot += 1;
    }
    else
    {
        // A vérifier l'algorithme pour les ennemis
        if (countUpdateShipShoot%3 ==0)
        {
            if(Bullet->Part.x >=360){
                Bullet->Part.x = 0;
            }else{
                Bullet->Part.x += 120;
            }
        }
        Bullet->Position.y += 6;
        if(Bullet->Position.y <= 0)
            //DestroyShipShoot();
        countUpdateShipShoot += 1;   
    }
}

void DeadBullet(BulletStruct *Bullet){

}

void DestroyBullet(BulletStruct *Bullet){
    Bullet->UnLoad(Bullet);
    free(Bullet);
}

// La direction pour savoir si c'est le vaisseau ennemi ou celui du joueur qui a tiré
BulletStruct *InitBullet(SDL_Rect *Canon, int direction){
    BulletStruct *Bullet;
    Bullet = malloc(sizeof(*Bullet));
    Bullet->Position.x = Canon->x + 28;
    Bullet->Position.y = Canon->y + 10;
    Bullet->Position.w = 15;
    Bullet->Position.h = 37;
    Bullet->Direction = direction;
    
    Bullet->Part.x = 0;
    Bullet->Part.y = 0;
    Bullet->Part.w = 120;
    Bullet->Part.h = 300;

    Bullet->Load = LoadContentBullet;
    Bullet->UnLoad = UnLoadContentBullet;
    Bullet->Draw = DrawBullet;
    Bullet->Update = UpdateBullet;
    Bullet->Dead = DeadBullet;
    Bullet->Destroy = DestroyBullet;
    Bullet->Load(Bullet);
    return (Bullet);
}

//
//  game.c
//  SpaceInvader
//
//  Created by Camille Pire on 20/08/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//
#include "Headers/header.h"


void InitGame()
{
    InitPause();
    InitBackground();
    InitMoon();
    InitMars();
    InitShip();
    InitLife();
    InitLayout();
    // Dépendant du vaisseau, a ne faire qu'au tir
    MyBullet = InitBullet(&Ship->Position, 0);
    // Faire une liste
    MyInvader = InitInvader(11);
    MyInvader2 = InitInvader(91);
}

void LoadGame()
{
    Pause->Load();   
    Background->Load();
    Moon->Load();
    Mars->Load();
    Ship->Load();
    Life->Load();
    Layout->Load();
    // Les tirs sont dépendant du vaisseau.
    // MyBullet->Load(MyBullet);
    // Les ennemis sont nombreux, boucle pour parcourire la liste.
    // MyInvader->Load();
}

void DestroyGame()
{
    Life->Destroy();
    Ship->Destroy();
    Mars->Destroy();
    Moon->Destroy();
    Background->Destroy();
    MyBullet->Destroy(MyBullet);
    MyInvader->Destroy(MyInvader);
    MyInvader2->Destroy(MyInvader2);
}

void UpdateGame()
{
    Layout->Update();
    if (Ship->IsAlive < 10)
    {
        Ship->Update();
    }
    // Traitement a faire dans les listes
    MyBullet->Update(MyBullet);
    Life->Update();
    MyInvader->Update(MyInvader);
    MyInvader2->Update(MyInvader2);

}


void DrawGame(){
    SDL_RenderClear(Renderer);
    
    Layout->Draw();
    if (Ship->IsAlive < 6)
    {
        Ship->Draw();
    }
    // Dépendance aux listes
    MyBullet->Draw(MyBullet);

    Life->Draw();

    MyInvader->Draw(MyInvader);
    MyInvader2->Draw(MyInvader2);
    if (paused == true)
    {
        Pause->Draw();
    }
    SDL_RenderPresent(Renderer);
}


void UpdateGameInput()
{
    while (SDL_PollEvent(&e))
    {
        switch(e.type){
            case SDL_QUIT:
                DestroyMain();
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym){
                    case SDLK_RIGHT:
                        right = true;
                        break;
                    case SDLK_LEFT:
                        left = true;
                        break;
                    case SDLK_SPACE:
                        shoot = true;
                        break;
                    case SDLK_ESCAPE:
                        menu=true;
                        destroy = true;
                        play = false;
                        break;
                    case SDLK_p:
                        paused = true;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(e.key.keysym.sym){
                    case SDLK_RIGHT:
                        right = false;
                        break;
                    case SDLK_LEFT:
                        left = false;
                        break;
                    case SDLK_SPACE:
                        shoot = false;
                        break;
                    case SDLK_ESCAPE:
                        menu=true;
                        destroy = true;
                        play = false;
                        break;
                    case SDLK_p:
                        paused = true;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    Ship->UpdateInput();
}


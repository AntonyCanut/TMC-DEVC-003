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
    InitBoss();
    InitLayout();
    ShipShootList = NULL;
    InvaderList = NULL;
    // Faire une liste
    for (int i = 0; i <= 6; i++)
    {
        InvaderStruct *MyInvader = InitInvader(11 + (80 * i));
        InvaderList = AddAtFrontInvaderList(InvaderList, MyInvader);
    }
}

void LoadGame()
{
    Pause->Load();   
    Background->Load();
    Moon->Load();
    Mars->Load();
    Ship->Load();
    Life->Load();
    Boss->Load();
    Layout->Load();
}

void DestroyGame()
{
    Life->Destroy();
    Ship->Destroy();
    Mars->Destroy();
    Moon->Destroy();
    Boss->Destroy();
    Background->Destroy();
    Bullets *ShotList = ShipShootList;
    while (ShotList != NULL)
    {
        ShotList->Current->Destroy(ShotList->Current);
        ShotList = ShotList->Next;
    }
    Invaders *InvaderListTemp = InvaderList;
    while (InvaderListTemp != NULL)
    {
        InvaderListTemp->Current->Destroy(InvaderListTemp->Current);
        InvaderListTemp = InvaderListTemp->Next;
    }
}

void UpdateGame()
{
    Layout->Update();
    if (Ship->IsAlive < 10)
    {
        Ship->Update();
    }
    Bullets *ShotList = ShipShootList;
    while (ShotList != NULL)
    {
        ShotList->Current->Update(ShotList->Current);
        ShotList = ShotList->Next;
    }
    Invaders *InvaderListTemp = InvaderList;
    while (InvaderListTemp != NULL)
    {
        InvaderListTemp->Current->Update(InvaderListTemp->Current);
        InvaderListTemp = InvaderListTemp->Next;
    }
    Life->Update();
    Boss->Update();
}


void DrawGame(){
    SDL_RenderClear(Renderer);
    
    Layout->Draw();
    if (Ship->IsAlive < 6)
    {
        Ship->Draw();
    }
    Bullets *ShotList = ShipShootList;
    while (ShotList != NULL)
    {
        ShotList->Current->Draw(ShotList->Current);
        ShotList = ShotList->Next;
    }
    Invaders *InvaderListTemp = InvaderList;
    while (InvaderListTemp != NULL)
    {
        InvaderListTemp->Current->Draw(InvaderListTemp->Current);
        InvaderListTemp = InvaderListTemp->Next;
    }
    Life->Draw();
    Boss->Draw();
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


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

    for (int i = 0; i <= 6; i++)
    {
        srand(time(NULL));
        InvaderStruct *MyInvader = InitInvader(11 + (80 * i), 0 , 4);
        InvaderList = AddAtFrontInvaderList(InvaderList, MyInvader);
    }
    for (int i = 0; i <= 6; i++)
    {
        srand(time(NULL));
        InvaderStruct *MyInvader = InitInvader(11 + (80 * i), 1 , 3);
        InvaderList = AddAtFrontInvaderList(InvaderList, MyInvader);
    }
    for (int i = 0; i <= 6; i++)
    {
        srand(time(NULL));
        InvaderStruct *MyInvader = InitInvader(11 + (80 * i), 2 , 2);
        InvaderList = AddAtFrontInvaderList(InvaderList, MyInvader);
    }
    for (int i = 0; i <= 6; i++)
    {
        srand(time(NULL));
        InvaderStruct *MyInvader = InitInvader(11 + (80 * i), 3 , 1);
        InvaderList = AddAtFrontInvaderList(InvaderList, MyInvader);
    }
    InitBonus();
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
    Bonus->Load();
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
    Bonus->Destroy();
}

void UpdateCollision()
{
    Bullets *ShotList = ShipShootList;
    Invaders *InvaderListTemp = InvaderList;
    int i = 0;
    int j = 0;
    while (ShotList != NULL)
    {
        if (ShotList->Current->Direction != 1)
        {
            while (InvaderListTemp != NULL)
            {
                if (collision(ShotList->Current->Position, InvaderListTemp->Current->Position) == 1)
                {
                    if (Bonus->IsAlive==0 && Ship->Shield != 1 && random_number(0, 10) == 5)
                        {
                            Bonus->IsAlive=1;
                            Bonus->Position.x = InvaderListTemp->Current->Position.x - 35;
                            Bonus->Position.y = InvaderListTemp->Current->Position.y - 35;
                        }
                    InvaderListTemp->Current->DeadInv=1;
                    ShipShootList = DeleteElementBulletList(ShipShootList, ShotList->Current);
                }
                InvaderListTemp = InvaderListTemp->Next;
                j++;
            }
        }else{
            if (collision(ShotList->Current->Position, Ship->Position) == 1){
                Ship->IsAlive=1;
                ShipShootList = DeleteElementBulletList(ShipShootList, ShotList->Current);
            }
        }
        ShotList = ShotList->Next;
        i++;
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
        if( ShotList->Current->Position.y < 20 || ShotList->Current->Position.y > SCREEN_HEIGHT-20){
            ShipShootList = DeleteElementBulletList(ShipShootList, ShotList->Current);
        }else{
            ShotList->Current->Update(ShotList->Current);
        }
        ShotList = ShotList->Next;
    }
    Invaders *InvaderListTemp = InvaderList;
    while (InvaderListTemp != NULL)
    {
        if(InvaderListTemp->Current->DeadInv==6){
            InvaderList = DeleteElementInvaderList(InvaderList, InvaderListTemp->Current);
        }else{
            InvaderListTemp->Current->Update(InvaderListTemp->Current);
        }
        InvaderListTemp->Current->Dead(InvaderListTemp->Current);
        InvaderListTemp = InvaderListTemp->Next;
    }
    UpdateCollision();
    Life->Update();
    Boss->Update();
    if (Bonus->IsAlive > 0)
    {
        Bonus->Update();
    }
}

void DrawGame(){
    SDL_RenderClear(Renderer);

    Layout->Draw();
    if (Ship->IsAlive < 6)
    {
        Ship->Draw();
    }
    if (Bonus->IsAlive > 0)
    {
        Bonus->Draw();
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


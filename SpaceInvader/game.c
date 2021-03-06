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
    InitGameOver();
    InitVictory();
    InitPause();
    InitBackground();
    InitMoon();
    InitMars();
    InitShip();
    InitLife();
    InitBoss();
    InitLayout();
    InitBonus();
    InitBossBullet();
    ShipShootList = NULL;
    InvaderList = NULL;

    right = false;
    left = false;
    shoot = false;

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
}

void LoadGame()
{
    Pause->Load();
    Victory->Load();
    Background->Load();
    GameOver->Load();
    Moon->Load();
    Mars->Load();
    Ship->Load();
    Life->Load();
    Boss->Load();
    Layout->Load();
    Bonus->Load();
    BossBullet->Load();
}

void DestroyGame()
{
    Life->Destroy();
    Ship->Destroy();
    Mars->Destroy();
    Moon->Destroy();
    GameOver->Destroy();
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
    BossBullet->Destroy();
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
                    if (Bonus->IsAlive == 0 && Ship->Shield != 1 && random_number(0, 10) == 5)
                        {
                            Bonus->IsAlive=1;
                            Bonus->Position.x = InvaderListTemp->Current->Position.x + 35;
                            Bonus->Position.y = InvaderListTemp->Current->Position.y + 35;
                        }
                    InvaderListTemp->Current->IsAlive=1;
                    ShipShootList = DeleteElementBulletList(ShipShootList, ShotList->Current);
                }
                InvaderListTemp = InvaderListTemp->Next;
                j++;
            }
            if ( Boss->IsAlive == 0 && collision(ShotList->Current->Position, Boss->Position) == 1){
                if (Bonus->IsAlive == 0 && Ship->Shield != 1 && random_number(0, 5) == 2)
                        {
                            Bonus->IsAlive=1;
                            Bonus->Position.x = Boss->Position.x + 110;
                            Bonus->Position.y = Boss->Position.y + 110;
                        }
                Boss->IsAlive=1;
                ShipShootList = DeleteElementBulletList(ShipShootList, ShotList->Current);
            }
        }else{
            if ( Ship->IsAlive == 0 && collision(ShotList->Current->Position, Ship->Position) == 1){
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
    UpdateCollision();
    if (Boss->Initialisation <= 0 && InvaderList == NULL)
    {
        isBoss = true;
        Boss->IsAlive = 0;
        Boss->Initialisation = 1;
    }
    Layout->Update();
    if (Ship->IsAlive < 10)
    {
        Ship->Update();
    }
    Bullets *ShotListUp = ShipShootList;
    while (ShotListUp != NULL)
    {
        if( ShotListUp->Current->Position.y < 20 || ShotListUp->Current->Position.y > SCREEN_HEIGHT-20){
            ShipShootList = DeleteElementBulletList(ShipShootList, ShotListUp->Current);
        }else{
            ShotListUp->Current->Update(ShotListUp->Current);
        }
        ShotListUp = ShotListUp->Next;
    }
    Invaders *InvaderListTempUp = InvaderList;
    while (InvaderListTempUp != NULL)
    {
        if(InvaderListTempUp->Current->IsAlive>=6){
            InvaderList = DeleteElementInvaderList(InvaderList, InvaderListTempUp->Current);
        }else{
            InvaderListTempUp->Current->Update(InvaderListTempUp->Current);
        }
        InvaderListTempUp->Current->Dead(InvaderListTempUp->Current);
        InvaderListTempUp = InvaderListTempUp->Next;
    }
    Life->Update();
    if (Boss->IsAlive <10)
    {
        Boss->Update();
    }
    if (Bonus->IsAlive > 0)
    {
        Bonus->Update();
    }
    BossBullet->Update();
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
    if (BossBullet->IsAlive > 0)
    {
        BossBullet->Draw();
    }
    Bullets *ShotListDraw = ShipShootList;
    while (ShotListDraw != NULL)
    {

        ShotListDraw->Current->Draw(ShotListDraw->Current);
        ShotListDraw = ShotListDraw->Next;
    }
    Invaders *InvaderListTempDraw = InvaderList;
    while (InvaderListTempDraw != NULL)
    {
        InvaderListTempDraw->Current->Draw(InvaderListTempDraw->Current);
        InvaderListTempDraw = InvaderListTempDraw->Next;
    }
    Life->Draw();
    if (Boss->IsAlive <10){
        Boss->Draw();
    }
    if (paused == true)
    {
        Pause->Draw();
    }
    if (lose == true)
    {
        GameOver->Draw();
    }
    if (victory == true)
    {
        Victory->Draw();
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


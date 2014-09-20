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



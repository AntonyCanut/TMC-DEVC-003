//
//  SpriteFunc.h
//  SpaceInvader
//
//  Created by Antony Canut on 22/07/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#ifndef SpaceInvader_SpriteFunc_h
#define SpaceInvader_SpriteFunc_h

typedef enum {false=(int)0, true=(int)1} bool;

// Préparation des type def, on pourrait faire directement mais visuellement c'est mieux
// La piscine c'est finit, ce qui est dégueulasse va disparaitre merci
typedef void (*Init)(void);
typedef void (*LoadContent)(void);
typedef void (*UnLoadContent)(void);
typedef void (*Draw)(void);
typedef void (*Update)(void);
typedef void (*UpdateInput)(void);
typedef void (*Shot)(void);
typedef void (*Dead)(void);
typedef void (*Destroy)(void);

// ##########################
// #       JOUEUR
// ##########################
struct ShipStruct {
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Life;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    UpdateInput UpdateInput;
    Shot Shot;
    Dead Dead;
    Destroy Destroy;
};

struct ShipShootStruct {
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Dead Dead;
    Destroy Destroy;
};

// ##########################
// #       END JOUEUR
// ##########################

struct InvaderStruct {
    SDL_Rect Position;
    SDL_Rect Part;
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Shot Shot;
    Dead Dead;
    Destroy Destroy;
};

struct Bullet {
    SDL_Rect Position;
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
};

struct MoonStruct {
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Dead Dead;
    Destroy Destroy;
};

struct BackgroundStruct {
    SDL_Rect PositionStar;
    SDL_Rect PositionEarth;
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
};

struct MarsStruct {
    SDL_Rect Position;
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
};

#endif

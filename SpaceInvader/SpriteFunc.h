//
//  SpriteFunc.h
//  SpaceInvader
//
//  Created by Antony Canut on 22/07/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#ifndef SpaceInvader_SpriteFunc_h
#define SpaceInvader_SpriteFunc_h

typedef enum {false=0, true=1} bool;


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
typedef struct ShipStruct;
struct ShipStruct {
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprite
    int IsAlive;
    int Speed;
    Init InitShip;
    LoadContent LoadContentShip;
    UnLoadContent UnLoadShip;
    Draw DrawShip;
    Update UpdateShip;
    UpdateInput UpdateInputShip;
    Shot ShotShip;
    Dead DeadShip;
};

typedef struct ShipShootStruct;
struct ShipShootStruct {
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprite
    int IsAlive;
    int Speed;
    Init InitShipShoot;
    LoadContent LoadContentShipShoot;
    UnLoadContent UnLoadShipShoot;
    Draw DrawShipShoot;
    Update UpdateShipShoot;
    Dead DeadShipShoot;
};
// ##########################
// #       END JOUEUR
// ##########################


typedef struct InvaderShipStruct;
struct InvaderShipStruct {
    SDL_Rect Position;
    SDL_Rect Part;
    int IsAlive;
    int Speed;
    Init InitInvaderShip;
    LoadContent LoadContentInvaderShip;
    UnLoadContent UnLoadInvaderShip;
    Draw DrawInvaderShip;
    Update UpdateInvaderShip;
    Shot ShotInvaderShip;
    Dead DeadInvaderShip;
};

typedef struct Bullet;
struct Bullet {
    SDL_Rect Position;
    int IsAlive;
    int Speed;
    Init Init;
    LoadContent LoadContent;
    UnLoadContent UnLoadContent;
    Draw Draw;
    Update Update;
};

typedef struct MoonStruct;
struct MoonStruct {
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprite
    int IsAlive;
    int Speed;
    Init InitMoon;
    LoadContent LoadContentMoon;
    UnLoadContent UnLoadContentMoon;
    Draw DrawMoon;
    Update UpdateMoon;
    Dead DeadMoon;
    Destroy DestroyMoon;
};

typedef struct BackgroundStruct;
struct BackgroundStruct {
    SDL_Rect PositionStar;
    SDL_Rect PositionEarth;
    int IsAlive;
    int Speed;
    Init Init;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
};

typedef struct MarsStruct;
struct MarsStruct {
    SDL_Rect Position;
    int IsAlive;
    int Speed;
    Init InitMars;
    LoadContent LoadContentMars;
    UnLoadContent UnLoadContentMars;
    Draw DrawMars;
    Update UpdateMars;
    Destroy DestroyMars;
};

#endif

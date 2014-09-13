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
typedef void (*Deselected)(void);
typedef void (*Selected)(void);

typedef struct sInvaderStruct InvaderStruct;

typedef void (*LoadContent2)(InvaderStruct *Invader);
typedef void (*UnLoadContent2)(InvaderStruct *Invader);
typedef void (*Draw2)(InvaderStruct *Invader);
typedef void (*Update2)(InvaderStruct *Invader);
typedef void (*Shot2)(InvaderStruct *Invader);
typedef void (*Dead2)(InvaderStruct *Invader);
typedef void (*Destroy2)(InvaderStruct *Invader);

// ##########################
// #       JOUEUR
// ##########################
struct ShipStruct {
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Life;
    int Speed;
    int Shield;
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
struct LifeStruct {
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
};


// ##########################
// #       END JOUEUR
// ##########################

typedef struct sInvaderStruct {
    SDL_Rect Position;
    SDL_Rect Part;
    int IsAlive;
    int Speed;
    SDL_Texture *Texture;
    LoadContent2 Load;
    UnLoadContent2 UnLoad;
    Draw2 Draw;
    Update2 Update;
    Shot2 Shot;
    Dead2 Dead;
    Destroy2 Destroy;
} InvaderStruct;

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

struct TitreStruct {
    SDL_Rect Titre;
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
};

struct PlayStruct {
    SDL_Rect Play;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
    Selected Selected;
    Deselected Deselected;
};

struct QuitStruct {
    SDL_Rect Quit;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
    Selected Selected;
    Deselected Deselected;
};

struct MenuStruct {
    SDL_Rect PositionStarMenu;
    int IsAlive;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    UpdateInput UpdateInput;
    Destroy Destroy;
};

#endif

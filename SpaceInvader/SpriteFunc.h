//
//  SpriteFunc.h
//  SpaceInvader
//
//  Created by Antony Canut on 22/07/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#ifndef SpaceInvader_SpriteFunc_h
#define SpaceInvader_SpriteFunc_h

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

// La structure d'un sprite agit comme une classe en langage objet : Attributs et fonctions
// Une structure Joueur, Ennemi, et Tir
typedef struct Player;
struct Player {
    SDL_Rect Position;
    int IsAlive;
    int Speed;
    // Cet endroit doit contenir une liste de "Bullet", et donc de sprite nommé Bullet
    // (je me souviens plus encore comment on fait une liste donc wait le temps que ça revienne)
    Init Init;
    LoadContent LoadContent;
    UnLoadContent UnLoadContent;
    Draw Draw;
    Update Update;
    UpdateInput UpdateInput;
    Shot Shot;
    Dead Dead;
};

typedef struct Ennemi;
struct Ennemi {
    SDL_Rect Position;
    int IsAlive;
    int Speed;
    // Cet endroit doit contenir une liste de "Bullet", et donc de sprite nommé Bullet
    // (je me souviens plus encore comment on fait une liste donc wait le temps que ça revienne)
    Init Init;
    LoadContent LoadContent;
    UnLoadContent UnLoadContent;
    Draw Draw;
    Update Update;
    Shot Shot;
    Dead Dead;
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
    Init InitBackground;
    LoadContent LoadContentBackground;
    UnLoadContent UnLoadContentBackground;
    Draw DrawBackground;
    Update UpdateBackground;
    Destroy DestroyBackground;
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

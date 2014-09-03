//
//  SpriteFunc.h
//  SpaceInvader
//
//  Created by Antony Canut on 22/07/14.
//  Copyright (c) 2014 Antony Canut. All rights reserved.
//

#ifndef SpaceInvader_SpriteFunc_h
#define SpaceInvader_SpriteFunc_h

typedef struct Coordonnees Coordonnees;
struct Coordonnees {
    int x;
    int y;
    int w;
    int h;
};

// Préparation des type def, on pourrait faire directement mais visuellement c'est mieux
// La piscine c'est finit, ce qui est dégueulasse va disparaitre merci
typedef void (*Init)(Coordonnees position);
typedef void (*LoadContent)(SDL_Surface surface);
typedef void (*UnLoadContent)(void);
typedef void (*Draw)(void);
typedef void (*Update)(void);
typedef void (*UpdateInput)(void);
typedef void (*Shot)(void);
typedef void (*Dead)(void);

// La structure d'un sprite agit comme une classe en langage objet : Attributs et fonctions
// Une structure Joueur, Ennemi, et Tir
typedef struct Player;
struct Player {
    Coordonnees Position;
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
    Coordonnees Position;
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
    Coordonnees Position;
    int IsAlive;
    int Speed;
    Init Init;
    LoadContent LoadContent;
    UnLoadContent UnLoadContent;
    Draw Draw;
    Update Update;
};

typedef struct Moon;
struct Moon {
    Coordonnees Position;
    int IsAlive;
    int Speed;
    Init Init;
    LoadContent LoadContent;
    UnLoadContent UnLoadContent;
    Draw Draw;
    Update Update;
    Dead Dead;
};

#endif

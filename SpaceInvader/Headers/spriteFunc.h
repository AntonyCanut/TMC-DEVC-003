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

typedef struct sBullet BulletStruct;

typedef void (*LoadContent3)(BulletStruct *Bullet);
typedef void (*UnLoadContent3)(BulletStruct *Bullet);
typedef void (*Draw3)(BulletStruct *Bullet);
typedef void (*Update3)(BulletStruct *Bullet);
typedef void (*Shot3)(BulletStruct *Bullet);
typedef void (*Dead3)(BulletStruct *Bullet);
typedef void (*Destroy3)(BulletStruct *Bullet);


// ##########################
// #       JOUEUR
// ##########################
typedef struct sShipStruct {
    SDL_Texture *Texture;
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
} ShipStruct;

struct sBullet {
    SDL_Texture *Texture;
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    int Direction;
    int Sprite;
    Uint32 ShootTime;
    LoadContent3 Load;
    UnLoadContent3 UnLoad;
    Draw3 Draw;
    Update3 Update;
    Dead3 Dead;
    Destroy3 Destroy;
};

typedef struct sLifeStruct {
    SDL_Texture *Texture;
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
} LifeStruct;

typedef struct sBonusStruct {
    SDL_Texture *Texture;
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
} BonusStruct;

// ##########################
// #       END JOUEUR
// ##########################

// ##########################
// #       BOSS
// ##########################

typedef struct sBossStruct {
    SDL_Texture *Texture;
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Life;
    int Speed;
    int Direction;
    int Shoot;
    int Initialisation;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Shot Shot;
    Dead Dead;
    Destroy Destroy;
} BossStruct;

typedef struct sBossBulletStruct {
    SDL_Texture *Texture;
    SDL_Rect PositionHead;
    SDL_Rect PositionBody;
    SDL_Rect PositionTail;
    SDL_Rect PartHead;
    SDL_Rect PartBody;
    SDL_Rect PartTail;// gestion des sprites
    int IsAlive;
    int Speed;
    Uint32 ShootTime;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
} BossBulletStruct;

typedef struct sBossLazer {
    SDL_Texture *Texture;
    SDL_Rect Position;
    SDL_Rect Part;// gestion des sprites
    int IsAlive;
    int Speed;
    int Direction;
    LoadContent3 Load;
    UnLoadContent3 UnLoad;
    Draw3 Draw;
    Update3 Update;
    Dead3 Dead;
    Destroy3 Destroy;
} BossLazerStruct;

// ##########################
// #       END BOSS
// ##########################


struct sInvaderStruct {
    SDL_Texture *Texture;
    SDL_Rect Position;
    SDL_Rect Part;
    int IsAlive;
    int Speed;
    int Sprite;
    LoadContent2 Load;
    UnLoadContent2 UnLoad;
    Draw2 Draw;
    Update2 Update;
    Shot2 Shot;
    Dead2 Dead;
    Destroy2 Destroy;
};

typedef struct sMoonStruct {
    SDL_Texture *Texture;
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
} MoonStruct;

typedef struct sBackgroundStruct {
    SDL_Texture *TextureStar;
    SDL_Texture *TextureEarth;
    SDL_Rect PositionStar;
    SDL_Rect PositionEarth;
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
} BackgroundStruct;

typedef struct sMarsStruct {
    SDL_Texture *Texture;
    SDL_Rect Position;
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
} MarsStruct;

typedef struct sLayoutStruct {
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
} LayoutStruct;

typedef struct sTitreStruct {
    SDL_Texture *Texture;
    SDL_Rect Titre;
    int IsAlive;
    int Speed;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    Destroy Destroy;
} TitreStruct;

typedef struct sPlayStruct {
    SDL_Texture *Texture;
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
} PlayStruct;

typedef struct sQuitStruct {
    SDL_Texture *Texture;
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
} QuitStruct;

typedef struct sMenuStruct {
    SDL_Texture *Texture;
    SDL_Rect PositionStarMenu;
    int IsAlive;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    UpdateInput UpdateInput;
    Destroy Destroy;
} MenuStruct;

typedef struct sPauseStruct {
    SDL_Texture *Texture;
    SDL_Rect PauseMenu;
    int IsAlive;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    UpdateInput UpdateInput;
    Destroy Destroy;
} PauseStruct;

typedef struct sGameOverStruct {
    SDL_Texture *Texture;
    SDL_Rect GameOverText;
    int IsAlive;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    UpdateInput UpdateInput;
    Destroy Destroy;
} GameOverStruct;

typedef struct sVictoryStruct {
    SDL_Texture *Texture;
    SDL_Rect VictoryText;
    int IsAlive;
    LoadContent Load;
    UnLoadContent UnLoad;
    Draw Draw;
    Update Update;
    UpdateInput UpdateInput;
    Destroy Destroy;
} VictoryStruct;

#endif

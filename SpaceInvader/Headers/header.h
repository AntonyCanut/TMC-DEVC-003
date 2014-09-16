/*
** header.h for HEADER
**
** Made by PIRE Camille
** Login   <pire_c@etna-alternance.net>
**
** Started on  Wed Feb 12 11:12:19 2014 PIRE Camille
** Last update Wed Mar 19 19:48:37 2014 camille pire
*/
#ifndef __HEADER_H__
# define __HEADER_H__

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

#include <stdio.h>
<<<<<<< HEAD:SpaceInvader/Headers/header.h
// #include <SDL2.framework/Headers/SDL.h>
// #include <SDL2_image.framework/Headers/SDL_image.h>
// #include <SDL2_mixer.framework/Headers/SDL_mixer.h>
#include "/usr/local/include/SDL2/SDL.h"
#include "/usr/local/include/SDL2/SDL_image.h"
#include "/usr/local/include/SDL2/SDL_mixer.h"
#include "spriteFunc.h"
=======
#include <SDL2.framework/Headers/SDL.h>
#include <SDL2_image.framework/Headers/SDL_image.h>
#include <SDL2_mixer.framework/Headers/SDL_mixer.h>
// #include "/usr/local/include/SDL2/SDL.h"
// #include "/usr/local/include/SDL2/SDL_image.h"
// #include "/usr/local/include/SDL2/SDL_mixer.h"
#include "spritefunc.h"
>>>>>>> FETCH_HEAD:SpaceInvader/header.h

SDL_Window *Window;
SDL_Renderer *Renderer;
SDL_Event e;
Uint32 time;

Mix_Music *musiqueBackground; 
Mix_Chunk *sonBackground; //Pointeur musique background
Mix_Chunk *son2;

bool *right;
bool *left;
bool *shoot;
bool *play;
bool *quit;
bool *menu;
bool *isUp;

<<<<<<< HEAD:SpaceInvader/Headers/header.h
MoonStruct *Moon;
BackgroundStruct *Background;
MenuStruct *Menu;
TitreStruct *Titre;
PlayStruct *Play;
QuitStruct *Quit;
MarsStruct *Mars;
ShipStruct *Ship;
=======
struct MoonStruct *Moon;
SDL_Texture *tMoon;

struct BackgroundStruct *Background;
SDL_Texture *tStar;
SDL_Texture *tEarth;

struct MenuStruct *Menu;
SDL_Texture *tStarMenu;

struct TitreStruct *Titre;
SDL_Texture *tTitre;

struct PlayStruct *Play;
SDL_Texture *tPlay;

struct QuitStruct *Quit;
SDL_Texture *tQuit;

struct MarsStruct *Mars;
SDL_Texture *tMars;

struct ShipStruct *Ship;
SDL_Texture *tShip;

>>>>>>> FETCH_HEAD:SpaceInvader/header.h
BulletStruct *MyBullet;
InvaderStruct *MyInvader;
InvaderStruct *MyInvader2;
LifeStruct *Life;

void InitTitre();
void InitPlay();
void InitQuit();
void InitMenu();
void InitBackground();
void InitMoon();
void InitMars();
void InitShip();
<<<<<<< HEAD:SpaceInvader/Headers/header.h
BulletStruct *InitBullet(SDL_Rect *Canon, int direction);
void InitLife();
=======

BulletStruct *InitBullet(SDL_Rect *Canon, int direction);


void InitLife();

>>>>>>> FETCH_HEAD:SpaceInvader/header.h
InvaderStruct *InitInvader(int x);


char collision(SDL_Rect, SDL_Rect);

#endif
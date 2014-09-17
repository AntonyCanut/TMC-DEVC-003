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
 #include <SDL2.framework/Headers/SDL.h>
#include <SDL2_image.framework/Headers/SDL_image.h>
 #include <SDL2_mixer.framework/Headers/SDL_mixer.h>
//#include "/usr/local/include/SDL2/SDL.h"
//#include "/usr/local/include/SDL2/SDL_image.h"
//#include "/usr/local/include/SDL2/SDL_mixer.h"
#include "spriteFunc.h"

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
bool *pause;

PauseStruct *Pause;
MoonStruct *Moon;
BackgroundStruct *Background;
MenuStruct *Menu;
TitreStruct *Titre;
PlayStruct *Play;
QuitStruct *Quit;
MarsStruct *Mars;
ShipStruct *Ship;
BulletStruct *MyBullet;
InvaderStruct *MyInvader;
InvaderStruct *MyInvader2;
LifeStruct *Life;

void InitPause();
void InitTitre();
void InitPlay();
void InitQuit();
void InitMenu();
void InitBackground();
void InitMoon();
void InitMars();
void InitShip();
BulletStruct *InitBullet(SDL_Rect *Canon, int direction);
void InitLife();
InvaderStruct *InitInvader(int x);


char collision(SDL_Rect, SDL_Rect);

#endif

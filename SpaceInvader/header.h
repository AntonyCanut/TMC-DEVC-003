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
// #include "/usr/local/include/SDL2/SDL.h"
// #include "/usr/local/include/SDL2/SDL_image.h"
// #include "/usr/local/include/SDL2/SDL_mixer.h"
#include "SpriteFunc.h"

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


struct MoonStruct *Moon;
SDL_Texture *tMoon;

struct BackgroundStruct *Background;
SDL_Texture *tStar;
SDL_Texture *tEarth;

struct MarsStruct *Mars;
SDL_Texture *tMars;

struct ShipStruct *Ship;
SDL_Texture *tShip;

struct ShipShootStruct *ShipShoot;
SDL_Texture *tShipShoot;

struct InvaderStruct *Invader;
SDL_Texture *tInvader;

void InitBackground();
void InitMoon();
void InitMars();
void InitShip();
void InitShipShoot();
void InitInvader();

#endif

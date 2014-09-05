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
#include "SpriteFunc.h"

SDL_Window *Window;
SDL_Renderer *Renderer;
SDL_Event e;
Uint32 time;

bool *right;
bool *left;
bool *shoot;

/*
*
*       Moon
*
*/
struct MoonStruct *Moon;
SDL_Texture *tMoon;

void LoadContentMoon();
void UnLoadMoon();
void DrawMoon();
void UpdateMoon();
void DeadMoon();
void InitMoon();
void DestroyMoon();

/*
*
*       Background
*
*/
struct BackgroundStruct *Background;
SDL_Texture *tStar;
SDL_Texture *tEarth;

void LoadContentBackground();
void UnLoadBackground();
void DrawBackground();
void UpdateBackground();
void InitBackground();
void DestroyBackground();

/*
*
*       Mars
*
*/
struct MarsStruct *Mars;
SDL_Texture *tMars;

void LoadContentMars();
void UnLoadMars();
void DrawMars();
void UpdateMars();
void InitMars();
void DestroyMars();


/*
*       SpaceShip
*
*/
struct ShipStruct *Ship;
SDL_Texture *tShip;

void LoadContentShip();
void UnLoadShip();
void DrawShip();
void UpdateShip();
void UpdateInputShip();
void ShotShip();
void DeadShip();
void InitShip();
void DestroyShip();

/*
*       ShipShoot
*
*/
struct ShipShootStruct *ShipShoot;
SDL_Texture *tShipShoot;

void LoadContentShipShoot();
void UnLoadShipShoot();
void DrawShipShoot();
void UpdateShipShoot();
void DeadShipShoot();
void InitShipShoot();
void DestroyShipShoot();

/*
*
*       InvaderShip
*
*/
struct InvaderShipStruct *InvaderShip;
SDL_Texture *tInvaderShip;

void LoadContentInvaderShip();
void UnLoadInvaderShip();
void DrawInvaderShip();
void UpdateInvaderShip();
void InitInvaderShip();
void DestroyInvaderShip();


#endif

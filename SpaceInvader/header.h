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
#include "SpriteFunc.h"

SDL_Window *Window;
SDL_Renderer *Renderer;

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
struct SpaceShipStruct *SpaceShip;
SDL_Texture *tSpaceShip;

void LoadContentShip();
void UnLoadShip();
void DrawShip();
void UpdateShip();
void InitShip();
void DestroyShip();

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

>>>>>>> Debut du vaisseau invader

#endif

/*
** header.h for HEADER
**
** Made by PIRE Camille
** Login   <pire_c@etna-alternance.net>
**
** Started on  Wed Feb 12 11:12:19 2014 PIRE Camille
** Last update Wed Mar 19 19:48:37 2014 camille pire
*/
#include "Headers/header.h"

int collision(SDL_Rect a, SDL_Rect b)
    {
    int collisionX = 0;
    int collisionY = 0;
     
    /* x */
    if ( ((a.x+a.w)>b.x ) && (a.x<(b.x+b.w)) ) {
        collisionX = 1;
    }
     
    /* y */
    if ( ((a.y+a.h)>b.y ) && (a.y<(b.y+b.h)) )
       {
        collisionY = 1;
       }
     
    /* si collision */
    if ( (collisionX == 1) && (collisionY == 1) )
       {
        return 1;
       }
    return 0;              
         
}

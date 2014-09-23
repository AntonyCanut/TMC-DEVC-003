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

int random_number(int min_num, int max_num)
{
    int result=0,low_num=0,hi_num=0;
    if(min_num<max_num)
    {
        low_num=min_num;
        hi_num=max_num+1; // this is done to include max_num in output.
    }else{
        low_num=max_num+1;// this is done to include max_num in output.
        hi_num=min_num;
    }
    srand(time(NULL));
    result = (rand()%(hi_num-low_num))+low_num;
    return result;
}

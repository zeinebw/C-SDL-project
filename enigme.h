#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "SDL/SDL_ttf.h"
#include <time.h>

typedef struct{
SDL_Surface * fond;
FILE * f; 
SDL_Rect posquest,posr1,posr2,posr3,posimageo,posimagen;
SDL_Surface imageo;
SDL_Surface imagen;
SDL_Rect pr1;
SDL_Rect pr2;
SDL_Rect pr3;
SDL_Rect pv;
SDL_Rect pquest;
SDL_Rect positionimageo;
SDL_Rect positionimagen;
  char quest[400];
  char r1[50];
  char r2[50];
  char r3[50];
  char v[50];
}enigme;


void initEnigme (enigme *e);
enigmeg genererEnigme(enigme e);
void afficherEnigme(enigme e, SDL_Surface *screen);
int random();
int resolutionEnigme(enigme e, SDL_Event event);
#endif 

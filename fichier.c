#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme.h"
#include <time.h>

enigme initEnigme (){
  enigme e;
  e.f = fopen("enigme.txt", "r");
 e.back = IMG_Load("lettre.gif");
 return e;
}


/*void showEnigme (enigmefic ed, SDL_Surface *screen, enigme e){
  typedef struct{
    SDL_Rect back;
    SDL_Rect quest;
    SDL_Rect q1;
    SDL_Rect q2;
    SDL_Rect q3;
  }posenigme;
posenigme pe;
SDL_Surface *questsurf;
SDL_Surface *q1surf;
SDL_Surface *q2surf;
SDL_Surface *q3surf;
TTF_Font * police;
SDL_Color red = {255,0,0};
SDL_Color white = {0,0,0};
if (TTF_Init() < 0) {
  printf("error\n");
}else{
police = TTF_OpenFont("res/Bebas-Regular.ttf", 24);
if (police == NULL) {
  printf("error in  open font enigma\n");
}else{
  questsurf = TTF_RenderText_Solid(police, ed.quest, white);
  c1surf = TTF_RenderText_Solid(police, ed.c1, red);
  c2surf = TTF_RenderText_Solid(police, ed.c2, red);
  c3surf = TTF_RenderText_Solid(police, ed.c3, red);
  pe.back.x = 200;
  pe.back.y = 100;
  pe.back.h = questsurf->h;
  pe.back.w = questsurf->w;
  pe.quest.x = 240;
  pe.quest.y = 130;
  pe.c1.x= 400;
  pe.c1.y= 200;
  pe.c2.x= 550;
  pe.c2.y= 200;
  pe.c3.x= 700;
  pe.c3.y= 200;
  SDL_BlitSurface(e.back, NULL, screen, &pe.back);
  SDL_BlitSurface(questsurf, NULL, screen, &pe.quest);
  SDL_BlitSurface(c1surf, NULL, screen, &pe.c1);
  SDL_BlitSurface(c2surf, NULL, screen, &pe.c2);
  SDL_BlitSurface(c3surf, NULL, screen, &pe.c3);
  TTF_CloseFont(police);
  TTF_Quit();
    }
    }
 }
*/

  int randomize(){
  int pos;
  srand(time(NULL));
  pos=rand()%(9-0+1)+0;
  return pos;
    }



enigmefic generateEnigme(enigme e){
  enigmefic ed [10];
  enigmefic edata;
  int i;
  int pos = randomize();
  for (i = 0; i < 10; i++) {
     fgets(ed[i].quest, 400, e.f);
    fscanf(e.f,"a.%s b.%s c.%s v.%s\n",ed[i].q1, ed[i].q2, ed[i].q3, ed[i].v);
  }   
  strcpy(edata.quest,ed[pos].quest);
  strcpy (edata.q1 ,ed[pos].q1);
      strcpy(edata.q2 ,ed[pos].q2);
        strcpy(edata.q3 ,ed[pos].q3);
          strcpy(edata.v ,ed[pos].v);
  return edata;
    }



int resolutionEnigme(enigmefic ed, SDL_Event event){
  switch(event.type){
         case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_1){
             if (strcmp (ed.q1, ed.v) == 0) {
               return 1;
             }
            }else{
              if(event.key.keysym.sym == SDLK_2){
                if (strcmp (ed.q2, ed.v) == 0) {
                  return 1;
                }
             }else{
               if(event.key.keysym.sym == SDLK_3){
                 if (strcmp (ed.q3, ed.v) == 0) {
                   return 1;
                 }
               }
             }
            }
    }
return 0;
}


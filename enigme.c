#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme.h"
#include <time.h>

int resolutionEnigme(enigmeg pe,enigme ed, SDL_Event event){
SDL_Surface *back = NULL, *imageo = NULL, *imagen = NULL; 
SDL_Rect positionimageo, positionimagen,positionclic;
imageo=IMG_Load("ouii.png");
imagen=IMG_Load("no.svg");
positionimageo.x=0;
positionimageo.y=0;
positionimagen.x=0;
positionimagen.y=0;
  switch(event.type){
case SDL_MOUSEBUTTONDOWN:
		{
		if (event.button.button ==SDL_BUTTON_LEFT)
		{
			positionclic.x=event.button.x;
			positionclic.y =event.button.y;
			if (event.button.x>e.pr1.x && event.button.x<e.pr1.x+e.pr1.w && event.button.y>e.pr1.y && event.button.y<e.pr1.y+e.pr1.h)
 { if(strcmp (e.r1, e.v) == 0) 		
			{
				SDL_BlitSurface(imageo,&e.fond,fond,&positionimageo); 
SDL_Flip(fond);
SDL_Delay(5000);
SDL_FreeSurface(imageo);
                                return 1;
                        }}
else if (event.button.x>e.pr2.x && event.button.x<e.pr2.x+e.pr2.w && event.button.y>e.pr2.y && event.button.y<e.pr2.y+e.pr2.h)
 { if(strcmp (e.r2, e.v) == 0) 		
			{
				SDL_BlitSurface(imageo,&e.fond,fond,&positionimageo);
SDL_Flip(fond);
SDL_Delay(5000);
SDL_FreeSurface(imageo);
                                return 1;
                        }}
else if (event.button.x>e.pr3.x && event.button.x<e.pr3.x+e.pr3.w && event.button.y>e.pr3.y && event.button.y<e.pr3.y+e.pr3.h)
 { if(strcmp (e.r3, e.v) == 0) 		
			{
				SDL_BlitSurface(imageo,&e.fond,fond,&positionimageo);
SDL_Flip(fond);
SDL_Delay(5000);
SDL_FreeSurface(imageo);
                                return 1;
                        }}
}
}
}
SDL_BlitSurface(imagen,&e.fond,fond,&positionimagen);
SDL_Flip(fond);
SDL_Delay(5000);
SDL_FreeSurface(imagen);
return 0;
}

void initEnigme (enigme *e){
  e->f = fopen("enigme.txt", "r");
 e->fond = IMG_Load("lettre.gif");
e->pr1.x=0;
e->pr2.x=0;
e->pr3.x=0;
e->pv.x=0;
e->pquest.x=0;
e->positionimageo.x=0;
e->positionimagen.x=0;
e->pr1.y=0;
e->pr2.y=0;
e->pr3.y=0;
e->pv.y=0;
e->pquest.y=0;
e->positionimageo.y=0;
e->positionimagen.y=0;
imageo=IMG_Load("ouii.png");
imagen=IMG_Load("no.svg");
}

int random()
   {
  int pos;
  srand(time(NULL));
  pos=rand()%(9-1+1)+0;
  return pos;
    }


enigme genererEnigme(enigme e){
  enigme e[10];
  int i;
  int pos = random();
  for (i = 0; i < 10; i++) {
   // fscanf(e.f,"*%d)%s",i,ed[i].quest);
    fgets(e[i].quest, 400, e.f);
    fscanf(e.f,"a.%s b.%s c.%s v.%s\n",e[i].r1, e[i].r2, e[i].r3, e[i].v);
  }   
  strcpy(e.quest,e[pos].quest);
  strcpy (e.r1 ,e[pos].r1);
  strcpy(e.r2 ,e[pos].r2);
  strcpy(e.r3 ,e[pos].r3);
  strcpy(e.v ,e[pos].v);
  return e;
    }








        

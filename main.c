#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme.h"
#include <time.h>
int main(void)
{ SDL_Surface *screen; SDL_Event event; int coeur=3; int i=0;
if (SDL_INIT_VIDEO!=0)
{
printf("ERROR:Unable to initialise SDL");
return 1;
}
screen=SDL_SetVideoMode(1029,795,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
enigme e;
enigme ee;
while ((coeur >0)&&(i==0))
{
initEnigme (&e);
ee=genererEnigme(e);
//afficherEnigme(ee,&screen,e);
i=resolutionEnigme(ee,event);
coeur--;
}
}

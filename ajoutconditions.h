//#ifndef AJOUTCONDITIONS_H_INCLUDED
//#define AJOUTCONDITIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct perso
{
	SDL_Surface *image2;
    	//SDL_Surface *textdT;
    	//SDL_Surface *pX ;
    	//SDL_Surface *cX ;	
	//SDL_Surface *temp_image2;
	SDL_Rect posPlayer;
   	int done ;
   	int right,left,sprint;
  	 int maxspeed;
   	double xVel,yVel,canJump;
   	double v_jump;
   	double gravity ;
	int acc;
	int ianim,ianim_c,timer,maxtimer;
	char playerX[50];
	char animchar[50];
	TTF_Font *textF ;
}perso;

typedef struct camera
{
	SDL_Rect posdT;
	SDL_Rect pXR;
	SDL_Rect cXR;
	double FPS;
	int dT;
   double FrmStrt,FrmEnd;
	char DT[50];
	SDL_Rect cam;
	char camX[50];
}camera;
void ajoutconditions (int vie,int coeur,int niveau,int score,SDL_Surface *ecran);
void initialiserperso(perso *p);
void initialiserpersos(perso *p);
void initialiserpersof(perso *p);
void afficher2(perso p,SDL_Surface *screen,SDL_Surface *image,camera c);
void deplacer_personnage(perso *p);
void annimation(perso *p);
void annimation2(perso *p);
void afficher(perso p,SDL_Surface *screen,SDL_Surface *image,camera c);
 void jump(perso *p);
void ajoutpersonnage (perso *p);


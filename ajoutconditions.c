#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
void ajoutconditions (int vie,int coeur,int niveau,int score,SDL_Surface *ecran)
{int etat;
if ((vie==0)&&(coeur==0))
etat=2;
SDL_Surface *imageg = NULL, *imagescore = NULL, *imageniveau = NULL;
SDL_Rect positionimageg, positionimagescore, positionimageniveau, positionFond;
positionimagescore.x=0;
positionimagescore.y=0;
positionimageniveau.x=0;
positionimageniveau.y=0;
positionimageg.x=0;
positionimageg.y=0;
if (etat==2)
{
imageg = IMG_Load("gameover.png");
SDL_BlitSurface(imageg,&positionFond,ecran,&positionimageg);
TTF_Init();
SDL_Color red={0,0,255};
TTF_Font* police=NULL;
police=TTF_OpenFont("leadcoat.ttf",28);
imagescore=TTF_RenderText_Solid(police,"score",red);
imageniveau=TTF_RenderText_Solid(police,"niveau",red);
TTF_CloseFont(police);
TTF_Quit();
}
}

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


/*void initialiserperso2(perso *p)
{
	p->image2 = IMG_Load("wegf.png");
   	p->posPlayer.x=70;
   	p->posPlayer.y=150;
   	p->posPlayer.w=1200;
   	p->posPlayer.h=600;
   	p->done = 1;
   	p->maxspeed=5;
   	p->canJump=1;
   	p->v_jump = -7;
   	p->gravity = 0.2;
   	p->acc=0;
   	p->ianim=0;
   	p->ianim_c=1;
   	p->timer=0;
	p->maxtimer=4;
	p->textF = TTF_OpenFont("bebas.ttf", 20);
}
void afficher2(perso p,SDL_Surface *screen,SDL_Surface *image,camera c)
{
	SDL_BlitSurface(image,&c.cam,screen,NULL);
	SDL_BlitSurface(p.image2,NULL,screen,&p.posPlayer);
	//SDL_BlitSurface(p.textdT,NULL,screen,&p.posdT);
	//SDL_BlitSurface(p.pX,NULL,screen,&p.pXR);
	//SDL_BlitSurface(p.cX,NULL,screen,&p.cXR);
}
void deplacer_personnage(perso *p)
{
	
//x movement
	if(p->right==1) p->xVel+=0.3;
	if(p->left==1) p->xVel-=0.3;
	if(p->right ==0 && p->xVel>0.2) p->xVel-=0.1;
	if(p->left ==0 && p->xVel<-0.2) p->xVel+=0.1;

	if(p->right==0 && p->left ==0 && p->xVel>=-0.2 && p->xVel<0.2) p->xVel=0; //STOP threshhold

	//speed control
	if(p->sprint==1) p->maxspeed = 9;
	if(p->sprint==0) p->maxspeed = 5;

	p->posPlayer.x+=p->xVel;


	p->posPlayer.y+=p->yVel;
	p->yVel += p->gravity*2;
	

	if(p->posPlayer.y>400) {p->yVel=0;p->canJump=1;}
	if(p->posPlayer.y<400) p->canJump=0;
	//smoothing
	//if(right==0 && xVel>0.2) xVel-=0.02;
	//if(left==0 && xVel<-0.2) xVel+=0.02;
	//if(left==0 && xVel>-0.1 && xVel<0) xVel=0;
	//limit vel

	if(p->xVel>p->maxspeed) p->xVel=p->maxspeed;
	if(p->xVel<-p->maxspeed) p->xVel=-p->maxspeed;
	
}

void annimation(perso *p)
{
	
	//animation
	p->timer++;
	if( p->timer>p->maxtimer  && p->canJump==1 )
	{
		if(p->right==1)
		{
		sprintf(p->animchar,"run/right/run%d.png",p->ianim_c);
		p->image2=IMG_Load(p->animchar);
		p->ianim_c++;
		if(p->ianim_c>8) p->ianim_c=1;
		p->timer=0;
		}
		if(p->left==1)
		{
		sprintf(p->animchar,"run/left/run%d.png",p->ianim_c);
		p->image2=IMG_Load(p->animchar);
		p->ianim_c++;
		if(p->ianim_c>8) p->ianim_c=1;
		p->timer=0;
		}
	}

	if(p->right==0 && p->left == 0) p->image2=IMG_Load("wegf.png");
	if(p->canJump==0 && p->xVel>=0) p->image2=IMG_Load("jump.png");
         if(p->canJump==0 && p->xVel<0) p->image2=IMG_Load("jump2.png");
	if(p->canJump==0 && p->xVel>=0 && p->yVel>0) p->image2=IMG_Load("fall.png");
	if(p->canJump==0 && p->xVel<0 && p->yVel>0) p->image2=IMG_Load("fall2.png");
}


void afficher(perso p,SDL_Surface *screen,SDL_Surface *image,camera c)
{
	SDL_BlitSurface(image,&c.cam,screen,NULL);
	SDL_BlitSurface(p.image2,NULL,screen,&p.posPlayer);
	//SDL_BlitSurface(p.textdT,NULL,screen,&p.posdT);
	//SDL_BlitSurface(p.pX,NULL,screen,&p.pXR);
	//SDL_BlitSurface(p.cX,NULL,screen,&p.cXR);


}

//jump
   void jump(perso *p)
	{
	if (p->canJump==1) p->yVel=p->v_jump;
	}

camera scrolling (camera c,perso *p,SDL_Surface *screen)
{
	

	if(p->posPlayer.x>700 && -c.cam.x+c.cam.w>1210) {c.cam.x+=p->xVel;p->posPlayer.x=700;}
	if(p->posPlayer.x<300 && c.cam.x>10) {c.cam.x+=p->xVel;p->posPlayer.x=300;}
	if(p->posPlayer.x>1110 || p->posPlayer.x<0) p->xVel=0;

	c.dT=SDL_GetTicks()-c.FrmEnd;
	if (1000/c.FPS>c.dT)
	{
        SDL_Delay(1000/c.FPS-c.dT);
	}
	
	return c;

}*/
//ajoutpersonnage 
void ajoutpersonnage (perso *p)
{ int i;
for (i=1;i<3;i++)
{
if (i==1)
{
void initialiserpersos(perso *p)
{
	p->image2 = IMG_Load("wegf.png");
   	p->posPlayer.x=70;
   	p->posPlayer.y=150;
   	p->posPlayer.w=1200;
   	p->posPlayer.h=600;
   	p->done = 1;
   	p->maxspeed=5;
   	p->canJump=1;
   	p->v_jump = -7;
   	p->gravity = 0.2;
   	p->acc=0;
   	p->ianim=0;
   	p->ianim_c=1;
   	p->timer=0;
	p->maxtimer=4;
	p->textF = TTF_OpenFont("bebas.ttf", 20);
}
void afficher(perso p,SDL_Surface *screen,SDL_Surface *imageskander,camera c)
}
if (i==2)
{
void initialiserpersof(perso *p)
{
	p->image2 = IMG_Load("wegf.png");
   	p->posPlayer.x=70;
   	p->posPlayer.y=150;
   	p->posPlayer.w=1200;
   	p->posPlayer.h=600;
   	p->done = 1;
   	p->maxspeed=5;
   	p->canJump=1;
   	p->v_jump = -7;
   	p->gravity = 0.2;
   	p->acc=0;
   	p->ianim=0;
   	p->ianim_c=1;
   	p->timer=0;
	p->maxtimer=4;
	p->textF = TTF_OpenFont("bebas.ttf", 20);
}
void afficher(perso p,SDL_Surface *screen,SDL_Surface *imagefille,camera c)
}
deplacer_personnage(perso *p);
annimation(perso *p);
}
}

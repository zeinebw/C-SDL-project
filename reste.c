/*int resolutionEnigme(enigmeg ed, SDL_Event event){
  switch(event.type){
         case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_a){
             if (strcmp (ed.q1, ed.v) == 0) {
               return 1;
             }
            }else{
              if(event.key.keysym.sym == SDLK_b){
                if (strcmp (ed.q2, ed.v) == 0) {
                  return 1;
                }
             }else{
               if(event.key.keysym.sym == SDLK_c){
                 if (strcmp (ed.q3, ed.v) == 0) {
                   return 1;
                 }
               }
             }
            }
    }
return 0;
}*/


void afficherEnigme (enigmeg pe, SDL_Surface *screen,enigme e){
  typedef struct{
    SDL_Rect fond;
    SDL_Rect quest;
    SDL_Rect r1;
    SDL_Rect r2;
    SDL_Rect r3;
  }posenigme;
posenigme pe;
SDL_Surface *questsurf;
SDL_Surface *r1surf;
SDL_Surface *r2surf;
SDL_Surface *r3surf;
TTF_Font * police;
SDL_Color blue = {51,250,255};
SDL_Color white = {0,0,0};
if (TTF_Init() < 0) {
  printf("error\n");
}else{
police = TTF_OpenFont("leadcoat.ttf", 24);
if (police == NULL) {
  printf("error in  open font enigme\n");
}else{
  questsurf = TTF_RenderText_Solid(police, ed.quest, blue);
  r1surf = TTF_RenderText_Solid(police, ed.r1, white);
  r2surf = TTF_RenderText_Solid(police, ed.r2, white);
  r3surf = TTF_RenderText_Solid(police, ed.r3, white);
  pe.fond.x = 200;
  pe.fond.y = 100;
  pe.fond.h = questsurf->h;
  pe.fond.w = questsurf->w;
  pe.quest.x = 240;
  pe.quest.y = 130;
  pe.r1.x= 400;
  pe.r1.y= 200;
  pe.r2.x= 550;
  pe.r2.y= 200;
  pe.r3.x= 700;
  pe.r3.y= 200;
  SDL_BlitSurface(e.fond, NULL, screen, &pe.fond);
  SDL_BlitSurface(questsurf, NULL, screen, &pe.quest);
  SDL_BlitSurface(r1surf, NULL, screen, &pe.r1);
  SDL_BlitSurface(r2surf, NULL, screen, &pe.r2);
  SDL_BlitSurface(r3surf, NULL, screen, &pe.r3);
  TTF_CloseFont(police);
  TTF_Quit();
    }
    }
 } 

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
char question1[5]="ab";
char rep1[5]="1";
char rep2[5]="2";
char rep3[5]="3";
FILE *f=fopen("fichiert.txt","r");
fprintf (f,"%s",question1);
fprintf (f,"%s",rep1);
fprintf (f,"%s",rep2);
fprintf (f,"%s",rep3);
fclose(f);

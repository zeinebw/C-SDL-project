prog:fonctions.o main.o
gcc fonctions.o main.o -o prog
main.o:main.c
gcc -c main.c
fonctions.o:fonctions.c
gcc -c fonctions.c

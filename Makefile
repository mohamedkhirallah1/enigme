Game:main.o fonctions.o
	gcc main.o fonctions.o -o Game -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c 
fonctions.o:fonctions.c
	gcc -c fonctions.c

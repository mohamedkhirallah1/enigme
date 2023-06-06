#define CAMERA_W 800   ///// la largeur/hauteur du screen dans setvideomod
#define CAMERA_H 600
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


typedef struct
{
SDL_Surface *img_b;/*!< Surface. */
SDL_Rect position_b; /*!< Rectangle*/ //position
SDL_Rect scroll; /*!< Rectangle*/ 
Mix_Music *music;//son




}background;
struct camera
{
	SDL_Rect camera;
}; 
typedef struct camera camera;

void initialiser_background(background *b);
void initialiser_background2(background *b);
void afficher_backgroundmask(background b, SDL_Surface *ecran);
void afficher_background(background b, SDL_Surface *ecran);
void animerBackground(background *e);
void scrolling(background *b, int dire,int *pasavancement,SDL_Rect per,SDL_Rect *perso,int* lvl);

void scrolling_int(background *b,background *b1,int d,int pas);
//int collisionPP(Personne p,SDL_Surface *Screen);



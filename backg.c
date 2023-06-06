
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "backg.h"


void initialiser_background(background *b)
{

b->img_b=IMG_Load("11.bmp");
b->position_b.x=0;//plein écran
b->position_b.y=0;
b->scroll.x=0;
b->scroll.y=0;
b->scroll.w=3000;//largeur de img
b->scroll.h=400;//hauteur img

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

b->music=Mix_LoadMUS("music.mp3");

Mix_PlayMusic(b->music, -1);//lancement de music
}
void afficher_backgroundmask(background b, SDL_Surface *ecran)
{
SDL_BlitSurface(b.img_b,NULL,ecran,NULL);//background mask
}

void afficher_background(background b, SDL_Surface *ecran)
{
SDL_BlitSurface(b.img_b,&b.scroll,ecran,NULL);//background orgl b.scroll 5tr tet7ark
}


/*void initialiser_background2(background *b)
{
SDL_Surface *img_b=NULL;


b->img_b=IMG_Load("1.png");
b->position_b.x=0;
b->position_b.y=0;
b->scroll.x=0;
b->scroll.y=600;
b->scroll.w=b->img_b->w;
b->scroll.h=300;

}*/

void scrolling_int(background *b,background *b1,int d,int pas)
{
if(d==1)
b->scroll.x+=pas;
if(b->scroll.x>2000)
{b->scroll.x=2000;b1->scroll.x=2000;}
if(b->scroll.x<0)
{b->scroll.x=0;b1->scroll.x=0;}
}

void scrolling(background *b, int dire , int *pasavancement,SDL_Rect per,SDL_Rect *perso,int *lvl)
{

	 if(dire==2)//droite
	{
		b->scroll.x=*pasavancement;//yzid 3al x
		if(b->scroll.x>3000-800){//wsel lel le5r
			*lvl=+1;//detecter le passage de background normal à la background d'animation
			if(*lvl>=1){	
}
			b->scroll.x=0;//recharche de l'image 
			//printf("per.x=%d\n",per.x);
			perso->x=per.x;//donc retour à la position
			*pasavancement=0;}//7abssa sghayra
		


	}

	
	else if(dire==1)//gauche
	{	
		b->scroll.x=*pasavancement;//yon9oss 3al x		
		if(b->scroll.x<=0)
               {
               }

		
	}
    

       
	
	/*else if(dire==3)//saut
	{
		
		b->scroll.y-=pasavancement;

		if(b->scroll.y<=b->position_b.y)
			b->scroll.y=(CAMERA_H-b->position_b.y);
                 /*if(b->scroll.y>=b->scroll.h-b->position_b.y)
			b->scroll.y=(b->scroll.h-b->position_b.y)/2;
	}
	else if (dire == 0)
	{
		b->scroll.y+=pasavancement;
                /*if(b->scroll.y<=b->position_b.y)
			b->scroll.y=(CAMERA_H-b->position_b.y);
                 if(b->scroll.y>=b->scroll.h-b->position_b.y)
			b->scroll.y=(b->scroll.h-b->position_b.y)/2;*/
	//}

	
}




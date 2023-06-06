#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"


void menu(SDL_Surface *background,SDL_Surface* screen,SDL_Rect positionbackground,texte* txt,SDL_Surface *play,SDL_Surface *setting,SDL_Surface *quit,SDL_Rect positionplay,SDL_Rect positionsetting,SDL_Rect positionquit,SDL_Surface *credits,SDL_Rect positioncredits)
{
    SDL_BlitSurface(background,NULL,screen,&positionbackground);
    SDL_BlitSurface(play,NULL,screen,&positionplay);
    SDL_BlitSurface(setting,NULL,screen,&positionsetting);
    SDL_BlitSurface(credits,NULL,screen,&positioncredits);
    SDL_BlitSurface(quit,NULL,screen,&positionquit);
    SDL_Flip(screen);
}

void menu1(SDL_Surface *background1,SDL_Surface* screen,SDL_Rect positionbackground)
{
    SDL_BlitSurface(background1,NULL,screen,&positionbackground);
    SDL_Flip(screen);
}

void fleche(int etat,SDL_Surface* screen,SDL_Surface *play,SDL_Surface *quit,SDL_Surface *setting,SDL_Surface *credits,SDL_Surface *quit1,SDL_Surface *setting1,SDL_Surface *play1,SDL_Surface *credits1,SDL_Rect positionplay,SDL_Rect positionquit,SDL_Rect positionsetting,SDL_Rect positioncredits)
{
    if (etat==0)
    {
    SDL_BlitSurface(play1,NULL,screen,&positionplay);
    SDL_BlitSurface(setting,NULL,screen,&positionsetting);
    SDL_BlitSurface(credits,NULL,screen,&positioncredits);
    SDL_BlitSurface(quit,NULL,screen,&positionquit);
    SDL_Flip(screen);
    }
    else if (etat==1)
    {
    SDL_BlitSurface(play,NULL,screen,&positionplay);
    SDL_BlitSurface(setting1,NULL,screen,&positionsetting);
    SDL_BlitSurface(credits,NULL,screen,&positioncredits);
    SDL_BlitSurface(quit,NULL,screen,&positionquit);
    SDL_Flip(screen);
    }
    else if (etat==2)
    {
    SDL_BlitSurface(play,NULL,screen,&positionplay);
    SDL_BlitSurface(setting,NULL,screen,&positionsetting);
    SDL_BlitSurface(credits1,NULL,screen,&positioncredits);
    SDL_BlitSurface(quit,NULL,screen,&positionquit);
    SDL_Flip(screen);
    }
    else if (etat==3)
    {
    SDL_BlitSurface(play,NULL,screen,&positionplay);
    SDL_BlitSurface(setting,NULL,screen,&positionsetting);
    SDL_BlitSurface(credits,NULL,screen,&positioncredits);
    SDL_BlitSurface(quit1,NULL,screen,&positionquit);
    SDL_Flip(screen);
    }
}

void animation1(SDL_Surface *background3,SDL_Surface* screen,SDL_Rect *position,SDL_Surface *background1,SDL_Surface *background2,SDL_Rect positionbackground,int * compteur)
{
	position->x-=10;
    	position->y+=10;
    	if (position->y==100)
    	{
	position->y=0;
	position->x=100;
    	}
	SDL_BlitSurface(background3,NULL,screen,position);
    	SDL_Flip(screen);
	
	SDL_BlitSurface(background2,NULL,screen,&positionbackground);
	SDL_Flip(screen);
	(*compteur)++;
	if((*compteur)>100)
	{
		SDL_BlitSurface(background1,NULL,screen,&positionbackground);
		SDL_Flip(screen);
		if((*compteur)==200)
		{
			(*compteur)=0;
		}
	}

    
}


































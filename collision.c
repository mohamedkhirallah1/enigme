#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "collision.h"
#include <time.h>

SDL_Color GetPixel(SDL_Surface *background_mask,int x,int y)//ta3tik lcouleur fi blassa déterminée par x et y
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char* ) background_mask->pixels;
pPosition+= (background_mask->pitch * y);
pPosition+= (background_mask->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,background_mask->format->BytesPerPixel);
SDL_GetRGB(col,background_mask->format, &color.r, &color.g, &color.b);//couleur r,g,b
return (color);
}



  int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect Personnage){
  SDL_Color colobs;
  SDL_Color colgotten;
  SDL_Rect Pos[8];
  int collision = 0, i = 5;




colobs.r=0;//couleur ta3 lmask
colobs.g=0;
colobs.b=0;

  Pos[0].x = Personnage.x;//les points de perso

  Pos[0].y = Personnage.y;

  Pos[1].x = Personnage.x + (Personnage.w /2);

  Pos[1].y = Personnage.y;

  Pos[2].x = Personnage.x + Personnage.w;

  Pos[2].y = Personnage.y;

  Pos[3].x = Personnage.x;

  Pos[3].y =  Personnage.y + (Personnage.h/2);

  Pos[4].x = Personnage.x;

  Pos[4].y = Personnage.y + Personnage.h;

  Pos[5].x = Personnage.x + (Personnage.w /2);

  Pos[5].y =  Personnage.y + Personnage.h;

  Pos[6].x = Personnage.x + Personnage.w;

  Pos[6].y = Personnage.y + Personnage.h;

  Pos[7].x = Personnage.x + Personnage.w;

  Pos[7].y = Personnage.y + (Personnage.h/2);



while ((i<=7) && (collision == 0)) {

colgotten = GetPixel(BackgroundMasque,Pos[i].x,Pos[i].y);//ta3tik lcouleur des pixels fi position ml les positions ta3 lperso fil back mask

//printf("position %d- x: %d y: %d R:%d G:%d B:%d\n",i,Pos[i].x,Pos[i].y,colgotten.r,colgotten.g,colgotten.b);

    if ((colobs.r == colgotten.r) &&  (colobs.b == colgotten.b) &&

  (colobs.g == colgotten.g)){//nafs loun
      collision = 1;//fama collision

    }
	else{

      i++;//t3adeli position o5ra

    }

}

return collision;
}


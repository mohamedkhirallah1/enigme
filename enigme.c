#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "enigme.h"
#include <time.h>
#include <string.h>




enigme initEnigme(enigmeData ed,timer *t)
{
  enigme e;int i;
  e.f = fopen("enigme.txt", "r"); //nhell l fichier enigme.txt en mode lecture
 e.back = IMG_Load("background.jpg");// telechargement de l'image de background

  
t->pos_sprite.x=0; 
t->pos_sprite.y=0;
t->pos_sprite.w=(885/6);
t->pos_sprite.h=(313/2); 

t->pos_clock.x=1000;
t->pos_clock.y=150;
t->pos_clock.w=155;
t->pos_clock.h=155;

t->sprite=IMG_Load("clock.png");  //telechargement
       


   e.pos_back.x=0;
   e.pos_back.y=0;
   e.pos_back.w=1200; 
   e.pos_back.h=900; 

   e.pos_quest.x=300;
   e.pos_quest.y=0;
   e.pos_quest.w=534;//
   e.pos_quest.h=544;//
  
   e.pos_c1.x=90;
   e.pos_c1.y=500;
   e.pos_c1.w=313;//
   e.pos_c1.h=114;//

   e.pos_c2.x=390;
   e.pos_c2.y=500;
   e.pos_c2.w=313;//
   e.pos_c2.h=114;//

   e.pos_c3.x=690;
   e.pos_c3.y=500;
   e.pos_c3.w=313;//
   e.pos_c3.h=114;//


 return e;
}

void afficher_Enigme (SDL_Surface *screen, enigme e){
  
  SDL_BlitSurface(e.back, NULL, screen, &e.pos_back); //affichage
  SDL_BlitSurface(e.quest, NULL, screen, &e.pos_quest);
  SDL_BlitSurface(e.c1, NULL, screen, &e.pos_c1);
  SDL_BlitSurface(e.c2, NULL, screen, &e.pos_c2);
  SDL_BlitSurface(e.c3, NULL, screen, &e.pos_c3);

}

int randomize(){ //bch taatini enigme aleatoire //manbadel feha chy
int pos;
 srand(time(NULL)); 
pos=rand()%(4-0+1)+0;
return pos;
}
enigmeData generateEnigme(enigme *e){
  enigmeData ed[5]; //tableau de enigme kol zouz ostra mn enigme .txt f case
  enigmeData edata;
  int i;
  
  int pos = 0;//randomize();//appel de fonction bch taaml aleatoirement
  for (i = 0; i < 5; i++) { //boucle bch ya9ra kol case wahadha
    fscanf(e->f,"%s\n",ed[i].quest); //tsajalli esemi l fichier f les variables
    fscanf(e->f,"1)%s 2)%s 3)%s -%s\n",ed[i].c1, ed[i].c2, ed[i].c3, ed[i].x);
  }
   strcpy(edata.quest,ed[pos].quest); 
  strcpy (edata.c1 ,ed[pos].c1);
      strcpy(edata.c2 ,ed[pos].c2);
        strcpy(edata.c3 ,ed[pos].c3);
          strcpy(edata.x ,ed[pos].x);
  e->quest=IMG_Load(edata.quest);
       e->c1=IMG_Load(edata.c1);
       e->c2=IMG_Load(edata.c2);
       e->c3=IMG_Load(edata.c3);  // bch yaatini question b zhar m tableau     
  return edata;
}
void liberer_enigme(enigme e)
{
SDL_FreeSurface(e.back);
SDL_FreeSurface(e.quest);
SDL_FreeSurface(e.c1);
SDL_FreeSurface(e.c2);
SDL_FreeSurface(e.c3);
}

void animation_clock(SDL_Surface* screen,timer *t)
{


SDL_BlitSurface(t->sprite,&t->pos_sprite,screen,&t->pos_clock);SDL_Delay(300);//sdl_delay sor3a mtaa tsawer kifch bch yodhhrou 

if(t->pos_sprite.x==775)
  {t->pos_sprite.x=0; 
   if(t->pos_sprite.y==0)    
     {t->pos_sprite.y=173;}
     else t->pos_sprite.y=0;//nheb naheha nheb nkhaleha
  }
 
 else
   t->pos_sprite.x+=155;  
}

int resolutionEnigme(enigmeData ed, SDL_Event event){
int r_correcte=2;
  switch(event.type){
         case SDL_KEYDOWN: //k nenzel aal clavier
if(event.key.keysym.sym == SDLK_a){ if(r_correcte==1)return 1;else return 0;}if(event.key.keysym.sym == SDLK_b){ if(r_correcte==2)return 1;else return 0;}
if(event.key.keysym.sym == SDLK_c){ if(r_correcte==3)return 1;else return 0;}
                 break; 
           case SDL_QUIT://bch tokhroj
           return 0;
            break;                
}
return -1;
}

int enigme_jeu(SDL_Surface *screen)
{
enigmeData edata;enigme e;int done=0,reponse_vrai;timer t;int time=0;
 SDL_Event event;SDL_Surface*win;SDL_Rect poswin;
  


screen=SDL_SetVideoMode(1200,900,32,SDL_HWSURFACE|SDL_DOUBLEBUF);//nbadel l h w w haseb taswira

e=initEnigme(edata,&t);

/*win=IMG_Load("great.png");
poswin.x=10;
poswin.y=15;
poswin.w=512;
poswin.h=512;*/
edata=generateEnigme(&e); //enigme aleatoire

 
  while(!done /*&& time<12*/) //baad mnkaml kol chy nahy slachet
  {
    while (SDL_PollEvent(&event))
     {
         reponse_vrai=resolutionEnigme(edata,event);
     }  

     if(reponse_vrai!=-1)
      {
          if(reponse_vrai==1){printf("felicitation!\n");return 1;}
	else return 0;
      }
      //else{if(reponse==3);printf("reponse fausse!!\n");}
      

    afficher_Enigme(screen,e);
    animation_clock(screen,&t);
    
    SDL_Flip(screen); //mise a jour de l'ecran
    
   time++;
  }
   time=0;
   /*while (done && time<9)
    {

          SDL_BlitSurface(win,NULL,screen,&poswin);
          time++;
          SDL_Delay(150);
          SDL_Flip(screen);
          
    }*/ //teb3a msg bravo
liberer_enigme(e);
SDL_FreeSurface(t.sprite); //liberer image clock
}




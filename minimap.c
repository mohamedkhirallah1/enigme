#include "minimap.h"
#include <string.h>
void init_minimap(minimap *m, char *backg, char *player)
{
        m->backg_img = IMG_Load(backg);
        m->player_img = IMG_Load(player);
        m->pos_minimap.x = 0;
        m->pos_minimap.y = 0;
        m->pos_player.x =0;
        m->pos_player.y =0;
}
void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement)
{
        m->pos_player.x = (posJoueur.x + camera.x) * 0.09 ;
        m->pos_player.y = (posJoueur.y + camera.y) * 0.2;
}
void afficher_minimap(minimap m, SDL_Surface *screen, SDL_Rect camera)
{
        SDL_BlitSurface(m.backg_img, NULL, screen, &m.pos_minimap);
        SDL_BlitSurface(m.player_img, NULL, screen, &m.pos_player);
}


void update_score(int *last_time, int *score, char str_time[30], char str_score[20])
{
        (*score)++;


        sprintf(str_score, "Score : %d", *score );

}
void save_score(int score, char *url, char name[])
{
        FILE *fichier = NULL;
        fichier = fopen(url, "a+");
        if (fichier == NULL)
        {
                printf("can't load file ");
        }
        else
        {
                fprintf(fichier, "%s : %d\n", name, score );
                fclose(fichier);
        }

}

void best_score(char *url, char high_score[])
{
        FILE *fichier = NULL;
        fichier = fopen(url, "r");
        int score = 0, max = 0;
        char name[50], best_player[50];
        if (fichier == NULL)
        {
                printf("cannot load file");
        }
        else
        {
                while (fscanf(fichier, "%s : %d\n", name, &score) != EOF)
                {
                        if (score > max)
                        {
                                max = score;
                                strcpy(best_player, name);
                        }
   

                }
                fprintf(fichier, "best player :%s ", best_player);

                fclose(fichier);
        }
        sprintf(high_score, "high score : %s : %d", best_player, max);
}
void input_UserName(char *name, SDL_Event event, int *write)
{
        char PressedKey[3];
        PressedKey[0] = event.key.keysym.sym;
        PressedKey[1] = '\0';
        if (PressedKey[0] >= 'a' && PressedKey[0] <= 'z')
        {

                strcat(name, PressedKey);
        }
        else if (PressedKey[0] == SDLK_SPACE)
        {
                PressedKey[0] = ' ';
                strcat(name, PressedKey);
        }
        else if (PressedKey[0] == SDLK_RETURN)
        {
                *write = 0;
        }

        printf("%s\n", name);
}
void initialiser_temps(temps *t)
{
t->texte = NULL;

t->position.x=0;
t->position.y=0;

t->police = NULL;
t->police = TTF_OpenFont("ka1.ttf", 20);
if(t->police==NULL)
printf("error police\n");
strcpy( t->entree,"");    
t->tempsActuel = 0; 
t->tempsPrecedent = 0;
t->min = 0;
t->cmp=0;

}

void afficher_temps(temps *t,SDL_Surface *screen)
{



TTF_Font *police = NULL;//


 SDL_Event event;
   // TTF_Init();
 SDL_Color couleurNoire = {0, 0, 0}, couleurRouge = {255, 0, 0};
 


t->tempsActuel = SDL_GetTicks();
 

  sprintf(t->entree, "temps: %dm %ds",t->min,t->cmp); 

t->texte = TTF_RenderText_Shaded(t->police,t->entree, couleurNoire, couleurRouge);  //probleme police    gdb prog   where


t->tempsActuel = SDL_GetTicks();

 
     
        if (t->tempsActuel - t->tempsPrecedent >= 1000)  /*elwa9te ely t3ada  1000 millisecondes = 1 seconde*/
         {
            t->cmp++;  
 
            if(t->cmp ==60)
             {
              t->cmp=0;
               t->cmp++;
                  t->min++;
             }

 

 t->texte = TTF_RenderText_Shaded(t->police, t->entree, couleurNoire, couleurRouge);
      t->tempsPrecedent = t->tempsActuel;  

          }

       
        t->position.x = 820;
        t->position.y = 0;
        SDL_BlitSurface(t->texte, NULL, screen, &t->position);
	
        SDL_Flip(screen);
  

}

void free_temps(temps *t,SDL_Surface *screen)
{
	SDL_FreeSurface(t->texte);
 	TTF_CloseFont(t->police);
}
void afficher_name(char name[],SDL_Surface *screen)
{
TTF_Font *police = TTF_OpenFont("ka1.ttf", 20);
char lp[20];


 SDL_Color couleurNoire = {0, 0, 0}, couleurRouge = {250, 255, 100};



SDL_Surface *texte;
SDL_Rect position;

  sprintf(lp, " %s is playing",name); 
 texte = TTF_RenderText_Shaded(police,lp, couleurNoire, couleurRouge);
     position.x = 800;
       position.y =34;
        SDL_BlitSurface(texte, NULL, screen, &position);
	
      // SDL_Flip(screen);

}


#ifndef MINIMAP_H_
#define MINIMAP_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
        SDL_Surface *backg_img;
        SDL_Rect pos_minimap;
        SDL_Surface *player_img;
        SDL_Rect pos_player;
} minimap;

typedef struct temps
{
SDL_Surface *texte;
SDL_Rect position;
  
TTF_Font *police ;

char entree[20];
SDL_Color couleurBlanche,couleurNoire ;
int tempsActuel,tempsPrecedent;
int min,cmp;
}temps;


void init_minimap(minimap *m, char *backg, char *player);
void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement);
void afficher_minimap(minimap m, SDL_Surface *screen, SDL_Rect camera);
void initialiser_temps(temps *t);
void afficher_temps(temps *t,SDL_Surface *screen);
void free_temps(temps *t,SDL_Surface *screen);
void update_score(int *last_time, int *score, char str_time[], char str_score[]);
void save_score(int score, char *url, char name[]);
void best_score(char *url, char high_score[]);
void input_UserName(char *name, SDL_Event event, int *write);
void afficher_name(char name[],SDL_Surface *screen);

#endif

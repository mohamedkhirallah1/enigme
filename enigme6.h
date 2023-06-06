#ifndef QUIZ_H_
#define QUIZ_H_
/** 
* @struct enigme 
* @brief struct for enigme 
*/ 

typedef struct{
int d;

}enigme6;



void enigma(SDL_Surface *ecran,enigme6 e);
void reponse(SDL_Surface *ecran,int d);
void solution(SDL_Surface *ecran,int d);
void correct(SDL_Surface *ecran);
enigme6 generer();

#endif

#include "jeu.h"
#include "enigme6.h"
int jeu(SDL_Surface *screen){
Personne p,p1;
SDL_Surface *back;
int continuer=1,up=0, up1=0;
SDL_Event event;
int acceleration=0;
int deceleration=0;

int acceleration1=0;
int deceleration1=0;

Uint32 t_prev,t_fin , dt ;
temps t;
    Uint32 timer,elapsed;
	minimap m;

	init_minimap(&m, "level1.2.png", "pt rg&.png");
initialiser_temps(&t);
int lastTime = 0, score = 0;
	char str_time[50], str_score[50], high_score[50];
char name[50] = "";
	int writeName;
	SDL_Rect camera,image;
	camera.x = 0;
	camera.y = 0;
	camera.w = 30/ 2;
	camera.h = 10;

Ennemi E ;
initEnnemi(&E);
int enemy_alive=1,enigme_played=0;

screen=SDL_SetVideoMode (1000,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
initPerso(&p);
initPerso(&p1);
printf("votre nom:");
scanf("%s",name);
back=IMG_Load("background.png");

	srand(time(NULL));
background b,b2;
initialiser_background(&b);
initialiser_background(&b2);
b2.img_b=IMG_Load("11mask.bmp");////////////////////////////////////////mask

enigme6 ev;
ev.d=1;
ev=generer();


while (continuer)
{
t_prev = SDL_GetTicks();

while(SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
    continuer=0;
    break;

case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
    {
    case  SDLK_RIGHT:
        p.direction=0;
        p.vitesse=5;
        break;
    case  SDLK_LEFT:
        p.direction=1;
        p.vitesse=5;
        break; 
    case SDLK_UP:
        up=1;
        break;  
    case SDLK_p:
        acceleration=1;
    break;
    case SDLK_o:
        deceleration=1;
        break;

        
    case  SDLK_d:
        p1.direction=0;
        p1.vitesse=5;
        break;
    case  SDLK_q:
        p1.direction=1;
        p1.vitesse=5;
        break; 
    case SDLK_z:
        up1=1;
        break;  
    case SDLK_f:
        acceleration1=1;
    break;
    case SDLK_g:
        deceleration1=1;
        break;
    
    }
break;

case SDL_KEYUP:
switch (event.key.keysym.sym)//lbouton appuyé?
    {
    case  SDLK_RIGHT:
              p.vitesse=0;
        break;

    case  SDLK_LEFT:        
        p.vitesse=0;
        break; 

    case SDLK_UP:
        up=0;
        break; 

    case SDLK_p:
        acceleration=0;
    break;

    case SDLK_o:
        deceleration=0;
        break; 



        case  SDLK_d:
              p1.vitesse=0;
        break;

    case  SDLK_q:        
        p1.vitesse=0;
        break; 

    case SDLK_z:
        up1=0;
        break; 

    case SDLK_f:
        acceleration1=0;
    break;

    case SDLK_g:
        deceleration1=0;
        break;             
    
    }

break;
}
}
if (acceleration==1) p.acceleration = p.acceleration + 0.005 ;
if (deceleration==1) p.acceleration = p.acceleration - 0.01;

if (acceleration1==1) p1.acceleration = p1.acceleration + 0.005 ;
if (deceleration1==1) p1.acceleration = p1.acceleration - 0.01;

p.acceleration = p.acceleration - 0.001;
if (p.acceleration<0) p.acceleration =0;


p1.acceleration = p1.acceleration - 0.001;
if (p1.acceleration<0) p1.acceleration =0;


SDL_Delay(3);
t_fin=SDL_GetTicks();
dt=t_fin - t_prev ;

deplacerPerso(&p,dt);
animerPerso(&p);

deplacerPerso(&p1,dt);
animerPerso(&p1);

if (up==1) saut(&p);
p.position.y = p.position.y   + p.vitesse_saut ;
p.vitesse_saut = p.vitesse_saut + 10 ;
if (p.position.y>=120)
{   
    p.position.y=120;
    p.vitesse_saut=0;
}

if (up1==1) saut(&p1);
p1.position.y = p1.position.y   + p1.vitesse_saut ;
p1.vitesse_saut = p1.vitesse_saut + 10 ;
if (p1.position.y>=120)
{   
    p1.position.y=120;
    p1.vitesse_saut=0;
}
int lvl=1,pas=2;
if(p1.position.x>750)
{scrolling_int(&b,&b2,1,p1.vitesse);p1.position.x=750;}
if(p.position.x>750)
{scrolling_int(&b,&b2,1,p.vitesse);p.position.x=750;}
if(p1.position.x<50)
{scrolling_int(&b,&b2,1,-p1.vitesse);p1.position.x=50;}
if(p.position.x<50)
{scrolling_int(&b,&b2,1,-p.vitesse);p.position.x=50;}

    deplacerIA(&E,p1.position);
    animerEnnemi(&E);
if(enemy_alive<7)
{if (collision(E.pos,p1.position)==1)
    	enemy_alive++;}
if(enigme_played==0)
if(enemy_alive==7)
{SDL_Delay(500);
if(rand()%2==1){
if(enigme_jeu(screen)) score+=200;else return 0;enemy_alive++;}
else
enigma(screen,ev);
screen=SDL_SetVideoMode (1000,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);enigme_played=1;
}
if(enigme_played==0)
if(detectCollPP (b2.img_b,p.position))
{SDL_Delay(500);if(rand()%2==1){
if(enigme_jeu(screen)) score+=200;else return 0;enemy_alive++;enigme_played=1;}
else
enigma(screen,ev);
screen=SDL_SetVideoMode (1000,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);enigme_played=1;}

timer = SDL_GetTicks();
        elapsed = SDL_GetTicks() - timer;
        if (elapsed<20)
           { SDL_Delay(20-elapsed); }

			update_score(&lastTime, &score, t.entree, str_score);


/*----------partie affichage---------*/
//animer mehish mawjouda
//animerBackground(&b);
afficher_background(b,screen);
if(enemy_alive<7)
afficherEnnemi(E,screen);
afficher_minimap(m, screen, camera);
p.position.x+=b.scroll.x;
MAJMinimap(p.position, &m, camera, 25);
p.position.x-=b.scroll.x;
 afficher_temps(&t,screen);  
 afficher_name(name,screen);
afficherPerso(p,screen);
afficherPerso(p1,screen);
SDL_Flip(screen);

SDL_Delay(30);
}
input_UserName(name,event,&writeName);
save_score(score, "score.txt", name);
 best_score("score.txt",high_score);
printf("%s\n",high_score);
free_temps(&t,screen);
Mix_HaltMusic();
    return 0;}

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"//hgvjbknl
#include "jeu.h"



int main(int argc, char *argv[])
{
options b[20];
texte txt[7];

SDL_Surface *play,*quit,*setting,*credits=NULL,*quit1,*setting1,*play1,*credits1,*animation;
SDL_Rect positionplay,positionquit,positionsetting,positioncredits,positionanimation;

SDL_Surface* screen  = NULL;
SDL_Surface *background,*playbackground,*settingbackground,*creditsbackground,*background1,*background2,*background3; //reference our image
SDL_Rect positionbackground,positionanimationn;
SDL_Event event,event1,event2,event3;
Mix_Music *musique; //Création d'un pointeur de type Mix_Music
Mix_Chunk *clic;
TTF_Font *police = NULL,*police1 = NULL;
SDL_Color couleurblanc = {255, 255, 255};
int volume;
int continuer=1,p=0,i=0,etat=-1;
int compteur=0;
SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_DOUBLEBUF); // Ouverture de la fenêtre
if(!screen)
{
printf("unable to set 1920x1080 video: %s\n",SDL_GetError());
return (-1);
}
SDL_WM_SetCaption("Menu BETA", NULL);

//musique
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
volume=MIX_MAX_VOLUME / 2;
Mix_VolumeMusic(volume); //Mettre le volume à la moitié
musique = Mix_LoadMUS("test/faded.mp3"); //Chargement de la musique
Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
clic = Mix_LoadWAV("test/sound82.wav"); //Chargement de la musique
//Mix_VolumeChunk(clic,MIX_MAX_VOLUME);

//background et boutton et police
background3=IMG_Load("test/animationn.png");
positionanimationn.x=80;
positionanimationn.y=0;
background2=IMG_Load("test/background2.png");
background1=IMG_Load("test/background1.png");
background=IMG_Load("test/background.png"); //chargement background
if (background==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
settingbackground=IMG_Load("test/SETTINGS.png");
playbackground=IMG_Load("test/play_background.jpg");
creditsbackground=IMG_Load("test/credits_in.png");
positionbackground.x = 0;
positionbackground.y = 0;
SDL_BlitSurface(background,NULL,screen,&positionbackground); //placement background
TTF_Init(); //initialisation du ttf
if(TTF_Init() == -1)
    {
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
    }
police = TTF_OpenFont("test/made_by.ttf", 90); //chargement police
if (police==NULL)
    {
        printf("police erreur\n");
    }
    txt[0].text = TTF_RenderText_Blended(police, "MADE BY", couleurblanc); //chargement text
        txt[0].positiontext.x = 1490;
        txt[0].positiontext.y = 160;

police1 = TTF_OpenFont("test/names.ttf", 60); //chargement police
if (police1==NULL)
    {
        printf("police1 erreur\n");
    }
    txt[1].text = TTF_RenderText_Blended(police1, "Mohamed Aziz Msekni", couleurblanc); //chargement text
        txt[1].positiontext.x = 1395;
        txt[1].positiontext.y = 310;

    txt[2].text = TTF_RenderText_Blended(police1, "Linda Farah Trabelsi", couleurblanc); //chargement text
        txt[2].positiontext.x = 1395;
        txt[2].positiontext.y = 410;

    txt[3].text = TTF_RenderText_Blended(police1, "Amira Ouaz", couleurblanc); //chargement text
        txt[3].positiontext.x = 1395;
        txt[3].positiontext.y = 510;

    txt[4].text = TTF_RenderText_Blended(police1, "Mohamed Khirallah", couleurblanc); //chargement text
        txt[4].positiontext.x = 1395;
        txt[4].positiontext.y = 610;

    txt[5].text = TTF_RenderText_Blended(police1, "Nouram Hamdi", couleurblanc); //chargement text
        txt[5].positiontext.x = 1395;
        txt[5].positiontext.y = 710;

    txt[6].text = TTF_RenderText_Blended(police1, "Nour Amara", couleurblanc); //chargement text
        txt[6].positiontext.x = 1395;
        txt[6].positiontext.y = 810;

//SDL_Surface *play,*quit,*setting,*credits=NULL,*quit1,*setting1,*play1,*credits1,*animation;
//SDL_Rect positionplay,positionquit,positionsetting,positioncredits,positionanimation;


play=IMG_Load("test/play_not_pressed.png");
if (play==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
setting=IMG_Load("test/setting_not_pressed.png");
if (setting==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
quit=IMG_Load("test/exit_not_pressed.png");
if (quit==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
credits=IMG_Load("test/credits_not_pressed.png");
if (credits==NULL)
{ 
printf("credits: %s\n" , IMG_GetError());
return 1;
}
quit1=IMG_Load("test/exit_pressed.png");
if (quit1==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
setting1=IMG_Load("test/setting_pressed.png");
if (setting1==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
play1=IMG_Load("test/play_pressed.png");
if (play1==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
credits1=IMG_Load("test/credits_pressed.png");
if (credits1==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}

b[0].boutton=IMG_Load("test/hb_not_pressed.png");
if (b[0].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[1].boutton=IMG_Load("test/hb_pressed.png");
if (b[1].boutton==NULL)
{
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[2].boutton=IMG_Load("test/mute_not_pressed.png");
if (b[2].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[3].boutton=IMG_Load("test/mute_pressed.png");
if (b[3].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[4].boutton=IMG_Load("test/um_not_pressed.png");
if (b[4].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[5].boutton=IMG_Load("test/um_pressed.png");
if (b[5].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[6].boutton=IMG_Load("test/mb_not_pressedd.png");
if (b[6].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[7].boutton=IMG_Load("test/mb_pressedd.png");
if (b[7].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[8].boutton=IMG_Load("test/pb_not_pressed.png");
if (b[8].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[9].boutton=IMG_Load("test/pb_pressed.png");
if (b[9].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[10].boutton=IMG_Load("test/fs_not_pressed.png");
if (b[10].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[11].boutton=IMG_Load("test/fs_pressed.png");
if (b[11].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[12].boutton=IMG_Load("test/wd_not_pressed.png");
if (b[12].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}
b[13].boutton=IMG_Load("test/wd_pressed.png");
if (b[13].boutton==NULL)
{ 
printf("Unable to load bitmap : %s\n" , IMG_GetError());
return 1;
}

b[0].positionboutton.x=1380;
b[0].positionboutton.y=10;
b[2].positionboutton.x=1680;
b[2].positionboutton.y=10;
b[4].positionboutton.x=1800;
b[4].positionboutton.y=7;
b[6].positionboutton.x=1700;
b[6].positionboutton.y=410;
b[8].positionboutton.x=1790;
b[8].positionboutton.y=410;
b[10].positionboutton.x=1405;
b[10].positionboutton.y=550;
b[12].positionboutton.x=1405;
b[12].positionboutton.y=710;




positionplay.x = 1515;
positionplay.y = 230;
SDL_BlitSurface(play1,NULL,screen,&positionplay);
positionsetting.x = 1515;
positionsetting.y = 400;
SDL_BlitSurface(setting,NULL,screen,&positionsetting);
positioncredits.x = 1515;
positioncredits.y = 570;
SDL_BlitSurface(credits,NULL,screen,&positioncredits);
positionquit.x = 1515;
positionquit.y = 740;
SDL_BlitSurface(play1,NULL,screen,&positionplay);
SDL_BlitSurface(setting,NULL,screen,&positionsetting);
SDL_BlitSurface(quit,NULL,screen,&positionquit);
SDL_BlitSurface(credits,NULL,screen,&positioncredits);

// fleche(etat,screen,play,quit,setting,credits,quit1,setting1,play1,credits1,positionplay,positionquit,positionsetting,positioncredits);
SDL_Flip(screen);
continuer=1;
int playy=0;
int settingg=0,creditss=0;


while (continuer)
    {
        //menu1(background2,screen,positionbackground);
        //menu1(background1,screen,positionbackground);
        animation1(background3,screen,&positionanimationn,background1,background2,positionbackground,&compteur);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                            if(event.button.x >= positionquit.x && event.button.x <= (positionquit.x + 273) && event.button.y >= positionquit.y && event.button.y <= positionquit.y+138)
                                {
                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                    SDL_Flip(screen);
                                    continuer = 0;
                                }
                            else if(event.button.x >= positioncredits.x && event.button.x <= (positioncredits.x + 273) && event.button.y >= positioncredits.y && event.button.y <= positioncredits.y+138)
                                {
                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                    SDL_Flip(screen);
                                    SDL_BlitSurface(creditsbackground,NULL,screen,&positionbackground);
                                    for (i=0;i<7;i++)
                                    SDL_BlitSurface(txt[i].text,NULL,screen,&txt[i].positiontext);
                                    SDL_BlitSurface(b[0].boutton,NULL,screen,&b[0].positionboutton);
                                    SDL_Flip(screen);
                                    creditss=1;
                                    while (creditss==1)
                                    {
                                        SDL_WaitEvent(&event3);
                                        switch(event3.type)
                                        {
                                            case SDL_KEYDOWN:
                                                switch (event3.key.keysym.sym)
                                                {
                                                case SDLK_ESCAPE:
                                                    creditss=0;
                                                break;
                                                }
                                            break;
                                            case SDL_MOUSEMOTION:
                                                if(event3.motion.x >= b[0].positionboutton.x && event3.motion.x <= (b[0].positionboutton.x + 108) && event3.motion.y >= b[0].positionboutton.y && event3.motion.y <= b[0].positionboutton.y+98)
                                                    {
                                                        SDL_BlitSurface(b[1].boutton,NULL,screen,&b[0].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else
                                                    SDL_BlitSurface(b[0].boutton,NULL,screen,&b[0].positionboutton);
                                                    SDL_Flip(screen);
                                            break;
                                            case SDL_MOUSEBUTTONDOWN:
                                                if(event3.button.x >= b[0].positionboutton.x && event3.button.x <= (b[0].positionboutton.x + 108) && event3.button.y >= b[0].positionboutton.y && event3.button.y <= b[0].positionboutton.y+98)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                        creditss=0;
                                                    }
                                        }
                                    }
                                    menu(background,screen,positionbackground,txt,play,setting,quit,positionplay,positionsetting,positionquit,credits,positioncredits);
                                }
                            else if(event.button.x >= positionsetting.x && event.button.x <= (positionsetting.x + 273) && event.button.y >= positionsetting.y && event.button.y <= positionsetting.y+138) 
                                {
                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                    SDL_Flip(screen);
                                    SDL_BlitSurface(settingbackground,NULL,screen,&positionbackground);
                                    for(i=0;i<13;i=i+2)
                                    SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                    SDL_Flip(screen);
                                    settingg=1;
                                    while (settingg==1)
                                    {
                                        SDL_WaitEvent(&event2);
                                        switch(event2.type)
                                        {
                                            case SDL_MOUSEMOTION:
                                                if(event2.motion.x >= b[0].positionboutton.x && event2.motion.x <= (b[0].positionboutton.x + 108) && event2.motion.y >= b[0].positionboutton.y && event2.motion.y <= b[0].positionboutton.y+98)
                                                    {
                                                        SDL_BlitSurface(b[1].boutton,NULL,screen,&b[0].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[2].positionboutton.x && event2.motion.x <= (b[2].positionboutton.x + 108) && event2.motion.y >= b[2].positionboutton.y && event2.motion.y <= b[2].positionboutton.y+98)
                                                    {
                                                        SDL_BlitSurface(b[3].boutton,NULL,screen,&b[2].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[4].positionboutton.x && event2.motion.x <= (b[4].positionboutton.x + 108) && event2.motion.y >= b[4].positionboutton.y && event2.motion.y <= b[4].positionboutton.y+98)
                                                    {
                                                        SDL_BlitSurface(b[5].boutton,NULL,screen,&b[4].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[6].positionboutton.x && event2.motion.x <= (b[6].positionboutton.x + 78) && event2.motion.y >= b[6].positionboutton.y && event2.motion.y <= b[6].positionboutton.y+63)
                                                    {
                                                        SDL_BlitSurface(b[7].boutton,NULL,screen,&b[6].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[8].positionboutton.x && event2.motion.x <= (b[8].positionboutton.x + 78) && event2.motion.y >= b[8].positionboutton.y && event2.motion.y <= b[8].positionboutton.y+63)
                                                    {
                                                        SDL_BlitSurface(b[9].boutton,NULL,screen,&b[8].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[10].positionboutton.x && event2.motion.x <= (b[10].positionboutton.x + 486) && event2.motion.y >= b[10].positionboutton.y && event2.motion.y <= b[10].positionboutton.y+123)
                                                    {
                                                        SDL_BlitSurface(b[11].boutton,NULL,screen,&b[10].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[12].positionboutton.x && event2.motion.x <= (b[12].positionboutton.x + 486) && event2.motion.y >= b[12].positionboutton.y && event2.motion.y <= b[12].positionboutton.y+123)
                                                    {
                                                        SDL_BlitSurface(b[13].boutton,NULL,screen,&b[12].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else 
                                                    {
                                                        for(i=0;i<13;i=i+2)
                                                        SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                break;
                                            case SDL_MOUSEBUTTONDOWN:
                                                if(event2.button.x >= b[0].positionboutton.x && event2.button.x <= (b[0].positionboutton.x + 108) && event2.button.y >= b[0].positionboutton.y && event2.button.y <= b[0].positionboutton.y+98)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                        settingg=0;
                                                    }
                                                else if(event2.button.x >= b[2].positionboutton.x && event2.button.x <= (b[2].positionboutton.x + 108) && event2.button.y >= b[2].positionboutton.y && event2.button.y <= b[2].positionboutton.y+98)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                        //Mix_VolumeChunk(clic,0);
                                                        Mix_PauseMusic();
                                                    }
                                                else if(event2.button.x >= b[4].positionboutton.x && event2.button.x <= (b[4].positionboutton.x + 108) && event2.button.y >= b[4].positionboutton.y && event2.button.y <= b[4].positionboutton.y+98)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                        //Mix_VolumeChunk(clic,MIX_MAX_VOLUME/2);
                                                        Mix_ResumeMusic();
                                                    }
                                                else if(event2.button.x >= b[6].positionboutton.x && event2.button.x <= (b[6].positionboutton.x + 78) && event2.button.y >= b[6].positionboutton.y && event2.button.y <= b[6].positionboutton.y+63)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                    if (volume>0)
                                                    {
                                                        volume=volume-16;
                                                    }
                                                    Mix_VolumeMusic(volume);
                                                    }
                                                else if(event2.button.x >= b[8].positionboutton.x && event2.button.x <= (b[8].positionboutton.x + 78) && event2.button.y >= b[8].positionboutton.y && event2.button.y <= b[8].positionboutton.y+63)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                    if (volume<128)
                                                    {
                                                        volume=volume+16;
                                                    }
                                                    Mix_VolumeMusic(volume);
                                                    }
                                                else if(event2.button.x >= b[10].positionboutton.x && event2.button.x <= (b[10].positionboutton.x + 486) && event2.button.y >= b[10].positionboutton.y && event2.button.y <= b[10].positionboutton.y+123)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        //screen=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_FULLSCREEN);
							screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_FULLSCREEN);
                                                        SDL_BlitSurface(settingbackground,NULL,screen,&positionbackground);
                                                        for(i=0;i<13;i=i+2)
                                                        SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.button.x >= b[12].positionboutton.x && event2.button.x <= (b[12].positionboutton.x + 486) && event2.button.y >= b[12].positionboutton.y && event2.button.y <= b[12].positionboutton.y+123)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
                                                        SDL_BlitSurface(settingbackground,NULL,screen,&positionbackground);
                                                        for(i=0;i<13;i=i+2)
                                                        SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                break;
                                            case SDL_KEYDOWN:
                                                switch (event2.key.keysym.sym)
                                                {
                                                case SDLK_ESCAPE:
                                                    settingg=0;
                                                    break;
                                                case SDLK_LEFT:
                                                    SDL_BlitSurface(b[7].boutton,NULL,screen,&b[6].positionboutton);
                                                    Mix_PlayChannel(1,clic,0);
                                                    SDL_Flip(screen);
                                                    if (volume>0)
                                                    {
                                                        volume=volume-16;
                                                    }
                                                    Mix_VolumeMusic(volume);
                                                    break;
                                                case SDLK_RIGHT:
                                                    SDL_BlitSurface(b[9].boutton,NULL,screen,&b[8].positionboutton);
                                                    Mix_PlayChannel(1,clic,0);
                                                    SDL_Flip(screen);
                                                    if (volume<128)
                                                    {
                                                        volume=volume+16;
                                                    }
                                                    Mix_VolumeMusic(volume);
                                                    break;
                                                }
                                        }
                                    }
                                    menu(background,screen,positionbackground,txt,play,setting,quit,positionplay,positionsetting,positionquit,credits,positioncredits);
                                }
                            else if(event.button.x >= positionplay.x && event.button.x <= (positionplay.x + 273) && event.button.y >= positionplay.y && event.button.y <= positionplay.y+138) 
                                {
                                    Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                    SDL_Flip(screen);
                                    jeu(screen);
                                    SDL_Flip(screen);
                                    playy=1;
screen=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
                                    /*while (playy==1)
                                    {
                                        SDL_WaitEvent(&event1);
                                        switch(event1.type)
                                        {
                                            case SDL_KEYDOWN:
                                                switch (event1.key.keysym.sym)
                                                {
                                                case SDLK_ESCAPE:
                                                    playy=0;
                                                    break;
                                                }
                                        }
                                    }*/
                                    menu(background,screen,positionbackground,txt,play,setting,quit,positionplay,positionsetting,positionquit,credits,positioncredits);
                                }
                                break;
                case SDL_MOUSEMOTION:
                            if(event.motion.x >= positionquit.x && event.motion.x <= (positionquit.x + 273) && event.motion.y >= positionquit.y && event.motion.y <= positionquit.y+138)
                                {SDL_BlitSurface(quit,NULL,screen,&positionquit);
 SDL_Flip(screen);
                                    SDL_BlitSurface(quit1,NULL,screen,&positionquit);
                                    SDL_Flip(screen);
                                }
                            else if(event.button.x >= positioncredits.x && event.button.x <= (positioncredits.x + 273) && event.button.y >= positioncredits.y && event.button.y <= positioncredits.y+138)
                                {  SDL_BlitSurface(credits,NULL,screen,&positioncredits);
 SDL_Flip(screen);
                                    SDL_BlitSurface(credits1,NULL,screen,&positioncredits);
                                    SDL_Flip(screen);
                                }
                            else if(event.motion.x >= positionsetting.x && event.motion.x <= (positionsetting.x + 273) && event.motion.y >= positionsetting.y && event.motion.y <= positionsetting.y+138) 
                                {SDL_BlitSurface(setting,NULL,screen,&positionsetting);
 SDL_Flip(screen);
                                    SDL_BlitSurface(setting1,NULL,screen,&positionsetting);
                                    SDL_Flip(screen);
                                }
                            else if(event.motion.x >= positionplay.x && event.motion.x <= (positionplay.x + 273) && event.motion.y >= positionplay.y && event.motion.y <= positionplay.y+138) 
                                {  SDL_BlitSurface(play,NULL,screen,&positionplay);
 SDL_Flip(screen);
                                    SDL_BlitSurface(play1,NULL,screen,&positionplay);
                                    SDL_Flip(screen);
                                }
                            else
                                {
                                SDL_BlitSurface(play,NULL,screen,&positionplay);
                                SDL_BlitSurface(setting,NULL,screen,&positionsetting);
                                SDL_BlitSurface(credits,NULL,screen,&positioncredits);
                                SDL_BlitSurface(quit,NULL,screen,&positionquit);
                                SDL_Flip(screen);
                                }
                            break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_p:
                        SDL_BlitSurface(play1,NULL,screen,&positionplay);
                        Mix_PlayChannel(1, clic, 0);
                        SDL_Flip(screen);
                        jeu(screen);
                        SDL_Flip(screen);
screen=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
                        /*playy=1;
                        while (playy==1)
                        {
                            SDL_WaitEvent(&event1);
                            switch(event1.type)
                            {
                                case SDL_KEYDOWN:
                                    switch (event1.key.keysym.sym)
                                    {
                                    case SDLK_ESCAPE:
                                        playy=0;
                                        break;
                                    }
                            }
                        }*/
                        menu(background,screen,positionbackground,txt,play,setting,quit,positionplay,positionsetting,positionquit,credits,positioncredits);
                        break;
                        case SDLK_ESCAPE:
                        Mix_PlayChannel(1, clic, 0);
                        SDL_BlitSurface(quit1,NULL,screen,&positionquit);
                        SDL_Flip(screen);
                        continuer=0;
                        break;
                        case SDLK_UP:
                        etat--;
                        if (etat>=0)
                        {
                        fleche(etat,screen,play,quit,setting,credits,quit1,setting1,play1,credits1,positionplay,positionquit,positionsetting,positioncredits);
                        }
                        else if (etat<0)
                        {
                            etat=3;
                            fleche(etat,screen,play,quit,setting,credits,quit1,setting1,play1,credits1,positionplay,positionquit,positionsetting,positioncredits);
                        }
                        break;
                        case SDLK_DOWN:
                        etat++;
                        if (etat<4)
                        {
                        fleche(etat,screen,play,quit,setting,credits,quit1,setting1,play1,credits1,positionplay,positionquit,positionsetting,positioncredits);
                        }
                        else if (etat>=4)
                        {
                            etat=0;
                            fleche(etat,screen,play,quit,setting,credits,quit1,setting1,play1,credits1,positionplay,positionquit,positionsetting,positioncredits);
                        }
                        break;
                        case SDLK_RETURN:
                        if (etat==0)
                        {
                           SDL_BlitSurface(play1,NULL,screen,&positionplay);
                        Mix_PlayChannel(1, clic, 0);
                        SDL_Flip(screen);
                        jeu(screen);
                        SDL_Flip(screen);
                        playy=1;
screen=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
                        /*while (playy==1)
                        {
                            SDL_WaitEvent(&event1);
                            switch(event1.type)
                            {
                                case SDL_KEYDOWN:
                                    switch (event1.key.keysym.sym)
                                    {
                                    case SDLK_ESCAPE:
                                        playy=0;
                                        break;
                                    }
                            }
                        }*/
                        menu(background,screen,positionbackground,txt,play,setting,quit,positionplay,positionsetting,positionquit,credits,positioncredits); 
                        }
                        else if (etat==1)
                        {
                            Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                    SDL_Flip(screen);
                                    SDL_BlitSurface(settingbackground,NULL,screen,&positionbackground);
                                    for(i=0;i<13;i=i+2)
                                    SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                    SDL_Flip(screen);
                                    settingg=1;
                                    while (settingg==1)
                                    {
                                        SDL_WaitEvent(&event2);
                                        switch(event2.type)
                                        {
                                            case SDL_MOUSEMOTION:
                                                if(event2.motion.x >= b[0].positionboutton.x && event2.motion.x <= (b[0].positionboutton.x + 108) && event2.motion.y >= b[0].positionboutton.y && event2.motion.y <= b[0].positionboutton.y+98)
                                                    {
                                                        SDL_BlitSurface(b[1].boutton,NULL,screen,&b[0].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[2].positionboutton.x && event2.motion.x <= (b[2].positionboutton.x + 108) && event2.motion.y >= b[2].positionboutton.y && event2.motion.y <= b[2].positionboutton.y+98)
                                                    {
                                                        SDL_BlitSurface(b[3].boutton,NULL,screen,&b[2].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[4].positionboutton.x && event2.motion.x <= (b[4].positionboutton.x + 108) && event2.motion.y >= b[4].positionboutton.y && event2.motion.y <= b[4].positionboutton.y+98)
                                                    {
                                                        SDL_BlitSurface(b[5].boutton,NULL,screen,&b[4].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[6].positionboutton.x && event2.motion.x <= (b[6].positionboutton.x + 78) && event2.motion.y >= b[6].positionboutton.y && event2.motion.y <= b[6].positionboutton.y+63)
                                                    {
                                                        SDL_BlitSurface(b[7].boutton,NULL,screen,&b[6].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[8].positionboutton.x && event2.motion.x <= (b[8].positionboutton.x + 78) && event2.motion.y >= b[8].positionboutton.y && event2.motion.y <= b[8].positionboutton.y+63)
                                                    {
                                                        SDL_BlitSurface(b[9].boutton,NULL,screen,&b[8].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[10].positionboutton.x && event2.motion.x <= (b[10].positionboutton.x + 486) && event2.motion.y >= b[10].positionboutton.y && event2.motion.y <= b[10].positionboutton.y+123)
                                                    {
                                                        SDL_BlitSurface(b[11].boutton,NULL,screen,&b[10].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.motion.x >= b[12].positionboutton.x && event2.motion.x <= (b[12].positionboutton.x + 486) && event2.motion.y >= b[12].positionboutton.y && event2.motion.y <= b[12].positionboutton.y+123)
                                                    {
                                                        SDL_BlitSurface(b[13].boutton,NULL,screen,&b[12].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else 
                                                    {
                                                        for(i=0;i<13;i=i+2)
                                                        SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                break;
                                            case SDL_MOUSEBUTTONDOWN:
                                                if(event2.button.x >= b[0].positionboutton.x && event2.button.x <= (b[0].positionboutton.x + 108) && event2.button.y >= b[0].positionboutton.y && event2.button.y <= b[0].positionboutton.y+98)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                        settingg=0;
                                                    }
                                                else if(event2.button.x >= b[2].positionboutton.x && event2.button.x <= (b[2].positionboutton.x + 108) && event2.button.y >= b[2].positionboutton.y && event2.button.y <= b[2].positionboutton.y+98)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                        //Mix_VolumeChunk(clic,0);
                                                        Mix_PauseMusic();
                                                    }
                                                else if(event2.button.x >= b[4].positionboutton.x && event2.button.x <= (b[4].positionboutton.x + 108) && event2.button.y >= b[4].positionboutton.y && event2.button.y <= b[4].positionboutton.y+98)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                        //Mix_VolumeChunk(clic,MIX_MAX_VOLUME/2);
                                                        Mix_ResumeMusic();
                                                    }
                                                else if(event2.button.x >= b[6].positionboutton.x && event2.button.x <= (b[6].positionboutton.x + 78) && event2.button.y >= b[6].positionboutton.y && event2.button.y <= b[6].positionboutton.y+63)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                    if (volume>0)
                                                    {
                                                        volume=volume-16;
                                                    }
                                                    Mix_VolumeMusic(volume);
                                                    }
                                                else if(event2.button.x >= b[8].positionboutton.x && event2.button.x <= (b[8].positionboutton.x + 78) && event2.button.y >= b[8].positionboutton.y && event2.button.y <= b[8].positionboutton.y+63)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                    if (volume<128)
                                                    {
                                                        volume=volume+16;
                                                    }
                                                    Mix_VolumeMusic(volume);
                                                    }
                                                else if(event2.button.x >= b[10].positionboutton.x && event2.button.x <= (b[10].positionboutton.x + 486) && event2.button.y >= b[10].positionboutton.y && event2.button.y <= b[10].positionboutton.y+123)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        screen=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
                                                        SDL_BlitSurface(settingbackground,NULL,screen,&positionbackground);
                                                        for(i=0;i<13;i=i+2)
                                                        SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else if(event2.button.x >= b[12].positionboutton.x && event2.button.x <= (b[12].positionboutton.x + 486) && event2.button.y >= b[12].positionboutton.y && event2.button.y <= b[12].positionboutton.y+123)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
                                                        SDL_BlitSurface(settingbackground,NULL,screen,&positionbackground);
                                                        for(i=0;i<13;i=i+2)
                                                        SDL_BlitSurface(b[i].boutton,NULL,screen,&b[i].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                break;
                                            case SDL_KEYDOWN:
                                                switch (event2.key.keysym.sym)
                                                {
                                                case SDLK_ESCAPE:
                                                    settingg=0;
                                                    break;
                                                case SDLK_LEFT:
                                                    SDL_BlitSurface(b[7].boutton,NULL,screen,&b[6].positionboutton);
                                                    Mix_PlayChannel(1,clic,0);
                                                    SDL_Flip(screen);
                                                    if (volume>0)
                                                    {
                                                        volume=volume-16;
                                                    }
                                                    Mix_VolumeMusic(volume);
                                                    break;
                                                case SDLK_RIGHT:
                                                    SDL_BlitSurface(b[9].boutton,NULL,screen,&b[8].positionboutton);
                                                    Mix_PlayChannel(1,clic,0);
                                                    SDL_Flip(screen);
                                                    if (volume<128)
                                                    {
                                                        volume=volume+16;
                                                    }
                                                    Mix_VolumeMusic(volume);
                                                    break;
                                                }
                                        }
                                    }
                                    menu(background,screen,positionbackground,txt,play,setting,quit,positionplay,positionsetting,positionquit,credits,positioncredits);
                        }
                        else if (etat==2)
                        {
                            Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                    SDL_Flip(screen);
                                    SDL_BlitSurface(creditsbackground,NULL,screen,&positionbackground);
                                    for (i=0;i<7;i++)
                                    SDL_BlitSurface(txt[i].text,NULL,screen,&txt[i].positiontext);
                                    SDL_BlitSurface(b[0].boutton,NULL,screen,&b[0].positionboutton);
                                    SDL_Flip(screen);
                                    creditss=1;
                                    while (creditss==1)
                                    {
                                        SDL_WaitEvent(&event3);
                                        switch(event3.type)
                                        {
                                            case SDL_KEYDOWN:
                                                switch (event3.key.keysym.sym)
                                                {
                                                case SDLK_ESCAPE:
                                                    creditss=0;
                                                break;
                                                }
                                            break;
                                            case SDL_MOUSEMOTION:
                                                if(event3.motion.x >= b[0].positionboutton.x && event3.motion.x <= (b[0].positionboutton.x + 108) && event3.motion.y >= b[0].positionboutton.y && event3.motion.y <= b[0].positionboutton.y+98)
                                                    {
                                                        SDL_BlitSurface(b[1].boutton,NULL,screen,&b[0].positionboutton);
                                                        SDL_Flip(screen);
                                                    }
                                                else
                                                    SDL_BlitSurface(b[0].boutton,NULL,screen,&b[0].positionboutton);
                                                    SDL_Flip(screen);
                                            break;
                                            case SDL_MOUSEBUTTONDOWN:
                                                if(event3.button.x >= b[0].positionboutton.x && event3.button.x <= (b[0].positionboutton.x + 108) && event3.button.y >= b[0].positionboutton.y && event3.button.y <= b[0].positionboutton.y+98)
                                                    {
                                                        Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                                                        SDL_Flip(screen);
                                                        creditss=0;
                                                    }
                                        }
                                    }
                                    menu(background,screen,positionbackground,txt,play,setting,quit,positionplay,positionsetting,positionquit,credits,positioncredits);
                        }
                        else if (etat==3)
                        {
                            Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                            SDL_Flip(screen);
                            continuer = 0;
                        }
                        break;
                    }
            }
        }
    }
Mix_CloseAudio(); //Fermeture de l'API
SDL_Quit(); // Arrêt de la SDL
return EXIT_SUCCESS; // Fermeture du programme
}


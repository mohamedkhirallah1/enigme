#include <stdio.h>
#include <stdlib.h>
#include "savegame.h"




void sauvegarder_stage (personnage *p, char *nomfichier ,background *b )
{
	FILE *f;
   
	f=fopen(nomfichier, "wb");

	fwrite(p, sizeof(personnage), 1, f);
	fwrite(b,sizeof(background),1,f);

	fclose(f);
	
   
}

void load_game (personnage *p, char *nomfichier, background *b)
{

	FILE *f=fopen(nomfichier,"rb");

	if(f==NULL)
	{
	     printf("Erreur !");
	}
	
	
	else
	{
		printf("loading");
		fread(p, sizeof(personnage), 1, f);	
		fread(b, sizeof(background), 1, f);
	}

	fclose(f);
}
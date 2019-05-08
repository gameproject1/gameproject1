#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
 #include <unistd.h>
#include <math.h>
#include"struct.h"

void initialiser_entite(entite *cd,entite *cg,entite *dc, entite *dop,entite *bijoux,entite *money,entite *password,entite*cle)
	{

	cd->image=NULL ; 
	cd->image=IMG_Load("cameradroite.png");
	cd->pos_image.x=1355 ; 
	cd->pos_image.y=0 ;


 
        bijoux->image=NULL ; 
	bijoux->image=IMG_Load("bijoux.png");
	bijoux->pos_image.x=4374 ; 
	bijoux->pos_image.y=335 ; 
        

        password->image=NULL ; 
	password->image=IMG_Load("password.png");
	password->pos_image.x=5321 ; 
	password->pos_image.y=350 ; 


        money->image=NULL ; 
	money->image=IMG_Load("money.png");
	money->pos_image.x=2753 ; 
	money->pos_image.y=255 ; 


        cle->image=NULL ; 
	cle->image=IMG_Load("clé.png");
	cle->pos_image.x=284 ; 
	cle->pos_image.y=254 ; 

	cg->image=NULL ; 
	cg->image=IMG_Load("cameragauche.png");
	cg->pos_image.x=1355 ; 
	cg->pos_image.y=0 ; 

	dc->image=NULL ; 
	dc->image=IMG_Load("doorclose.png");
	dc->pos_image.x=5500 ; 
	dc->pos_image.y=241 ; 

	dop->image=NULL ; 
	dop->image=IMG_Load("dooropen.png");
	dop->pos_image.x=5500 ; 
	dop->pos_image.y=241 ; 
	cd->x=1;
	cd->k1=0;
	cd->k2=0;

	}

       void affichage_entite(SDL_Surface *screen,entite *cd,entite *cg,entite *dc, entite *dop,entite *bijoux,entite *money,entite *password,entite*cle,int mouvment)
	{
        SDL_Surface*imv=NULL;
         imv=IMG_Load("vie1.png");
	if (mouvment==1){
		cd->pos_image.x-=5;
		dc->pos_image.x-=5;
		dop->pos_image.x-=5;
		cg->pos_image.x-=5;
	}
	if (mouvment==2){
		cd->pos_image.x+=5;
		dc->pos_image.x+=5;
		dop->pos_image.x+=5;
		cg->pos_image.x+=5;
	}
	
	if (cd->x==1){
		SDL_BlitSurface(cd->image,NULL,screen,&cd->pos_image);
		SDL_BlitSurface(dc->image,NULL,screen,&dc->pos_image);
;
	
		cd->k1++;
		if (cd->k1==30){
			cd->x=2;
			cd->k2=0;
		}
	}
	if (cd->x==2){
		SDL_BlitSurface(dop->image,NULL,screen,&dop->pos_image);
		SDL_BlitSurface(cg->image,NULL,screen,&cg->pos_image);
		cd->k2++;
			if (cd->k2==30){
				cd->x=1;
				cd->k1=0;
			}

	}
	if (cg->pos_image.x<0)
	 	cg->image=NULL;
	if (cd->pos_image.x<0)
{
	 	cd->image=NULL;
	
	}
SDL_BlitSurface(imv,NULL,screen,NULL);
SDL_Flip(screen);
/*SDL_BlitSurface(bijoux->image,NULL,screen,NULL);
SDL_Flip(screen);
SDL_BlitSurface(money->image,NULL,screen,&money->pos_image);
SDL_Flip(screen);
SDL_BlitSurface(password->image,NULL,screen,&password->pos_image);
SDL_Flip(screen);
SDL_BlitSurface(cle->image,NULL,screen,&cle->pos_image);
SDL_Flip(screen);*/





}
	


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
#include <time.h>
void initialiser_perso(perso *aziz){
		
		//evan->afficher_hero=NULL;
		//evan->afficher_hero=IMG_Load("walk.png");

		aziz->afficher_heror[0]=NULL;
		aziz->afficher_heror[1]=NULL;
		aziz->afficher_heror[2]=NULL;
		aziz->afficher_heror[3]=NULL;
		aziz->afficher_heror[4]=NULL;
		aziz->afficher_heror[5]=NULL;
		aziz->afficher_heror[6]=NULL;
		aziz->afficher_heror[7]=NULL;
		aziz->afficher_heror[8]=NULL;
		aziz->afficher_heror[9]=NULL;

		aziz->afficher_herol[0]=NULL;
		aziz->afficher_herol[1]=NULL;
		aziz->afficher_herol[2]=NULL;
		aziz->afficher_herol[3]=NULL;
		aziz->afficher_herol[4]=NULL;
		aziz->afficher_herol[5]=NULL;
		aziz->afficher_herol[6]=NULL;
		aziz->afficher_herol[7]=NULL;
		aziz->afficher_herol[8]=NULL;
		aziz->afficher_herol[9]=NULL;

		aziz->afficher_heror[0]=IMG_Load("r1.png");
		aziz->afficher_heror[1]=IMG_Load("r2.png");
		aziz->afficher_heror[2]=IMG_Load("r3.png");
		aziz->afficher_heror[3]=IMG_Load("r4.png");
		aziz->afficher_heror[4]=IMG_Load("r5.png");
		aziz->afficher_heror[5]=IMG_Load("r6.png");
		aziz->afficher_heror[6]=IMG_Load("r7.png");
		aziz->afficher_heror[7]=IMG_Load("r8.png");
		aziz->afficher_heror[8]=IMG_Load("r9.png");
		aziz->afficher_heror[9]=IMG_Load("r10.png");

		aziz->afficher_herol[0]=IMG_Load("l1.png");
		aziz->afficher_herol[1]=IMG_Load("l2.png");
		aziz->afficher_herol[2]=IMG_Load("l3.png");
		aziz->afficher_herol[3]=IMG_Load("l4.png");
		aziz->afficher_herol[4]=IMG_Load("l5.png");
		aziz->afficher_herol[5]=IMG_Load("l6.png");
		aziz->afficher_herol[6]=IMG_Load("l7.png");
		aziz->afficher_herol[7]=IMG_Load("l8.png");
		aziz->afficher_herol[8]=IMG_Load("l9.png");
		aziz->afficher_herol[9]=IMG_Load("l10.png");


	
	aziz->farm=0;
	
	aziz->pos_hero2.x=0;
	aziz->pos_hero2.y=400;

}

int mouvment(perso aziz,SDL_Event *event){

 	int mouvment;

 	SDL_PollEvent(event);
 	switch (event->type)
        {
        case SDL_QUIT:
           mouvment=0;
            break;
  	case SDL_MOUSEBUTTONUP:               
                    
           	mouvment=1;
	 break;
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym)
            {
            case SDLK_ESCAPE:
                mouvment=0;
                break;
            case SDLK_RIGHT:
				mouvment=1;
                break;
            case SDLK_LEFT:
            	mouvment=2;
                break;
            case SDLK_UP: 
                mouvment=3;  
                 break;
            }
            break;
             default: 	mouvment=9;
 }

 return mouvment;

}

void afficher_perso(perso aziz,SDL_Surface *ecran){
	if ((aziz.mouvment==1)||(aziz.mouvment==3)||(aziz.mouvment==9))
		SDL_BlitSurface(aziz.afficher_heror[aziz.farm],NULL,ecran,&(aziz.pos_hero2));
	if(aziz.mouvment==2)
		SDL_BlitSurface(aziz.afficher_herol[aziz.farm],NULL,ecran,&(aziz.pos_hero2));
}

int animation_perso(perso aziz){


	int farm=aziz.farm;
	switch(aziz.mouvment){

		case 1:
				if (farm<9)
					farm++;
				else farm=0;
				//usleep(30000);
			
			break;
		case 2:
				if (farm<9)
					farm++;
				else farm=0;			
				
				//usleep(20000);
			
			break;
		case 3:
			if (farm<9)
					farm++;
				else farm=0;			
				//usleep(20000);
			break;
		default: farm=0;
	}
	return farm;
}

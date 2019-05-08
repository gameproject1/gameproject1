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

void initialiser_background(background *bckg){



	bckg->afficher_background=NULL;
	bckg->afficher_background=IMG_Load("b1.jpg");
	bckg->pos_background.x=0;
	bckg->pos_background.y=0;
	bckg->pos_background2.x=0;
	bckg->pos_background2.y=0;
	bckg->pos_background2.h=680;
	bckg->pos_background2.w=1200;
}
void afficher_background(background bckg,SDL_Surface *ecran){
	SDL_BlitSurface(bckg.afficher_background,&(bckg.pos_background2),ecran,&(bckg.pos_background));

}
void scrolling (perso *aziz,background *bckg )
{
		aziz->etat=0;
	switch(aziz->mouvment)
	{

		case 1: 
			
				aziz->etat=1;
			if ((bckg->pos_background2.x<4500)&&(aziz->pos_hero2.x>=300)){
                		bckg->pos_background2.x=bckg->pos_background2.x+5;
			}
			if (((aziz->pos_hero2.x<300)||((bckg->pos_background2.x>=4500))&&(aziz->pos_hero2.x<1000)))
				aziz->pos_hero2.x=aziz->pos_hero2.x+5;
	
	
		
		
		break;
		case 2:
		
				aziz->etat=2;
			if (bckg->pos_background2.x>0)
                		bckg->pos_background2.x=bckg->pos_background2.x-5;
	    		if (((bckg->pos_background2.x!=0)&&(aziz->pos_hero2.x>=150))||((bckg->pos_background2.x==0)&&(aziz->pos_hero2.x=50)))
				aziz->pos_hero2.x=aziz->pos_hero2.x-5;
				
		break;
	}

	
}

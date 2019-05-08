#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"struct.h"
#include"score.h"

void main(void){
	SDL_Surface *ecran =NULL,*rectangle = NULL;
	menu menu;
        SDL_Rect p ;
	p.x=0 ;
	p.y=0 ;
	enigme  e;
        score ss;
        SDL_Event event;
	FILE *f ;
	int s,r,run =1,running=1,alea,k;
	char image[30]="";
        f=fopen("test.txt","a") ;
	int continuer=1;
	SDL_Init(SDL_INIT_VIDEO);
	background bckg;
	perso aziz;
	entite cd,cg,dop,dc,bijoux,cle,money,password;
        mini m;
        m=init(m);
        ecran = SDL_SetVideoMode(1209, 680, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	initialiser_menu(&menu,ecran);
	initialiser_background(&bckg);
	initialiser_perso(&aziz);
	initialiser_entite(&cd,&cg,&dc,&dop,&bijoux,&money,&password,&cle);
        ss=init_score(ss);
	


	while(continuer){
			if (menu.action==1){
			affichermenu(&menu,ecran);
			}

			if (menu.action==10){
                              
				afficher_background(bckg,ecran);
                                afficher_perso(aziz,ecran);
                                //afficher( m,ecran);
				aziz.mouvment=mouvment(aziz,&event);
				aziz.farm=animation_perso(aziz);
                                //minimap(ecran,&event, m,continuer);
				scrolling (&aziz,&bckg );
                                affichage_entite(ecran,&cd,&cg,&dc,&dop,&bijoux,&money,&password,&cle,aziz.mouvment);
                                //scor(ss,ecran,&event);
                               

     
                                
                                
			}
			 if ((menu.action==0)||(aziz.mouvment==0))
			 continuer=0;
			 SDL_Flip(ecran);
                         SDL_Delay(30);



if(bckg.pos_background2.x>4200)
{


 while (run)
	 {
        running=1,r=0 ;
	SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                run = 0;
	 break ;
	

        }	
                 fprintf(f,"%d\n",e.p.x) ;
	         fprintf(f,"%d\n",e.p.y) ;
                 generate_afficher (ecran, image ,&e,&alea) ;
                 SDL_Flip(ecran);
	         fprintf(f,"%s\n",image) ;

                        s=solution_e (image );
			do{
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;
			fprintf(f,"run=%d\n",run) ;
			fprintf(f,"s= %d\nr=%d\n",s,r) ;
			
      while(running)
{

	afficher_resultat (ecran,s,r,&e) ;
        SDL_Flip(ecran);
	SDL_PollEvent(&event);
        switch(event.type)
        {
	case SDL_QUIT :
            running =0 ;
	run=0 ;
	break ;
            case SDL_KEYDOWN :
						    
                  switch( event.key.keysym.sym )
                {
			             case  SDLK_ESCAPE: 
			              running= 0 ;
run=0 ;

			              break ;
case SDLK_SPACE:
running=0;
break;
			  
			   
        }
						break ;
        }
				
        }
			
	
	
	
}






}

}

fclose(f) ;
}



















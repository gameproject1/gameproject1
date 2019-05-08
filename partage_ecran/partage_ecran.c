#include <stdlib.h>
#include <stdio.h>
#include "partage_ecran.h"

background Initialiser_map (background backg)
{

backg.speed_camera1=10;
backg.camera1.x=0;
backg.camera1.y=0;
backg.camera1.h=680;
backg.camera1.w=2880;
backg.positionback1.x=0;
backg.positionback1.y=0;
backg.positionback1.w=2880;
backg.positionback1.h=680;
backg.speed_camera2=10;
backg.camera2.x=0;
backg.camera2.y=0;
backg.camera2.h=680;
backg.camera2.w=2880;
backg.positionback2.x=2880;
backg.positionback2.y=0;
backg.positionback2.w=2880;
backg.positionback2.h=680;
backg.background1=IMG_Load("map.jpg");
return backg;
}




void afficher_background(background backg,SDL_Surface*ecran)
{

SDL_BlitSurface(backg.background1,&backg.camera1,ecran,&backg.positionback1);
SDL_Flip(ecran);
SDL_BlitSurface(backg.background1,&backg.camera2,ecran,&backg.positionback2);
SDL_Flip(ecran);

}



background scrolling(background backg,SDL_Event e)
{  
SDL_PollEvent(&e);
    switch(e.type)
    {     	
case SDL_KEYDOWN:
    	
  	switch(e.key.keysym.sym)
        {
                   case SDLK_LEFT:
                   backg.camera1.x-=200;
                   break;
                   case SDLK_RIGHT:
                   backg.camera1.x+=200;
                   break;
        }
	
	
	if(backg.camera1.x>=5760)
		backg.camera1.x=5760;
	if(backg.camera1.x<=0)
		backg.camera1.x=0;
    }
return backg;	    	      
}

background scrolling1(background backg,SDL_Event e)
{  
SDL_PollEvent(&e);
    switch(e.type)
    {     	
case SDL_KEYDOWN:
    	
  	switch(e.key.keysym.sym)
        {
                   case SDLK_q:
                   backg.camera2.x-=200;
                   break;
                   case SDLK_d:
                   backg.camera2.x+=200;
                   break;
        }
	
	
	if(backg.camera2.x>=5760)
		backg.camera2.x=5760;
	if(backg.camera2.x<=0)
		backg.camera2.x=0;
    }
return backg;	    	      
}














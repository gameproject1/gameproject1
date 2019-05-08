#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
#include "trigo.h"



int main()
{
 SDL_Surface *screen=NULL,*image1,*image2;
 SDL_Rect position1,position2;
 int collusion;
 int continuer=1;
 SDL_Event event;
 //int collusion;
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
 screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 image1=IMG_Load("a.png");
 image2=IMG_Load("b.png");

 position1.x=400;
 position1.y=100;

 position2.x=100;
 position2.y=100;


SDL_EnableKeyRepeat(10,10);
 while(continuer)
 {
  SDL_WaitEvent(&event);
  switch(event.type)
  {
   case SDL_QUIT:
    continuer=0;
    break;
   case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
    {
     case SDLK_RIGHT:
      position2.x=position2.x+7;
      break;
     case SDLK_LEFT:
      position2.x=position2.x-7;
      break;
    }

  }
  collusion=collusion_trigonometrique_circonscrit(image1,image2,position1,position2);

  if(collusion)
   continuer=0;
  SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
  
  SDL_BlitSurface(image2,NULL,screen,&position2);
  SDL_BlitSurface(image1,NULL,screen,&position1);
 
  SDL_Flip(screen);
  
 }
//-----------------------------------------
 SDL_FreeSurface(image1);
 SDL_FreeSurface(image2);
 SDL_Quit();
}


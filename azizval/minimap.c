#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"
#define LARGEUR_SPRITE 32    
#define HAUTEUR_SPRITE 32



mini init(mini m)
{

    m.rectangle=NULL;
    m.radar=IMG_Load("h.png");
    m.posradar.x=400;
    m.posradar.y=500;
    m.posradar.h=5;
    m.posradar.w=5;
    m.position.x =400; 
    m.position.y = 500;
    SDL_Init(SDL_INIT_VIDEO);
    m.rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 200, 32, 0, 100, 100, 0);
    
return m;
}

void minimap(SDL_Surface *screen, SDL_Event *event,mini m,int continuer)
{
int x=100;
SDL_Delay(x);
if (m.posradar.x<220||m.posradar.y<720)
 {
SDL_PollEvent(event);
switch(event->type)
{
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_KEYDOWN:
        switch(event->key.keysym.sym)
        {
            case SDLK_UP:    
                m.posradar.y=m.posradar.y-1;
                x = 50;
                break; 
            case SDLK_DOWN:
                
                m.posradar.y=m.posradar.y+1;
                 x = 50;
                break;
            case SDLK_RIGHT:
                x = 50;
                 m.posradar.x=m.posradar.x+1;             
                break;
            case SDLK_LEFT:
                m.posradar.x=m.posradar.x-1;
                x = 50;
                break;
}
}

    }

   else
{
   m.posradar.x=0;
   m.posradar.y=580;
   
	
}
}
void afficher(mini m,SDL_Surface*screen)
{
    SDL_BlitSurface(m.rectangle, NULL, screen, &(m.position)); 
    SDL_BlitSurface(m.radar,NULL,screen,&(m.posradar));
    SDL_Flip(screen); 
}






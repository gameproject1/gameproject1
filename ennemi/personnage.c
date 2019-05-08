
#include "personnage.h"


int main(int argc, char**argv[])
{
    SDL_Surface *ecran = NULL, *fond= NULL, *ennemie= NULL;
    SDL_Rect positionfond, positionennemie;
 
    positionennemie.x = 295;
    positionennemie.y = 250;
    positionfond.x = 0;
    positionfond.y = 0;
int ecranheight =1080;
int ecranwidth=1520;
 
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(1500,600,32, SDL_HWSURFACE);
    fond = IMG_Load("room.png");
    ennemie = IMG_Load("per.png");
 
    int continuer = 1;
 
    while(continuer)
    {
        SDL_Event event;
        SDL_WaitEvent(&event);
 
        switch(event.type)
        {
            case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            case SDLK_ESCAPE:
            continuer = 0;
            break;
          case SDLK_UP:
            positionennemie.y-=10;
            break;
          case SDLK_DOWN:
	    if(positionennemie.y+ennemie->h+10<ecranheight) 
                 positionennemie.y+=10;
            break;
          case SDLK_LEFT:
            positionennemie.x-=10;
            break;
          case SDLK_RIGHT:
 	    if(positionennemie.x+ennemie->w+10<ecranwidth) 
                 positionennemie.x+=10;
            break;
        }

        break;
}
        SDL_FillRect (ecran, NULL, SDL_MapRGB(ecran->format, 255,255,255));
        SDL_BlitSurface(fond, NULL, ecran, &positionfond);
        SDL_BlitSurface(ennemie, NULL, ecran, &positionennemie);
        SDL_Flip(ecran);
        SDL_Flip(fond);
        SDL_Flip(ennemie);
        
    }
    SDL_FreeSurface(ennemie);
    SDL_FreeSurface(fond);
    SDL_Quit();
    return EXIT_SUCCESS;
}


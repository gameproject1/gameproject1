#include <stdlib.h>
#include <stdio.h>
#include "partage_ecran.h"


int main()
{

    SDL_Surface*ecran=NULL;
    background backg;
    backg=Initialiser_map(backg);
    SDL_Event e;
    int continuer=1;
    SDL_Init(SDL_INIT_EVERYTHING);
    ecran = SDL_SetVideoMode(5760,680, 32, SDL_HWSURFACE);
    while(continuer)
    {
        afficher_background(backg,ecran);
        backg=scrolling(backg,e);
        backg=scrolling1(backg);
        //afficher_background(backg,ecran);
        SDL_PollEvent(&e);
        switch(e.type)
        {
            case SDL_QUIT:
            continuer=0 ;
            break;
        }


    }
    SDL_Quit();




return 0;
}

#include"score.h"


score init_score(score s)
{


    s.continuer=1;
    s.texte=NULL;
    SDL_Color couleurRouge={255 , 0 , 0};
    SDL_Color couleurBlanche = {255, 255, 255};
    s.police = NULL;
    s.tempsActuel = 0; 
    s.tempsPrecedent = 0;
    s.compteur = 0;
    s.temps[20]=""; 
    s.police = TTF_OpenFont("arial.ttf",20);   
    sprintf(s.temps, "TEMPS:%d", s.compteur);
    s.texte = TTF_RenderText_Shaded(s.police, s.temps, couleurRouge,couleurBlanche );
    s.position.x = 300;
    s.position.y = 8;
return s;

}

void scor(score s,SDL_Surface *ecran,SDL_Event *event)
{
        SDL_Color couleurRouge={255 , 0 , 0};
        SDL_Color couleurBlanche = {255, 255, 255};
        SDL_PollEvent(event);
        switch(event->type)
        {
            case SDL_QUIT:
               s. continuer = 0;
                break;
        }
        s.tempsActuel = SDL_GetTicks();
        if (s.tempsActuel - s.tempsPrecedent >= 1000) 
        {
            s.compteur += 1; 
            sprintf(s.temps, "TEMPS : %d", s.compteur); 
            SDL_FreeSurface(s.texte);
            s.texte = TTF_RenderText_Shaded(s.police, s.temps, couleurRouge, couleurBlanche);
            s.tempsPrecedent = s.tempsActuel; 
		if(s.compteur == 0){s.continuer = 0;}
        }
       
        SDL_BlitSurface(s.texte, NULL, ecran, &s.position);  
        SDL_Flip(ecran);
	SDL_Delay(100);

}

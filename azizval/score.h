#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
 
typedef struct score
{
SDL_Rect position;
 int tempsActuel,tempsPrecedent,compteur;
 SDL_Surface*texte;
 TTF_Font *police;
char temps[20];
int continuer;

}score;

#ifndef SCORE_H
#define SCORE_H

/*#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES//evité les inculsions infinies*/


//jeu
score init_score(score s);
void scor(score ss,SDL_Surface *ecran,SDL_Event *event);

#endif

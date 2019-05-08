#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
 #include <unistd.h>
#include <math.h>


typedef struct menu
{
    SDL_Surface * img0;
    SDL_Surface * img1;
    SDL_Surface * img2;
    SDL_Surface * img3;
    SDL_Surface * img4;
    SDL_Surface * img5;
    SDL_Surface * img10;
    SDL_Surface *GIF_Img[10];
    SDL_Event event;
    SDL_Rect positionecran;
    Mix_Music *music;
    int c;
    int po;
    int i;
    int action;
}menu;

typedef struct personnage{

    SDL_Surface *afficher_heror[10];
    SDL_Surface *afficher_herol[10];
    SDL_Rect pos_hero;
    SDL_Rect pos_hero2;

    int mouvment;
    int farm;
    int etat;
}perso;

typedef struct background{

    SDL_Surface *afficher_background;
    SDL_Rect pos_background;
    SDL_Rect pos_background2;
    //SDL_Surface *calque_background;
}background;
typedef struct ob {
    SDL_Surface *image;
    SDL_Rect pos_image;
    int x;
    int k1;
    int k2;
    }entite;
typedef struct 
{
 SDL_Surface * img;
 SDL_Rect p;
}enigme;



typedef struct mini
{

    SDL_Surface*rectangle;
    SDL_Rect position;
    SDL_Rect posradar1;
    SDL_Rect posradar;
    SDL_Surface *radar;
   
}mini;


void initialiser_entite(entite *cd,entite *cg,entite *dc, entite *dop ,entite*bijoux,entite*money,entite*password,entite*cle);
void affichage_entite(SDL_Surface *screen,entite *cd,entite*cg,entite*dc, entite *dop,entite*bijoux,entite*money,entite*password,entite*cle,int mouvment);
void initialiser_menu(menu *menu,SDL_Surface *ecran);
void affichermenu(menu *menu,SDL_Surface *ecran);
void init_enigme(enigme * e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;
int solution_e (char image []) ;
int resolution (int * running,int *run);
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;
void initialiser_background(background *bckg);
void afficher_background(background bckg,SDL_Surface *ecran);
void scrolling (perso *aziz,background *bckg );
void initialiser_perso(perso *aziz);
void afficher_perso(perso aziz,SDL_Surface *ecran);
int animation_perso(perso aziz);
int mouvment(perso aziz,SDL_Event *event);
mini init(mini m);
void minimap(SDL_Surface*ecran,SDL_Event *event,mini m,int continuer);
void afficher(mini m,SDL_Surface*screen);
#endif

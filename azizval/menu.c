#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"struct.h"




void initialiser_menu(menu *menu,SDL_Surface *ecran){


    menu->img0=NULL;
    menu->img1=NULL;
    menu->img2=NULL;
    menu->img3=NULL;
    menu->img4=NULL;
    menu->img5=NULL;
    menu->img10=NULL;

    menu->GIF_Img[0]=NULL;
    menu->GIF_Img[1]=NULL;
    menu->GIF_Img[2]=NULL;
    menu->GIF_Img[3]=NULL;
    menu->GIF_Img[4]=NULL;
    menu->GIF_Img[5]=NULL;
    menu->GIF_Img[6]=NULL;
    menu->GIF_Img[7]=NULL;
    menu->GIF_Img[8]=NULL;

    menu->img0=IMG_Load("menu1.jpg");
    menu->img1=IMG_Load("im3.jpg");
    menu->img2=IMG_Load("im2.jpg");
    menu->img3=IMG_Load("im1.jpg");
    menu->img4=IMG_Load("menu.jpg");
    menu->img5=IMG_Load("map.jpg");
    menu->img10=IMG_Load("im10.jpg");
    menu->GIF_Img[0]=IMG_Load("a1.jpg");
    menu->GIF_Img[1]=IMG_Load("a2.jpg");
    menu->GIF_Img[2]=IMG_Load("a4.jpg");
    menu->GIF_Img[3]=IMG_Load("a3.jpg");
    menu->GIF_Img[4]=IMG_Load("a5.jpg");
    menu->GIF_Img[5]=IMG_Load("a6.jpg");
    menu->GIF_Img[6]=IMG_Load("a7.jpg");
    menu->GIF_Img[7]=IMG_Load("a8.jpg");
    menu->GIF_Img[8]=IMG_Load("a9.jpg");

    menu->c=1;
    menu->positionecran.x=0;
    menu->positionecran.y=0;
    putenv("SDL_VIDEO_CENTRED=1");
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    menu->music=Mix_LoadMUS("aziz.mp3");
    Mix_PlayMusic(menu->music,-1);
    menu->action=1;


}
void affichermenu(menu *menu,SDL_Surface *ecran)
{

    int x,y;


   
        SDL_WaitEvent(&menu->event);
        switch(menu->event.type)
        {
        case SDL_QUIT :
            menu->action=0;
            break;
         case SDL_KEYDOWN:
                switch(menu->event.key.keysym.sym)
                {
                              case SDLK_ESCAPE:
                        SDL_QUIT;
                        menu->action=0;
                        break;
		      case SDLK_DOWN:
			
			if (menu->po==0){
				SDL_BlitSurface(menu->img1, NULL, ecran, &menu->positionecran);
                                SDL_Flip(ecran);
				menu->po=1;
			}
			else if (menu->po==1){
				SDL_BlitSurface(menu->img2, NULL, ecran, &menu->positionecran);
                                  SDL_Flip(ecran);
				menu->po=2;
			}
			else if (menu->po==2){
				SDL_BlitSurface(menu->img3, NULL, ecran, &menu->positionecran);
                                SDL_Flip(ecran);
				menu->po=3;
			}
			
			break;
		               case SDLK_UP:
                          if (menu->po==2)
                        {
				SDL_BlitSurface(menu->img2, NULL, ecran, &menu->positionecran);
                                SDL_Flip(ecran);
				menu->po=1;
			}
			else if (menu->po==1){
				SDL_BlitSurface(menu->img1, NULL, ecran, &menu->positionecran);
                                SDL_Flip(ecran);
				menu->po=0;
			}
			else if (menu->po==3){
				SDL_BlitSurface(menu->img3, NULL, ecran, &menu->positionecran);
                                SDL_Flip(ecran);
				menu->po=2;
			
			}
			
			break;
		}
		break;
        case SDL_MOUSEBUTTONUP:
             menu->action=10;
            if ((menu->event.button.x >170 )&& (menu->event.button.x<320 )&&  (menu->event.button.y>520)&&( menu->event.button.y<590))
{
                menu->action=0;
}
else if((170<=menu->event.button.x)&&(menu->event.button.x<=320)&&(menu->event.button.y<=470)&&(410<=menu->event.button.y))
{
  SDL_BlitSurface(menu->img4, NULL, ecran, &menu->positionecran);
  SDL_Flip(ecran);
  SDL_Delay(2500);
}
else if((180<=menu->event.button.x)&&(menu->event.button.x<=305)&&(menu->event.button.y<=350)&&(280<=menu->event.button.y))
{
  SDL_BlitSurface(menu->img5, NULL, ecran, &menu->positionecran);
  SDL_Flip(ecran);
  SDL_Delay(2000);
/*while((60<=event.button.x)&&(event.button.x<=200)&&(event.button.y<=335)&&(200<=event.button.y))
{*/
for(menu->i=0;menu->i<9;menu->i++)
{

		SDL_BlitSurface(menu->GIF_Img[menu->i], NULL, ecran, &menu->positionecran);
		SDL_Flip(ecran);
		SDL_Delay(2000);
              
}
SDL_BlitSurface(menu->img10, NULL, ecran, &menu->positionecran);
  SDL_Flip(ecran);
  SDL_Delay(3000);
//}
}
            break;

       case SDL_MOUSEMOTION:

            if ((180<=menu->event.motion.x)&&(menu->event.motion.x<=305)&&(menu->event.motion.y<=350)&&(280<=menu->event.motion.y))
            {
                SDL_BlitSurface(menu->img1, NULL, ecran, &menu->positionecran);
                SDL_Flip(ecran);
            }
            else if ((170<=menu->event.motion.x)&&(menu->event.motion.x<=320)&&(menu->event.motion.y<=470)&&(410<=menu->event.motion.y))
            {
                SDL_BlitSurface(menu->img2, NULL, ecran, &menu->positionecran);
                   SDL_Flip(ecran);



            }
            else if ((170<=menu->event.motion.x)&&(menu->event.motion.x<=320)&&(menu->event.motion.y<=590)&&(520<=menu->event.motion.y))
            {
                SDL_BlitSurface(menu->img3, NULL, ecran, &menu->positionecran);
                SDL_Flip(ecran);
            }

            else
            {
                SDL_BlitSurface(menu->img0, NULL, ecran, &menu->positionecran);
                 SDL_Flip(ecran);
            }

            break;


        }
       SDL_Flip(ecran);
    }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
#include "trigo.h"

int collusion_trigonometrique_circonscrit(SDL_Surface *image1, SDL_Surface *image2,SDL_Rect position_image1,SDL_Rect position_image2)
{
 float centre1_x=position_image1.x+(position_image1.w/2);
 float centre1_y=position_image1.y+(position_image1.h/2);
 float r1,distance;
 double a=(position_image1.w/2)*(position_image1.w/2)+(position_image1.h/2)*(position_image1.h/2) ;

  r1=sqrt(a);

 float centre2_x=position_image2.x+(position_image2.w/2);
 float centre2_y=position_image2.y+(position_image2.h/2);
 float r2;
 a=(position_image2.w/2)*(position_image2.w/2)+(position_image2.h/2)*(position_image2.h/2) ;
 r2=sqrt(a);

 a=(centre2_x-centre1_x)*(centre2_x-centre1_x)+(centre2_y-centre1_y)*(centre2_y-centre1_y);
 distance=sqrt(a)-r1-r2 ;
 //printf("centre1:(%f,%f)"\ncentre
 if(distance<=0)
  return 1;
 else
  return 0;
}
//-----------------------------------------------------------------------------------------------




#include "menu.h"
int main()
{
    SDL_Surface *ecran=NULL,*img0=NULL,*img1=NULL,*img2=NULL,*img3=NULL,*img4=NULL,*img5=NULL;
    SDL_Event event;
    SDL_Rect positionecran;

    Mix_Music *music;

    int continuer=1;
    int c=1;
    int x,y;
    img0=IMG_Load("M.png");
    img1=IMG_Load("M-1.png");
    img2=IMG_Load("M-2.png");
    img3=IMG_Load("M-3.png");
    img4=IMG_Load("M-4.png");
    img5=IMG_Load("MAP.png");


    positionecran.x=0;
    positionecran.y=0;
    putenv("SDL_VIDEO_CENTRED=1");
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    ecran=SDL_SetVideoMode(704,704,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    music=Mix_LoadMUS("aziz.mp3");
    Mix_PlayMusic(music,-1);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT :
            continuer=0;
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.motion.x >550 && event.motion.x<672 && event.motion.y>503&& event.motion.y<590)
{
                exit(0);
}
else if((550<=event.motion.x)&&(event.motion.x<=672)&&(event.motion.y<=210)&&(123<=event.motion.y))
{

 SDL_BlitSurface(img5, NULL, ecran, &positionecran);
  SDL_Flip(ecran);
SDL_Delay(200);
}
            break;

 case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
            case SDLK_ESCAPE:
                        SDL_QUIT;
                        continuer=0;
                        break;
}
break;

       case SDL_MOUSEMOTION:

            if ((550<=event.motion.x)&&(event.motion.x<=672)&&(event.motion.y<=210)&&(123<=event.motion.y))
            {
                SDL_BlitSurface(img1, NULL, ecran, &positionecran);
                SDL_Flip(ecran);
            }
            else if ((553<=event.motion.x)&&(event.motion.x<=672)&&(event.motion.y<=337)&&(250<=event.motion.y))
            {
                SDL_BlitSurface(img2, NULL, ecran, &positionecran);
                   SDL_Flip(ecran);



            }
            else if ((550<=event.motion.x)&&(event.motion.x<=672)&&(event.motion.y<=465)&&(381<=event.motion.y))
            {
                SDL_BlitSurface(img3, NULL, ecran, &positionecran);
                SDL_Flip(ecran);



            }
            else if ((553<=event.motion.x)&&(event.motion.x<=672)&&(event.motion.y<=590)&&(503<=event.motion.y))
            {
                SDL_BlitSurface(img4, NULL, ecran, &positionecran);
                  SDL_Flip(ecran);

            }
            else
            {
                SDL_BlitSurface(img0, NULL, ecran, &positionecran);
                 SDL_Flip(ecran);
            }

            break;


        }
       SDL_Flip(ecran);

    }
    Mix_FreeMusic(music);
    SDL_FreeSurface(ecran);
    Mix_Quit();
    return EXIT_SUCCESS;
}
















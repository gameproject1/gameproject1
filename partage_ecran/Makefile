prog:main.o partage_ecran.o
		gcc main.o partage_ecran.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
		gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
partage_ecran.o:partage_ecran.c
		gcc -c partage_ecran.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

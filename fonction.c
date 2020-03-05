#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void Initialiser(SDL_Surface *ecran){
	int i,d;
	int Zone1[]={1,2,3,1,3,2};
	int Zone2[]={0,0,0,0,0,0};
	SDL_Surface *objet=NULL;
	SDL_Rect positionobjet;
    positionobjet.x=68;
    positionobjet.y=68;
	for(i=0;i<6;i++){
		d=Zone1[i];
		switch(d){
			case 1:
				objet=SDL_LoadBMP("Cercle.bmp");
				positionobjet.x+=75;
				SDL_BlitSurface(objet, NULL, ecran, &positionobjet);
				SDL_Flip(ecran);
				break;
			case 2:
				objet=SDL_LoadBMP("Rectangle.bmp");
				positionobjet.x+=75;
				SDL_BlitSurface(objet, NULL, ecran, &positionobjet);
				SDL_Flip(ecran);
				positionobjet.x-=32;
				break;
			case 3:
				objet=SDL_LoadBMP("Carré.bmp");
				positionobjet.x+=75;
				SDL_BlitSurface(objet, NULL, ecran, &positionobjet);
				SDL_Flip(ecran);
				break;
		}
	}
	return;
	
}
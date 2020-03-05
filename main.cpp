#include "constantes.h"
#include "fonction.c"

int main(int argc, char *argv[]){
    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*imageDeF= NULL ;
    SDL_Rect positionFond,positionF;
    positionF.x=0;
    positionF.y=0;
    positionFond.x = 0;
    positionFond.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("ROBOT", NULL);
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);


    /* Chargement d'une image Bitmap dans une surface */
    imageDeFond = SDL_LoadBMP("MAMADO.bmp");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_Flip(ecran);
    int continuer = 1;
    SDL_Event event;
    while (continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_SPACE: /* Appui sur la touche Echap, on arrête le programme */
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
                        SDL_Flip(ecran);
                        Initialiser(ecran);
                        break;

                }
                break;
        }

    }
    SDL_FreeSurface(imageDeF);
    SDL_FreeSurface(imageDeFond); /* On libère la surface */
    SDL_Quit();
    return 0;
}


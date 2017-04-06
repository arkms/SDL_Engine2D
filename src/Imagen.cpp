#include "Imagen.h"
#include <iostream>

#include "Game.h"
#include "SDL_image.h"

Imagen::Imagen()
{
    //ctor
}

Imagen::~Imagen()
{
    SDL_DestroyTexture(texture); ///kuLiberamos memoria
}

void Imagen::CargarImagen(const char* _path, int _x=0, int _y=0)
{
    SDL_Surface* temp = NULL;
    //temp = SDL_LoadBMP(_path); ///Cargamos imagen
    temp = IMG_Load(_path); ///Cargamos imagen

    texture = SDL_CreateTextureFromSurface(g_game.renderer, temp);

    SDL_FreeSurface(temp); ///Liberamos temp,, (Asi lo indica SDL)

    x= _x;
    y = _y;
}

void Imagen::Dibujar()
{
    SDL_RenderCopy(g_game.renderer, texture, NULL, NULL);
}

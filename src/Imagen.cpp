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

    ///Obtenemos W y H de la textura
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    ///ASignamos
    ImgPos.x = _x;
    ImgPos.y = _y;
    ImgPos.w = w;
    ImgPos.h = h;
}

void Imagen::CargarImagen(const char* _path, int _x, int _y, int _MascaraR, int _MascaraG, int _MascaraB)
{
    SDL_Surface* temp = NULL;
    temp = SDL_LoadBMP(_path); ///Cargamos imagen

    SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, _MascaraR, _MascaraG, _MascaraB));

    texture = SDL_CreateTextureFromSurface(g_game.renderer, temp);

    SDL_FreeSurface(temp); ///Liberamos temp,, (Asi lo indica SDL)

    ///Obtenemos W y H de la textura
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    ///ASignamos
    ImgPos.x = _x;
    ImgPos.y = _y;
    ImgPos.w = w;
    ImgPos.h = h;
}

void Imagen::Dibujar()
{
    SDL_RenderCopy(g_game.renderer, texture, NULL, &ImgPos);
}

///Set y Gets--------------------------------

void Imagen::SetPos(int _x, int _y)
{
    ImgPos.x = _x;
    ImgPos.y = _y;
}

void Imagen::SetX(int _x)
{
    ImgPos.x = _x;
}

void Imagen::SetY(int _y)
{
    ImgPos.y = _y;
}

int Imagen::GetX()
{
    return ImgPos.x;
}

int Imagen::GetY()
{
    return ImgPos.y;
}

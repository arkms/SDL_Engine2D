#ifndef IMAGEN_H
#define IMAGEN_H

//#include "Game.h"
#include "SDL.h"

class Imagen
{
    public:
        Imagen();
        virtual ~Imagen();

        void CargarImagen(const char* _path, int _x, int _y);
        void CargarImagen(const char* _path, int _x, int _y, int _MascaraR, int _MascaraG, int _MascaraB);
        void Dibujar();

        ///Set y Gets de posicion
        void SetPos(int _x, int _y);
        void SetX(int _x);
        void SetY(int _y);
        int GetX();
        int GetY();

    protected:

    private:
        SDL_Texture* texture;
        SDL_Rect ImgPos;

};

#endif // IMAGEN_H

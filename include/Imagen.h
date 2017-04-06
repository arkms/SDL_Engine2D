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
        void Dibujar();

        int x;
        int y;

    protected:

    private:
        SDL_Texture* texture;

};

#endif // IMAGEN_H

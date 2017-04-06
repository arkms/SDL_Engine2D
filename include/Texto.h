#ifndef TEXTO_H
#define TEXTO_H

#include "SDL.h"

class Texto
{
    public:
        Texto();
        ~Texto();

        /// Permite asignar el texto y de paso indicar posicion y color, perfecto para inicializar
        void SetText(const char* _texto, int _posX, int _posY, int _r, int _g, int _b);
        void SetText(const char* _texto, int _posX, int _posY);
        ///Asignamos texto
        void SetText(const char* _texto);
        void SetColor(int _r, int _g, int _b);
        void SetPos(int _x, int _y);
        ///Dibuja en pantalla
        void Dibujar();
        const SDL_Rect& GetRect();
        ///Indicar que las coordenas se usaran como punto medio, debe activarse antes que caulquier cosa
        void ActivarCoordenasCentral();

    private:
        SDL_Color textColor;
        SDL_Rect renderQuad;
        bool coordMedio; ///Se usara coordenadas como punto central?
        SDL_Texture* text;
        char* text_;
};

#endif // TEXTO_H

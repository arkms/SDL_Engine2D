#ifndef BUTTON_H
#define BUTTON_H

#include "Texto.h"

class Button
{
    public:
        Button();
        ~Button();
        void Iniciar(const char* _texto, int _posX, int _posY);
        void SetPos(int _posX, int _posY);
        Texto* GetText();
        bool IsPresionado(int _mouseX, int _mouseY);
        void Dibujar();

    protected:

    private:
        Texto text;
        SDL_Rect rect;


};

#endif // BUTTON_H

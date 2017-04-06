#include "Button.h"
#include "DrawBasic.h"

Button::Button()
{}

Button::~Button()
{}

void Button::Iniciar(const char* _texto, int _posX, int _posY)
{
    text.ActivarCoordenasCentral();
    text.SetText(_texto, _posX, _posY);
    rect = text.GetRect();
    ///Agregamos 2 pixeles en cada lado para que el cuadro no tape la imagen
    rect.x -= 2;
    rect.y -= 2;
    rect.w += 2;
    rect.h += 2;
}

void Button::SetPos(int _posX, int _posY)
{
    text.SetPos(_posX, _posY);
    rect = text.GetRect();
    ///Agregamos 2 pixeles en cada lado para que el cuadro no tape la imagen
    rect.x -= 2;
    rect.y -= 2;
    rect.w += 2;
    rect.h += 2;
}

Texto* Button::GetText()
{
    return &text;
}

bool Button::IsPresionado(int _mouseX, int _mouseY)
{
    if(rect.x < _mouseX && rect.x + rect.w > _mouseX)
    {
        if(rect.y < _mouseY && rect.y + rect.h > _mouseY)
        {
            return true;
        }
    }

    return false;
}

void Button::Dibujar()
{
    DrawBasic::SetDrawColor(0, 0, 0);
    DrawBasic::Draw_Cube(rect);
    text.Dibujar();
}

#include "Texto.h"

#include "Game.h"

Texto::Texto()
{
    textColor = { 0, 0, 0, SDL_ALPHA_OPAQUE };
    coordMedio= false;
}

Texto::~Texto()
{
    SDL_DestroyTexture(text);
    delete text_;
}

void Texto::SetText(const char* _texto, int _posX, int _posY, int _r, int _g, int _b)
{
    SetColor(_r, _g, _b);
    SetPos(_posX, _posY);
    SetText(_texto);
}

void Texto::SetText(const char* _texto, int _posX, int _posY)
{
    SetPos(_posX, _posY);
    SetText(_texto);
}

void Texto::SetText(const char* _texto)
{
    if(text_ != NULL) ///Evitamos fuga de memoria
        delete text_;
    text_ = (char*)_texto; ///Respaldamos texto
    ///Generamos texto
    SDL_Surface* textSurface = TTF_RenderText_Solid(g_game.gFont, "Hola Mundo", textColor);
    text = SDL_CreateTextureFromSurface(g_game.renderer, textSurface);
    ///Ajustamos posicion
    int text_width = textSurface->w;
    int text_height = textSurface->h;
    SDL_FreeSurface(textSurface);
    if(coordMedio == false)
    {
        renderQuad.w = text_width; renderQuad.h = text_height;
    }
    else
    {
        ///Tenemos que sumar la mitad de ancho y largo anterior para ajustarlo correctamente
        renderQuad.x = renderQuad.x - text_width/2 + renderQuad.w/2;
        renderQuad.y = renderQuad.y - text_height/2 + renderQuad.h/2;
        renderQuad.w = text_width; renderQuad.h = text_height;
    }
}

void Texto::SetColor(int _r, int _g, int _b)
{
    ///Cambiamos de Color
    textColor.r= _r;
    textColor.g= _g;
    textColor.b= _b;
    ///Tenemos que regenerar textura
    SDL_Surface* textSurface = TTF_RenderText_Solid(g_game.gFont, text_, textColor);
    text = SDL_CreateTextureFromSurface(g_game.renderer, textSurface);
    SDL_FreeSurface(textSurface);
}

void Texto::SetPos(int _posX, int _posY)
{
    if(coordMedio == false)
    {
        renderQuad.x = _posX;
        renderQuad.y = _posY;
    }
    else ///Tomar centro como coordenadas centrales
    {
        if(text == NULL) ///Es la priemra vez que se llama setPos, ponemos w y h en 0 para que no haga dagas
        {
            renderQuad.w= renderQuad.h = 0;
        }
        renderQuad.x = _posX - renderQuad.w/2;
        renderQuad.y = _posY - renderQuad.h/2;
    }
}

void Texto::Dibujar()
{
    SDL_RenderCopy(g_game.renderer, text, NULL, &renderQuad);
}

const SDL_Rect& Texto::GetRect()
{
    return renderQuad;
}

void Texto::ActivarCoordenasCentral()
{
    if(text == NULL)
    {
        coordMedio= true;
    }
}

#include "DrawBasic.h"
#include <math.h>

namespace DrawBasic
{
    void Draw_Point(int _x, int _y)
    {
        SDL_RenderDrawPoint(g_game.renderer, _x, _y);
    }

    void Draw_Line(int _x1, int _y1, int _x2, int _y2)
    {
        SDL_RenderDrawLine(g_game.renderer, _x1, _y1, _x2, _y2);
    }

    void Draw_Cube(int _x, int _y, int _w, int _h)
    {
        SDL_Rect CuboRect ;
        CuboRect.x = _x - _w/2;
        CuboRect.y = _y - _h /2;
        CuboRect.w = _w ;
        CuboRect.h = _h ;
        SDL_RenderDrawRect(g_game.renderer, &CuboRect);
    }

    void Draw_Cube(SDL_Rect _rect)
    {
        SDL_RenderDrawRect(g_game.renderer, &_rect);
    }

    void Draw_FillCube(int _x, int _y, int _w, int _h)
    {
        SDL_Rect CuboRect ;
        CuboRect.x = _x - _w/2;
        CuboRect.y = _y - _h /2;
        CuboRect.w = _w ;
        CuboRect.h = _h ;
        SDL_RenderFillRect(g_game.renderer, &CuboRect);
    }

    void Draw_Sphere(int _x, int _y, int _r)
    {
        const float lados = 18.0f;
        const float d_a = 6.28318530f / lados;
        float angle = d_a;

        int x1, y1, x2, y2;
        x2 = _r + _x;
        y2 = _y;

        for (int i=0; i!=lados; i++)
        {
            x1 = x2;
            y1 = y2;
            x2 = cos(angle) * _r;
            y2 = sin(angle) * _r;
            x2+= _x;
            y2+= _y;
            angle += d_a;
            Draw_Line(x1, y1, x2, y2);
        }
    }

    void Draw_FillSphere(int _x, int _y, int _r)
    {
        int r2 = _r * 2;
        int rpow2 = _r * _r;
        for (int w = 0; w < r2; w++)
        {
            for (int h = 0; h < r2; h++)
            {
                int dx = _r - w;
                int dy = _r - h;
                if ((dx*dx + dy*dy) <= (rpow2))
                {
                    Draw_Point(_x + dx, _y + dy);
                }
            }
        }
    }

    SDL_Color GetColor(int _r, int _g, int _b, int _a= 255)
    {
        SDL_Color col = {_r, _g, _b, _a};
        return col;
    }
}



#ifndef DRAWBASIC_H
#define DRAWBASIC_H

#include "Game.h"

namespace DrawBasic
{
    inline void SetDrawColor(int _r, int _g, int _b)
    {
        SDL_SetRenderDrawColor(g_game.renderer, _r, _g, _b, SDL_ALPHA_OPAQUE);
    }

    void Draw_Point(int _x, int _y);

    void Draw_Line(int _x1, int _y1, int _x2, int _y2);

    void Draw_Cube(int _x, int _y, int _w, int _h);

    void Draw_Cube(SDL_Rect _rect);

    void Draw_FillCube(int _x, int _y, int _w, int _h);

    void Draw_Sphere(int _x, int _y, int _r);

    void Draw_FillSphere(int _x, int _y, int _r);

    SDL_Color GetColor(int _r, int _g, int _b, int _a);
};

#endif // DRAWBASIC_H

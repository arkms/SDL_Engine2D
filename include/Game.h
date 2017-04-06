#ifndef GAME_H
#define GAME_H
///Basado en http://windrealm.org/tutorials/sdl/sdl2-base-cpp.php


#include "SDL.h"
#include "SDL_ttf.h"
#include "Imagen.h"
#include <map>
#include "Texto.h"
#include "Button.h"

class Game
{
    public:
        Game();
        ~Game();
        void start(); ///Iniciador
        void stop() ; ///cerrar ventana
        void Init(); ///Funcion para iniciar
        void fpsChanged( int fps ); ///Solo imprime en el titulo de la ventana los fps
        void onQuit(); ///Se llama para salir
        void onKeyDown( SDL_Event* event ); ///Detectar un DOWN
        void onKeyUp( SDL_Event* event ); ///Detectar un UP
        void onMouse( SDL_Event* event ); ///Detectar evento de mouse
        void run(); ///Ejecuta la ventana
        void update();
        void draw();

        SDL_Renderer* renderer;
        TTF_Font *gFont = NULL; ///Fuente global
private:
        std::map<int,int> keys;
        int frameSkip ;
        bool running ;
        SDL_Window* window;

        Imagen img;
        Texto txt1;
        Button btn1;

};

extern Game g_game;

#endif // GAME_H

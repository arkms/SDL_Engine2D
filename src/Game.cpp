#include "Game.h"
#include "SDL_image.h" ///No remover
#include "DrawBasic.h"
#include <cstdio>
#include <iostream>

const int DISPLAY_WIDTH  = 480;
const int DISPLAY_HEIGHT = 320;
const float UPDATE_INTERVAL = 1000.0f/60.0f;

Game g_game; ///Singleton

//https://github.com/ocornut/imgui

void Game::draw()
{
    ///Limpiamos ventana
    DrawBasic::SetDrawColor(255, 255, 255); ///Color de limpiar pantalla
    SDL_RenderClear(renderer);


    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    DrawBasic::SetDrawColor(255, 0, 0);
    DrawBasic::Draw_Line(0, 0, 200, 200);

    DrawBasic::SetDrawColor(0, 255, 0);
    DrawBasic::Draw_Point(300, 300);

    DrawBasic::SetDrawColor(0, 0, 255);
    DrawBasic::Draw_Cube(200, 200, 50, 50);

    DrawBasic::Draw_Sphere(250, 50, 30);

    txt1.Dibujar();

    btn1.Dibujar();

    ///Dibujar imagen
    //img.Dibujar();

    ///Terminamos de dibujar
    SDL_RenderPresent(renderer);
}

void Game::update()
{
    if ( keys[SDLK_LEFT] )
    {

    }
    else if ( keys[SDLK_RIGHT] )
    {

    }
    else if ( keys[SDLK_UP] )
    {

    }
    else if ( keys[SDLK_DOWN] )
    {

    }
}

void Game::onMouse(SDL_Event* evt)
{
    ///Coordenadas del mouse
    int x = evt->motion.x;
    int y = evt->motion.y;

    //if( evt->button.button  == SDL_BUTTON_LEFT)
    //if( evt->button.button  == SDL_BUTTON_RIGHT)

    if( evt->type == SDL_MOUSEBUTTONDOWN ) ///Se presiono cloc
    {
        if(btn1.IsPresionado(x, y))
        {

            std::cout << "Presionado" << std::endl;

        }
    }
    else if( evt->type == SDL_MOUSEBUTTONUP ) ///Se solto clic
    {

    }
    if( evt->type == SDL_MOUSEMOTION ) ///Solo movimiento
    {

    }
}

///TECLAS: https://www.libsdl.org/release/SDL-1.2.15/docs/html/sdlkey.html
void Game::onKeyDown( SDL_Event* evt )
{
    keys[ evt->key.keysym.sym ] = 1 ; ///Indicamos que ese tecla esta activa
}

void Game::onKeyUp( SDL_Event* evt )
{
    keys[ evt->key.keysym.sym ] = 0 ; ///Ya no se esta llamando la tecla
}

void Game::Init()
{
    img.CargarImagen("Recursos/test_img.bmp", 50, 50);
    txt1.SetText("Hola Mundo!");
    btn1.Iniciar("Boton", 200, 200);
}


///Se llama que es hora de salir del juego
void Game::onQuit()
{
    running = false ;
}








///NO CAMBIAR de aqui para abajo,  ---------------------------------------------------------------------------------
Game::Game():frameSkip(0), running(0), window(NULL), renderer(NULL) {}

Game::~Game()
{
    this->stop();
}

void Game::start() ///Inicializa vetana
{
    int flags = SDL_WINDOW_SHOWN ;
    if (SDL_Init(SDL_INIT_EVERYTHING))
        return;

    if (SDL_CreateWindowAndRenderer(DISPLAY_WIDTH, DISPLAY_HEIGHT, flags, &window, &renderer))
        return;


    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return;
    }

    ///Cargamos la fuente para escribir
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        return;
    }

    gFont = TTF_OpenFont("Recursos/lazy.ttf", 15);

    this->running = true ;
    run();
}

void Game::stop() ///Liberamos memoria de SDL
{
    if (NULL != renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if (NULL != window)
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }
    TTF_Quit();
    SDL_Quit();
}

void Game::run()
{
    int past = SDL_GetTicks();
    int now = past, pastFps = past ;
    int fps = 0, framesSkipped = 0 ;
    SDL_Event event ;
    Init();
    ///Ciclo de juego
    while ( running )
    {
        int timeElapsed = 0 ;
        ///Eventos (Teclado y Mouse)
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:    onQuit();
                    break;
                case SDL_KEYDOWN: onKeyDown( &event );
                    break ;
                case SDL_KEYUP:   onKeyUp( &event );
                    break ;
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEMOTION:
                    onMouse(&event);
                    break ;
            }
        }

        ///Update y Draw
        ///Esta formula ayuda que corra ya suave, por lo que omite la necesidad de usar DeltaTime
        timeElapsed = (now=SDL_GetTicks()) - past ;
        if ( timeElapsed >= UPDATE_INTERVAL  )
        {
            past = now ;
            update();
            if ( framesSkipped++ >= frameSkip )
            {
                draw();
                ++fps ;
                framesSkipped = 0 ;
            }
        }
        /// fps
        if ( now - pastFps >= 1000 )
        {
            pastFps = now ;
            fpsChanged( fps );
            fps = 0 ;
        }
        ///Retraso de 1ms o SDL se congela
        SDL_Delay( 1 );
    }
}

void Game::fpsChanged( int fps )
{
    char szFps[ 128 ] ;
    sprintf( szFps, "%s: %d FPS", "Nombre de Ventana", fps );
    SDL_SetWindowTitle(window, szFps);
}

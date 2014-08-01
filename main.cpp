#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "sdlGraphics.h"
#include "menu.h"
#include <iostream>
#include <string>

using namespace std;

int quit = 1;

SDLGraphics* g_graphics = NULL;
mainMenu* g_menu = NULL;
int main(int argc, char* args[])
{
    g_graphics = new SDLGraphics(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    g_menu = new mainMenu();

    g_menu->firstLoad();
    while (quit != 0)
    {
        quit = g_menu->load();
        if (quit == 2)
        {
            g_menu->loadOptions();
        }
    }
    cout << "quit is " << quit << endl;
delete g_menu;
delete g_graphics;
return 0;

}

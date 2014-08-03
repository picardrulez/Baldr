#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "sdlGraphics.h"
#include "menu.h"
#include "game.h"
#include <iostream>
#include <string>

using namespace std;

bool gameRunning = true;

SDLGraphics* g_graphics = NULL;
mainMenu* g_menu = NULL;
game* g_game = NULL;
int main(int argc, char* args[])
{
    g_graphics = new SDLGraphics(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    g_menu = new mainMenu();
    g_game = new game();

    while (gameRunning)
    {
        g_menu->firstLoad();
        bool inMenu = true;
        int menuStatus;
        while (inMenu)
        {
            menuStatus = g_menu->load();
            if (menuStatus == 2)
            {
                menuStatus = g_menu->loadOptions();
            }
            if (menuStatus == 1)
            {
                inMenu = false;
            }
            if (menuStatus == 0)
            {
                inMenu = false;
                gameRunning = false;
            }
        }
        g_menu->menuMusic(false);
        int gameStatus = g_game->intro();
        cout << "gameStatus is " << gameStatus << endl;
        if (gameStatus == 0)
        {
            gameRunning = false;
            return 0;
        }
        cout << "starting level" << endl;
        gameStatus = g_game->level();
        if (gameStatus == 0)
        {
            gameRunning = false;
            return 0;
        }
    }
delete g_menu;
delete g_graphics;
return 0;

}

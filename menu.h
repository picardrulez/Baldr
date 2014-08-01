#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "sdlGraphics.h"

class mainMenu
{
    public:
        mainMenu();
        ~mainMenu();
        void firstLoad();
        int load();
        int loadOptions();

    private:
        string currentSelect;

        SDL_Rect StarT;
        SDL_Rect OptionS;

        SDL_Texture* background;
        SDL_Texture* blankBackground;
        SDL_Texture* start;
        SDL_Texture* startSelect;
        SDL_Texture* options;
        SDL_Texture* optionsSelect;

};

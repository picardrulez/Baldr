#include "sdlGraphics.h"
#include "player.h"
#include "input.h"

class game
{
    public:
        int intro();
        int level();
    private:
        SDL_Texture* background;
};

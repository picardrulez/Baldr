#include "sdlGraphics.h"
#include "player.h"
#include "input.h"

class game
{
    public:
        game();
        int intro();
        int level();
        void eventHandler(SDL_Event& event);
        int mVel;
    private:
        player* g_player;
        SDL_Texture* background;
};

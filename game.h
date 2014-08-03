#include "sdlGraphics.h"
#include "player.h"
#include "input.h"

class game
{
    public:
        game();
        int intro();
        int level();
        void musicOn(bool isOn);
        void eventHandler(SDL_Event& event);
        void pause();
        int mVel;
    private:
        Mix_Music * gMusic;
        player* g_player;
        SDL_Texture* background;
};

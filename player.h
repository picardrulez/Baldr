#include "sdlGraphics.h"
class player
{
    public:
        player();
        ~player();

        void moveLeft();
        void moveRight();
        void jump();
        void draw();
        bool playerFlip;
    private:
        SDL_Texture* character;
        SDL_Rect PlayeR;
};

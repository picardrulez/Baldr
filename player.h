#include "sdlGraphics.h"
class player
{
    public:
        player(int num);
        ~player();

        void moveLeft();
        void moveRight();
        void jump();
        void draw();
        void move();
        bool playerFlip;
        int geoffTest;
        static const int P_VEL = 1;
        int mVel;
//    private:
        SDL_Texture* character;
        SDL_Rect PlayeR;
};

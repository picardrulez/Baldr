#include "sdlGraphics.h"
class input
{
    public:
        input();
        ~input();
        void readInput();
        bool* getInput();
        bool windowClosed();

    private:
        SDL_Event m_event;
        bool m_keysHeld[323];
        bool m_windowClosed;
};

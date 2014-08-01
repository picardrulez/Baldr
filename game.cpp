#include "game.h"
int game::intro()
{
    bool introRunning = true;
    bool introQuit;
    int introPos = 1;
    SDL_Texture* intro1;
    SDL_Texture* intro2;
    SDL_Texture* intro3;
    intro1=loadTexture("images/intro1.png");
    intro2=loadTexture("images/intro2.png");
    intro3=loadTexture("images/intro3.png");
    cout << "starting whileloop" << endl;
    while (introRunning)
    {
        if (introPos == 0)
        {
            cout << "at introPos 0" << endl;
            SDL_DestroyTexture(intro1);
            SDL_DestroyTexture(intro2);
            SDL_DestroyTexture(intro3);
            intro1 = NULL;
            intro2 = NULL;
            intro3 = NULL;
            introRunning = false;
            if (introQuit)
            {
                cout << "returning 0" << endl;
                return 0;
            }
            else
            {
                cout << "returning 1" << endl;
                return 1;
            }
        }
        else if (introPos == 3)
        {
            cout << "at introPos 3" << endl;
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, intro3, NULL, NULL);
            SDL_RenderPresent(renderer);
            introPos = 0;
        }
        else if (introPos == 2)
        {
            cout << "at introPos 2" << endl;
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, intro2, NULL, NULL);
            SDL_RenderPresent(renderer);
            introPos = 3;
        }
        else if (introPos == 1)
        {
            cout << "at introPos 1" << endl;
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, intro1, NULL, NULL);
            SDL_RenderPresent(renderer);
            introPos = 2;
        }
    
        SDL_Event event;
        bool keypressed = false;
        while (!keypressed)
        {
            while (SDL_PollEvent(&event) != 0)
            {
                if (event.type == SDL_QUIT)
                {
                    introPos = 0;
                    introQuit = true;
                    keypressed = true;
                }
                else if (event.type == SDL_KEYDOWN)
                {
                    keypressed = true;
                }
            }
        }
    }
}

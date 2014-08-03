#include "game.h"
game::game()
{
    g_player = new player(0);
    cout << "g_player has been created, mVel is:  " << g_player->mVel << endl;
    cout << "g_player P_VEL is " << g_player->P_VEL << endl;
    cout << "g_player geoffTest is " << g_player->geoffTest << endl;
    cout << "int is broke, bandaid fixing to equal 0" << endl;
    g_player->mVel = 0;
    cout << "mVel is now:  " << g_player->mVel << endl;
    int mVel = 0;
}
int game::intro()
{
    bool introRunning = true;
    bool introQuit = false;;
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

int game::level()
{
    background = loadTexture("images/forrest.png");
    bool levelRun = true;
    bool quit = false;
    while (levelRun)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        g_player->draw();
        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                levelRun = false;
                quit = true;
            }
            eventHandler(event);
            cout << "current Location is:  " << g_player->PlayeR.x <<", " << g_player->PlayeR.y << endl;
            cout << "current mVel is:  " << g_player->mVel << endl;
        }
            g_player->move();
            g_player->draw();
        



    }
    delete g_player;
    if (quit)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void game::eventHandler(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                cout << "right pressed, adding " << g_player->P_VEL << " P_VEL " << "to" << g_player->mVel << " m_Vel" << endl;
                g_player->mVel += g_player->P_VEL;
                g_player->playerFlip = false;
                break;
            case SDLK_LEFT:
                cout << "left pressed, subtracting" << g_player->P_VEL << " P_VEL " << "to" << g_player->mVel << " m_vel" << endl;
                g_player->mVel -= g_player->P_VEL;
                g_player->playerFlip = true;
                break;
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                cout << "right released, subtracting " << g_player->P_VEL << " P_VEL " << "to" << g_player->mVel << " m_Vel" << endl;
                g_player->mVel -= g_player->P_VEL;
                g_player->playerFlip = false;
                break;
            case SDLK_LEFT:
                cout << "left released, adding " << g_player->P_VEL << " P_VEL " << "to" << g_player->mVel << " m_Vel" << endl;
                g_player->mVel += g_player->P_VEL;
                g_player->playerFlip = true;
                break;
        }
    }
}

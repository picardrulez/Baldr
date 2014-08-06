#include "game.h"
game::game()
{
    g_player = new player(0);
    bool levelRun = true;
    bool quit = false;
    cout << "g_player has been created, mVel is:  " << g_player->mVel << endl;
    cout << "g_player P_VEL is " << g_player->P_VEL << endl;
    cout << "g_player geoffTest is " << g_player->geoffTest << endl;
    cout << "int is broke, bandaid fixing to equal 0" << endl;
    g_player->mVel = 0;
    cout << "mVel is now:  " << g_player->mVel << endl;
    int mVel = 0;
    gMusic = Mix_LoadMUS("audio/mainMenu2.mp3");
}
int game::intro()
{
    musicOn(true);
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
        }
            cout << "current Location is:  " << g_player->PlayeR.x << ", " << g_player->PlayeR.y << endl;
            cout << "current mVel is:  " << g_player->mVel << endl;
            g_player->move();
            g_player->draw();
        



    }
    delete g_player;
    if (quit)
    {
        cout << "returning 0" << endl;
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
            case SDLK_ESCAPE:
                cout << "escap pressed, starting pause()" << endl;
                pause();
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

void game::musicOn(bool isOn)
{
    if (isOn)
    {
        Mix_VolumeMusic(currentMVolume);
        Mix_PlayMusic(gMusic, 1);
    }
    else
    {
        Mix_HaltMusic();
    }
}

void game::pause()
{
    bool inPause = true;
    Mix_PauseMusic();
    string currentSelect = "settings";
    int iW, iH;
    SDL_Color color = {255, 255, 255, 255 };
    SDL_Texture* Selection = loadTexture("images/redSelect.png");
    SDL_Texture* transBack;
    transBack=loadTexture("images/darkTrans.png");
    SDL_RenderCopy(renderer, transBack, NULL, NULL);
    SDL_Texture* Paused = renderText("Paused", "fonts/NewRocker.otf", color, 42, renderer);
    SDL_QueryTexture(Paused, NULL, NULL, &iW, &iH);
    SDL_Rect PauseD;
    PauseD.x = SCREEN_WIDTH / 2 - iW / 2;
    PauseD.y = 50;
    PauseD.w = iW;
    PauseD.h = iH;
    SDL_RenderCopy(renderer, Paused, NULL, &PauseD);
    SDL_Texture* Settings = renderText("Settings", "fonts/NewRocker.otf", color, 32, renderer);
    SDL_QueryTexture(Settings, NULL, NULL, &iW, &iH);
    SDL_Rect SettingS;
    SettingS.x = SCREEN_WIDTH / 2 - iW / 2;
    SettingS.y = 200;
    SettingS.w = iW;
    SettingS.h = iH;
    SDL_RenderCopy(renderer, Settings, NULL, &SettingS);
    SDL_Texture* Quit = renderText("Quit to Menu", "fonts/NewRocker.otf", color, 32, renderer);
    SDL_QueryTexture(Quit, NULL, NULL, &iW, &iH);
    SDL_Rect QuiT;
    QuiT.x = SCREEN_WIDTH / 2 - iW / 2;
    QuiT.y = 250;
    QuiT.w = iW;
    QuiT.h = iH;
    SDL_RenderCopy(renderer, Quit, NULL, &QuiT);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    SDL_Texture* lastWindow = textureWindow();

    while (inPause)
    {
        cout << "clearing" << endl;
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, lastWindow, NULL, NULL);
//        SDL_RenderCopy(renderer, transBack, NULL, NULL);
        SDL_RenderCopy(renderer, Paused, NULL, &PauseD);
        SDL_RenderCopy(renderer, Settings, NULL, &SettingS);
        SDL_RenderCopy(renderer, Quit, NULL, &QuiT);
        cout << "currentSelect is " << currentSelect << endl;
        if (currentSelect == "settings")
        {
            cout << "rendering settings" << endl;
            SDL_RenderCopy(renderer, Selection, NULL, &SettingS);
        }
        else if (currentSelect == "quit")
        {
            cout << "rendering quit" << endl;
            SDL_RenderCopy(renderer, Selection, NULL, &QuiT);
        }
        SDL_RenderPresent(renderer);

        cout << "listening for input" << endl;
        while (SDL_PollEvent(&event) !=0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                inPause = false;
                levelRun = false;
                cout << "quit is now:  " << quit << endl;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (currentSelect == "settings")
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            inPause = false;
                            break;
                        case SDLK_DOWN:
                            currentSelect = "quit";
                            break;
                    }
                }
                else if (currentSelect == "quit")
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            inPause = false;
                            break;
                        case SDLK_UP:
                            currentSelect = "settings";
                            break;
                        case SDLK_RETURN:
                            inPause = false;
                            levelRun = false;
                            break;
                    }
                }
            }
        }
    }
    Mix_ResumeMusic();
}

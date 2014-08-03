#include "menu.h"
#include "sdlGraphics.h"

mainMenu::mainMenu()
{
    background=loadTexture("images/background.png");
    blankBackground=loadTexture("images/blankBackground.png");
    start=loadTexture("images/start.png");
    startSelect=loadTexture("images/startSelected.png");
    options=loadTexture("images/options.png");
    optionsSelect=loadTexture("images/optionsSelected.png");
    mMusic = Mix_LoadMUS("audio/mainMenu1.mp3");
    gSelect = Mix_LoadWAV("audio/select.wav");
    Mix_Volume(2, currentSVolume);
    StarT.x = 110;
    StarT.y = 335;
    StarT.w = 114;
    StarT.h = 49;
    OptionS.x = 350;
    OptionS.y = 335;
    OptionS.w = 165;
    OptionS.h = 57;

}

mainMenu::~mainMenu()
{
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(blankBackground);
    SDL_DestroyTexture(start);
    SDL_DestroyTexture(startSelect);
    SDL_DestroyTexture(options);
    SDL_DestroyTexture(optionsSelect);
    Mix_FreeChunk(gSelect);
    Mix_FreeMusic(mMusic);
    background = NULL;
    blankBackground = NULL;
    start = NULL;
    startSelect = NULL;
    options = NULL;
    optionsSelect = NULL;
    mMusic = NULL;
    gSelect = NULL;
}

void mainMenu::firstLoad()
{
    cout << "firstload hass tarted" << endl;
    int ALPHA = 0;
    while ( ALPHA <= 255 )
    {
        cout << "alpha is " << ALPHA << endl;
        SDL_RenderClear(renderer);
        SDL_SetTextureBlendMode(background, SDL_BLENDMODE_BLEND);
        SDL_SetTextureAlphaMod(background, ALPHA);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_RenderPresent(renderer);
        ALPHA += 5;
        //SDL_Delay(2);
    }
    menuMusic(true);
}

int mainMenu::load()
{
    string currentSelect = "start";
    bool inMenu = true;
    while (inMenu)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        if (currentSelect == "start")
        {
            SDL_RenderCopy(renderer, startSelect, NULL, &StarT);
            SDL_RenderCopy(renderer, options, NULL, &OptionS);
        }
        else if (currentSelect == "options")
        {
            SDL_RenderCopy(renderer, start, NULL, &StarT);
            SDL_RenderCopy(renderer, optionsSelect, NULL, &OptionS);
        }

        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                inMenu = false;
                SDL_DestroyTexture(background);
                SDL_DestroyTexture(blankBackground);
                SDL_DestroyTexture(start);
                SDL_DestroyTexture(startSelect);
                SDL_DestroyTexture(options);
                SDL_DestroyTexture(optionsSelect);
                background = NULL;
                blankBackground = NULL;
                start = NULL;
                startSelect = NULL;
                options = NULL;
                optionsSelect = NULL;
                return 0;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        Mix_PlayChannel(2, gSelect, 0);
                        currentSelect = "options";
                        break;
                    case SDLK_LEFT:
                        Mix_PlayChannel(2, gSelect, 0);
                        currentSelect = "start";
                        break;
                    case SDLK_ESCAPE:
                        inMenu = false;
                        //DESTROYEVERYTHING
                        return 0;
                    case SDLK_RETURN:
                        Mix_PlayChannel(2, gSelect, 0);
                        if (currentSelect == "start")
                        {
                            inMenu = false;
                            return 1;
                        }
                        else if (currentSelect == "options")
                        {
                            return 2;
                        }
                }
            }
        }
    }
}

int mainMenu::loadOptions()
{
    bool inOptions = true;
    string optionsSelection = "difficulty";
    while (inOptions)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, blankBackground, NULL, NULL);
    
        SDL_Color color = { 255, 255, 255, 255 };
        int iW, iH;
    
        SDL_Texture* Difficulty = renderText("Difficulty", "fonts/NewRocker.otf", color, 42, renderer);
        SDL_QueryTexture(Difficulty, NULL, NULL, &iW, &iH);
        SDL_Rect DifficultY;
        DifficultY.x = SCREEN_WIDTH / 2 - iW / 2;
        DifficultY.y = 5;
        DifficultY.w = iW;
        DifficultY.h = iH;
        SDL_RenderCopy(renderer, Difficulty, NULL, &DifficultY);
    
        SDL_Texture* Easy = renderText("Easy", "fonts/NewRocker.otf", color, 32, renderer);
        SDL_QueryTexture(Easy, NULL, NULL, &iW, &iH);
        SDL_Rect EasY;
        EasY.x = SCREEN_WIDTH / 6;
        EasY.y = 75;
        EasY.w = iW;
        EasY.h = iH;
        SDL_RenderCopy(renderer, Easy, NULL, &EasY);
    
        SDL_Texture* Normal = renderText("Normal", "fonts/NewRocker.otf", color, 32, renderer);
        SDL_QueryTexture(Normal, NULL, NULL, &iW, &iH);
        SDL_Rect NormaL;
        NormaL.x = SCREEN_WIDTH / 2 -iW / 2;
        NormaL.y = 75;
        NormaL.w = iW;
        NormaL.h = iH;
        SDL_RenderCopy(renderer, Normal, NULL, &NormaL);
    
        SDL_Texture* Hard = renderText("Hard", "fonts/NewRocker.otf", color, 32, renderer);
        SDL_QueryTexture(Hard, NULL, NULL, &iW, &iH);
        SDL_Rect HarD;
        HarD.x = SCREEN_WIDTH - SCREEN_WIDTH / 4;
        HarD.y = 75;
        HarD.w = iW;
        HarD.h = iH;
        SDL_RenderCopy(renderer, Hard, NULL, &HarD);
    
        SDL_Texture *Mvolume = renderText("Music Volume", "fonts/NewRocker.otf", color, 42, renderer);
        SDL_QueryTexture(Mvolume, NULL, NULL, &iW, &iH);
        SDL_Rect MvolumE;
        MvolumE.x = SCREEN_WIDTH / 2 - iW / 2;
        MvolumE.y = 135;
        MvolumE.w = iW;
        MvolumE.h = iH;
        SDL_RenderCopy(renderer, Mvolume, NULL, &MvolumE);
    
        SDL_Texture *Svolume = renderText("SFX_Volume", "fonts/NewRocker.otf", color, 42, renderer);
        SDL_QueryTexture(Svolume, NULL, NULL, &iW, &iH);
        SDL_Rect SvolumE;
        SvolumE.x = SCREEN_WIDTH / 2 - iW / 2;
        SvolumE.y = 265;
        SvolumE.w = iW;
        SvolumE.h = iH;
        SDL_RenderCopy(renderer, Svolume, NULL, &SvolumE);
    
        SDL_Texture* settingBar = loadTexture("images/settingBar.png");
        SDL_Rect SbaR;
        SDL_QueryTexture(settingBar, NULL, NULL, &iW, &iH);
        SbaR.w = iW;
        SbaR.h = iH;
        int mStop = currentMVolume * 4.2;
        for (int i = 100; i < mStop; i += 10)
        {
            SbaR.x = i;
            SbaR.y = 200;
            SDL_RenderCopy(renderer, settingBar, NULL, &SbaR);
        }
        int sStop = currentSVolume * 4.2;
        SDL_RenderCopy(renderer, Svolume, NULL, &SvolumE);
        for (int i = 100; i < sStop; i += 10)
        {
            SbaR.x = i;
            SbaR.y = 330;
            SDL_RenderCopy(renderer, settingBar, NULL, &SbaR);
        }
    
        SDL_Texture* Controls = renderText("Controls", "fonts/NewRocker.otf", color, 42, renderer);
        SDL_QueryTexture(Controls, NULL, NULL, &iW, &iH);
        SDL_Rect ControlS;
        ControlS.x = SCREEN_WIDTH / 2 - iW / 2;
        ControlS.y = 380;
        ControlS.w = iW;
        ControlS.h = iH;
        SDL_RenderCopy(renderer, Controls, NULL, &ControlS);
    
        SDL_Texture* Selection = loadTexture("images/selection.png");
    
        if (optionsSelection == "difficulty")
        {
            SDL_RenderCopy(renderer, Selection, NULL, &DifficultY);
        }
        else if (optionsSelection == "mvolume")
        {
            SDL_RenderCopy(renderer, Selection, NULL, &MvolumE);
        }
        else if (optionsSelection == "svolume")
        {
            SDL_RenderCopy(renderer, Selection, NULL, &SvolumE);
        }
        else if (optionsSelection == "controls")
        {
            SDL_RenderCopy(renderer, Selection, NULL, &ControlS);
        }
    
        if (difficultySetting == "easy")
        {
            SDL_RenderCopy(renderer, Selection, NULL, &EasY);
        }
        else if (difficultySetting == "normal")
        {
            SDL_RenderCopy(renderer, Selection, NULL, &NormaL);
        }
        else if (difficultySetting == "hard")
        {
            SDL_RenderCopy(renderer, Selection, NULL, &HarD);
        }
    
        SDL_RenderPresent(renderer);
    
        SDL_Event event;
        while (SDL_PollEvent(&event) !=0)
        {
            if (event.type == SDL_QUIT)
            {
                inOptions = false;
                return 0;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (optionsSelection == "difficulty")
                {
                    if (difficultySetting == "easy")
                    {
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_RIGHT:
                                Mix_PlayChannel(2, gSelect, 0);
                                difficultySetting = "normal";
                                break;
                            case SDLK_DOWN:
                                Mix_PlayChannel(2, gSelect, 0);
                                optionsSelection = "mvolume";
                                break;
                            case SDLK_ESCAPE:
                                Mix_PlayChannel(2, gSelect, 0);
                                inOptions = false;
                                SDL_RenderClear(renderer);
                                break;
                        }
                    }
                    else if (difficultySetting == "normal")
                    {
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_RIGHT:
                                Mix_PlayChannel(2, gSelect, 0);
                                difficultySetting = "hard";
                                break;
                            case SDLK_LEFT:
                                Mix_PlayChannel(2, gSelect, 0);
                                difficultySetting = "easy";
                                break;
                            case SDLK_DOWN:
                                Mix_PlayChannel(2, gSelect, 0);
                                optionsSelection = "mvolume";
                                break;
                            case SDLK_ESCAPE:
                                Mix_PlayChannel(2, gSelect, 0);
                                inOptions = false;
                                SDL_RenderClear(renderer);
                                break;
                        }
                    }
                    else if (difficultySetting == "hard")
                    {
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_LEFT:
                                Mix_PlayChannel(2, gSelect, 0);
                            difficultySetting = "normal";
                            break;
                        case SDLK_DOWN:
                            Mix_PlayChannel(2, gSelect, 0);
                            optionsSelection = "mvolume";
                            break;
                        case SDLK_ESCAPE:
                            Mix_PlayChannel(2, gSelect, 0);
                            inOptions = false;
                            SDL_RenderClear(renderer);
                            break;
                        }
                    }
                }
                else if (optionsSelection == "mvolume")
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP:
                        Mix_PlayChannel(2, gSelect, 0);
                        optionsSelection = "difficulty";
                        break;
                    case SDLK_LEFT:
                        Mix_PlayChannel(2, gSelect, 0);
                        currentMVolume = Mix_VolumeMusic(-1);
                        if (currentMVolume == 128)
                        {
                            currentMVolume = currentMVolume - 8;
                        }
                        else if (currentMVolume <= 0)
                        {
                            currentMVolume = 0;
                        }
                        else
                        {
                            currentMVolume = currentMVolume - 10;
                        }
                        Mix_VolumeMusic(currentMVolume);
                        break;
                    case SDLK_RIGHT:
                        Mix_PlayChannel(2, gSelect, 0);
                        currentMVolume = Mix_VolumeMusic(-1);
                        if (currentMVolume >= 128)
                        {
                            currentMVolume = 128;
                        }
                        else if (currentMVolume == 120)
                        {
                            currentMVolume = 128;
                        }
                        else 
                        {
                            currentMVolume = currentMVolume + 10;
                        }
                        Mix_VolumeMusic(currentMVolume);
                        break;
                    case SDLK_DOWN:
                        Mix_PlayChannel(2, gSelect, 0);
                        optionsSelection = "svolume";
                        break;
                    case SDLK_ESCAPE:
                        Mix_PlayChannel(2, gSelect, 0);
                        inOptions = false;
                        SDL_RenderClear(renderer);
                        break;
                    }
                }
                else if (optionsSelection == "svolume")
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            Mix_PlayChannel(2, gSelect, 0);
                            optionsSelection = "mvolume";
                            break;
                        case SDLK_LEFT:
                            Mix_PlayChannel(2, gSelect, 0);
                            currentSVolume = Mix_Volume(2, -1);
                            if (currentSVolume == 128)
                            {
                                currentSVolume = currentSVolume - 8;
                            }
                            else if (currentSVolume <= 0)
                            {
                                currentSVolume = 0;
                            }
                            else
                            {
                                currentSVolume = currentSVolume - 10;
                            }
                            Mix_Volume(2, currentSVolume);
                            break;
                        case SDLK_RIGHT:
                            Mix_PlayChannel(2, gSelect, 0);
                            currentSVolume = Mix_Volume(2, -1);
                        if (currentSVolume >= 128)
                                {
                                currentSVolume = 128;
                                }
                        else if (currentSVolume == 120)
                        {
                            currentSVolume = 128;
                        }
                        else
                        {
                            currentSVolume = currentSVolume + 10;
                        }
                        Mix_Volume(2, currentSVolume);
                        break;
                    case SDLK_DOWN:
                        Mix_PlayChannel(2, gSelect, 0);
                        optionsSelection = "controls";
                        break;
                    case SDLK_ESCAPE:
                        Mix_PlayChannel(2, gSelect, 0);
                        inOptions = false;
                        SDL_RenderClear(renderer);
                        break;
                    }
                }
                else if (optionsSelection == "controls")
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            Mix_PlayChannel(2, gSelect, 0);
                            optionsSelection = "svolume";
                            break;
                        case SDLK_ESCAPE:
                            Mix_PlayChannel(2, gSelect, 0);
                            inOptions = false;
                            SDL_RenderClear(renderer);
                            break;
                    }
                }
            }
        }
    }
}

void mainMenu::menuMusic(bool isOn)
{
    if (isOn)
    {
        Mix_VolumeMusic(currentMVolume);
        Mix_PlayMusic(mMusic, 1);
    }
    else
    {
        Mix_HaltMusic();
    }
}

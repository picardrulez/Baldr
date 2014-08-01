#ifndef SDLGRAPHICS_H
#define SDLGRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>

using namespace std;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const char* WINDOW_TITLE;
extern int currentMVolume;
extern int currentSVolume;
extern string difficultySetting;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* loadTexture(const string &str);
extern SDL_Texture* renderText(const string &message, const string &fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer);
extern Mix_Music * gMusic;
extern Mix_Chunk* gSelect;

class SDLGraphics
{
    public:
        SDLGraphics(int screenWidth, int screenHeight, const char* windowTitle);
        ~SDLGraphics();
        

        void beginScene();
        void endScene();

        void drawSprite();
        void drawText();

//        void setBackgroundColor(int r, int g, int b);

    private:
 //       int m_backgroundColorRed;
 //       int m_backgroundColorGreen;
 //       int m_backgroundColorBlue;
};
#endif

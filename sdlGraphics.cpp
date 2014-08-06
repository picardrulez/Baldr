#include "sdlGraphics.h"
const int SCREEN_WIDTH = 854;
const int SCREEN_HEIGHT = 480;
const char* WINDOW_TITLE = "Baldr";
int currentMVolume = 70;
int currentSVolume = 70;
string difficultySetting = "normal";

SDL_Window* window;
SDL_Renderer* renderer;
//Mix_Music* gMusic = NULL;
Mix_Chunk* gSelect = NULL;

SDLGraphics::SDLGraphics(int screenWidth, int screenHeight, const char* windowTitle)
{
    SDL_Init (SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    TTF_Init();
}

SDLGraphics::~SDLGraphics()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}



//void SDLGraphics::closeTexture(SDL_Texture* textureName)
//{
//    SDL_DestroyTexture(textureName);
//}

void SDLGraphics::beginScene()
{
    SDL_RenderClear(renderer);
}

void SDLGraphics::endScene()
{
    SDL_RenderClear(renderer);
}

SDL_Texture* loadTexture(const string &str)
{
    SDL_Surface* surface = IMG_Load(str.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* renderText(const string &message, const string &fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer)
{
    TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);
    SDL_Surface* surf = TTF_RenderText_Blended(font, message.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

SDL_Texture* textureWindow()
{
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

#include "player.h"
player::player()
{
    int iW, iH;
    character=loadTexture("images/character.png");
    SDL_QueryTexture(character, NULL, NULL, &iW, &iH);
    PlayeR.x = 200;
    PlayeR.y = 200;
    PlayeR.w = iW;
    PlayeR.h = iH;
    bool playerFlip = false;
}
player::~player()
{
    SDL_DestroyTexture(character);
    character = NULL;
}
void player::moveLeft()
{
    PlayeR.x = PlayeR.x -= 15;
}

void player::moveRight()
{
    PlayeR.x = PlayeR.x += 15;
}

void player::draw()
{
    if (playerFlip == false)
    {
        SDL_RenderCopy(renderer, character, NULL, &PlayeR);
    }
    else if (playerFlip == true)
    {
        SDL_RenderCopyEx(renderer, character, NULL, &PlayeR, 0, 0, SDL_FLIP_HORIZONTAL);
    }
}

all:
	g++ main.cpp sdlGraphics.cpp menu.cpp game.cpp player.cpp input.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf  -o test

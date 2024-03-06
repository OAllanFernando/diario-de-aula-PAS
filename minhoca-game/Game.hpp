
#define Game_hpp
#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include "SDL_image.h"

class Game {

public:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	bool running();
};


#include "SDL.h"
#include <stdio.h>

//from the sdl tutorial
//and tweaked

int main(int argc, char* argv[]) {

	SDL_Window *window;
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"Raytracer",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);

	if (window == NULL) {
		printf("Something is very wrong: %s\n", SDL_GetError());
		return 1;
	}

	// Wait a lil, then close window
	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}

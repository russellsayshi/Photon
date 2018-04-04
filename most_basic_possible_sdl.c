#include "SDL2-2.0.8/include/SDL.h"
#include <stdio.h>

//from the sdl tutorial
//and tweaked

struct win {
	SDL_Surface* surface;
	SDL_PixelFormat* format;
	SDL_Window* window;
};

void set_pixel_raw(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	Uint8 *target_pixel = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;
	*(Uint32 *)target_pixel = pixel;
}

void set_pixel(win* window, int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	Uint32 pixel = SDL_MapRGB(const SDL_PixelFormat* window->format, r, g, b);
	set_pixel_raw(window->surface, x, y, pixel);
}

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
	
	SDL_Surface *screen;
	screen = SDL_GetWindowSurface(window);
	SDL_PixelFormat *format = screen->format;
	SDL_UpdateWindowSurface(window);
	
	win* window = new win();
	window->surface = screen;
	window->window = window;
	window->format = format;
	set_pixel(window, 10, 10, 0, 255, 0); //set pixel (10, 10) to bright green
	delete window;

	// Wait a lil, then close window
	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}

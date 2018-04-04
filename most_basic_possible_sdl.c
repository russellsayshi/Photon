#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

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

void set_pixel(struct win* window, int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	Uint32 pixel = SDL_MapRGB(window->format, r, g, b);
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
	
	struct win* window2 = (struct win*)malloc(sizeof (struct win));
	window2->surface = screen;
	window2->window = window;
	window2->format = format;
	for(int i = 10; i < 100; i++) {
		for(int o = 10; o < 100; o++) {
			set_pixel(window2, i, o, 0, 255, 0); //set pixel (10, 10) to bright green
		}
	}
	for(int i = 0; i < 300; i++) {
		double v = sin(((double)i)/3.141565)*10;
		set_pixel(window2, i, 200 + (int)v, 255, 255, 255);
	}
	SDL_UpdateWindowSurface(window);
	free(window2);

	// Wait a lil, then close window
	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}

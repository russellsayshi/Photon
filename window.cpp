#include "window.h"
#include <iostream>

photon::win::win(std::string name, int width, int height) {
	this->width = width;
	this->height = height;
	photon::video::initialize();

	window = SDL_CreateWindow(
		name.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_OPENGL
	);

	if (window == NULL) {
		std::stringstream s;
		s << "Something is very wrong: " << SDL_GetError();
		throw std::runtime_error(s.str());
	}
	surface = SDL_GetWindowSurface(window);
	format = surface->format;
}

photon::win::~win() {
	if(window != nullptr) {
		SDL_DestroyWindow(window);
	}
}

void photon::win::set_pixel_raw(int x, int y, Uint32 pixel) {
	SDL_LockSurface( surface );
	if(x < 0 || y < 0 || x >= surface->w || y >= surface->h) {
		std::stringstream error_msg;
		error_msg << "Out of bounds! x is " << x << " and y is " << y << ". X needs to be between 0 and " << width << " and y between 0 and " << height << ".";
		throw std::out_of_range(error_msg.str());
	}
	Uint8 *target_pixel = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;
	*(Uint32 *)target_pixel = pixel;
}

void photon::win::set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	Uint32 pixel = SDL_MapRGB(format, r, g, b);
	set_pixel_raw(x, y, pixel);
}

void photon::win::update() {
	SDL_UpdateWindowSurface(window);
}

void photon::win::clear() {
	SDL_FillRect(surface, NULL, 0x000000);
}

int photon::win::get_key() {
	while(SDL_WaitEvent(&keyevent)) {
		if(keyevent.type == SDL_KEYDOWN) {
				return 0;
		}
	}
	return 1;
}

void photon::win::delay(int time) {
	SDL_Delay(3000);
}

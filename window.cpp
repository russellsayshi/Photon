#include "window.h"
#include <iostream>

photon::win::win(std::string name, int width, int height, bool fullscreen) {
	this->width = width;
	this->height = height;
	photon::Video::initialize();

	int f = 0;
	if (fullscreen)
		f = SDL_WINDOW_FULLSCREEN;

	window = SDL_CreateWindow(
		name.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_OPENGL | f
	);

	if (window == nullptr) {
		std::stringstream s;
		s << "Something is very wrong: " << SDL_GetError();
		throw std::runtime_error(s.str());
	}
	windowID = SDL_GetWindowID(window);
	surface = SDL_GetWindowSurface(window);
	format = surface->format;
	clear();
}

photon::win::~win() {
	if(window != nullptr) {
		SDL_DestroyWindow(window);
	}
	photon::Video::destroy();
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

Uint32 photon::win::rgbToPixel(Uint8 r, Uint8 g, Uint8 b) {
	return SDL_MapRGB(format, r, g, b);
}

void photon::win::set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	Uint32 pixel = rgbToPixel(r, g, b);
	set_pixel_raw(x, y, pixel);
}

void photon::win::set_pixel(int x, int y, Colors::color c) {
	Uint8 r, g, b;
	std::tie(r, g, b) = c;
	set_pixel(x, y, r, g, b);
}

void photon::win::update() {
	SDL_UpdateWindowSurface(window);
}

void photon::win::fill(Uint8 r, Uint8 g, Uint8 b) {
	SDL_FillRect(surface, nullptr, rgbToPixel(r, g, b));
}

void photon::win::fill(Colors::color c) {
	Uint8 r, g, b;
	std::tie(r, g, b) = c;
	fill(r, g, b);
}

void photon::win::clear() {
	SDL_FillRect(surface, nullptr, rgbToPixel(0, 0, 0));
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

photon::window_event photon::win::get_event() {
	using namespace photon;
	SDL_Event event;
	if(!SDL_PollEvent(&event)) {
		window_event res(true, -1);
		return res;
	}
	switch(event.type) {
		case SDL_KEYDOWN: {
			window_event res(false, window_event::KEYDOWN, event.key.keysym.sym);
			return res;
		} break;
		case SDL_QUIT: {
			window_event res(false, window_event::QUIT);
			return res;
		} break;
		default: {
			window_event res(false, window_event::UNKNOWN);
			return res;
		} break;
	}
}

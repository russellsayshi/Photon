#include <SDL2/SDL.h>
#include <sstream>
#include <exception>
#include "video.h"

#ifndef PROTON_WIN_HEADER
#define PROTON_WIN_HEADER

namespace photon {

	class win {
	private:
		SDL_Surface* surface;
		SDL_PixelFormat* format;
		SDL_Window* window;
		int width;
		int height;
		SDL_Event keyevent;
	
	protected:
		void set_pixel_raw(int x, int y, Uint32 pixel);
	
	public:
		win(std::string name, int width, int height);
		void set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
		void update();
		~win();
		void delay(int time);
		int get_key(); 
	};

};

#endif

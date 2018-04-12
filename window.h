#include <SDL2/SDL.h>
#include <sstream>
#include <exception>
#include <tuple>

#include "Video.h"
#include "Colors.h"

#ifndef PROTON_WIN_HEADER
#define PROTON_WIN_HEADER

namespace photon {

	class win {
	private:
		SDL_Surface* surface;
		SDL_PixelFormat* format;
		SDL_Window* window;
		int windowID;
		int width;
		int height;
		SDL_Event keyevent;
		Uint32 rgbToPixel(Uint8 r, Uint8 g, Uint8 b);
	
	protected:
		void set_pixel_raw(int x, int y, Uint32 pixel);
	
	public:
		win(std::string name, int width, int height, bool fullscreen=false);
		~win();
		void set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
		void set_pixel(int x, int y, Colors::color c);
		void update();
		void fill(Uint8 r, Uint8 g, Uint8 b);
		void fill(Colors::color c);
		void clear();
		void delay(int time);
		int get_key();
	};

};

#endif

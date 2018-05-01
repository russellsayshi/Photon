#include <SDL2/SDL.h>

#ifndef WINDOW_EVENT_HEADER
#define WINDOW_EVENT_HEADER

namespace photon {
	class window_event {
	private:
		bool empty;
		int type;
	public:
		const int KEYDOWN = SDL_KEYDOWN;
		const int QUIT = SDL_QUIT;
		bool isEmpty();
		int getType();
	};
};

#endif

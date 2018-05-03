#include <SDL2/SDL.h>

#ifndef WINDOW_EVENT_HEADER
#define WINDOW_EVENT_HEADER

namespace photon {
	class window_event {
	private:
		bool empty;
		int type;
		int key;
	public:
		window_event(bool empty1, int type1) : empty(empty1), type(type1) {}
		window_event(bool empty1, int type1, int key1) : empty(empty1), type(type1), key(key1) {}
		window_event() : empty(true), type(UNKNOWN) {}
		static const int KEYDOWN = SDL_KEYDOWN;
		static const int QUIT = SDL_QUIT;
		static const int UNKNOWN = 5555;
		bool is_empty();
		int get_type();
		int get_key();
	};
};

#endif

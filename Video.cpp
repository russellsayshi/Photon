#include "Video.h"

namespace photon {
	int num_initialized = 0;
};

void photon::Video::initialize() {
	if(num_initialized == 0)
		SDL_Init(SDL_INIT_VIDEO);
	num_initialized++;
}

void photon::Video::destroy() {
	num_initialized--;
	if(num_initialized == 0)
		SDL_Quit();
}

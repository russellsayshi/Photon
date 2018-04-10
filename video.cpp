#include "video.h"

namespace photon {
	int num_initialized = 0;
};

void photon::video::initialize() {
	if(num_initialized == 0) {
		num_initialized++;
		std::cout << "Initializing SDL" << std::endl;
		SDL_Init(SDL_INIT_VIDEO);
	}
}

void photon::video::destroy() {
	num_initialized--;
	if(num_initialized == 0) {
		std::cout << "Quitting SDL" << std::endl;
		SDL_Quit();
	}
}

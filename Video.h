#include <SDL2/SDL.h>
#include <iostream>

#ifndef PHOTON_VID_HEADER
#define PHOTON_VID_HEADER

namespace photon {
	class Video {
	public:
		static void initialize();
		static void destroy();
	};

};

#endif

#include <SDL2/SDL.h>
#include <iostream>

#ifndef PHOTON_VID_HEADER
#define PHOTON_VID_HEADER

namespace photon {
	class video {
	public:
		static void initialize();
		static void destroy();
	};

};

#endif

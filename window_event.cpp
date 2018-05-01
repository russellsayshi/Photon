#include "window_event.h"

namespace photon {
	bool window_event::isEmpty() {
		return this->empty;
	}
	int window_event::getType() {
		return this->type;
	}
};

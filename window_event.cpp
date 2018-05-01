#include "window_event.h"

namespace photon {
	bool window_event::is_empty() {
		return this->empty;
	}
	int window_event::get_type() {
		return this->type;
	}
};

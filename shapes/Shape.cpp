#include "Shape.h"
#include <cmath>

virtual bool Shape::intersects(Ray* ray) {
	return false;
}

virtual double Shape::intersectsWhen(Ray* ray) {
	return -1;
}
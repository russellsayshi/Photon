#include "Shape.h"
#include <cmath>

bool Shape::intersects(Ray* ray) {
	return false;
}

double Shape::intersectsWhen(Ray* ray) {
	return -1;
}

Shape::Shape() {}

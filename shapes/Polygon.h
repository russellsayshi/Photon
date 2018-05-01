#include "../util/Point.h"
#include "../util/Ray.h"
#include "../util/Vec3.h"
#include "Shape.h"

#ifndef PHOTON_POLYGON_H
#define PHOTON_POLYGON_H


class Polygon : public Shape {
public:
	Vec3* normal;
	double dotBoi;

	Polygon() : Polygon(0, 0, 0, 1) {}

	Polygon(double a, double b, double c, double d)
			: normal(new Vec3(a, b, c)), dotBoi(d) {}

	Polygon(double a, double b, double c, double x, double y, double z) : Plane(a, b, c, 0) {
		double d = a * x + b * y + c * z;
		dotBoi = d;
	}

	bool intersects(Ray *ray);
	double intersectsWhen(Ray *ray);
};

#endif //PHOTON_POLYGON_H

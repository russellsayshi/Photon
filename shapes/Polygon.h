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

	Polygon(double a, double b, double c, double x, double y, double z) : Polygon(a, b, c, 0) {
		double d = a * x + b * y + c * z;
		dotBoi = d;
	}

	Polygon(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
		Vec3* ab = new Vec3(x2-x1, y2-y1, z2-z1);
		Vec3* ac = new Vec3(x3-x1, y3-y1, z3-z1);
		
	}

	bool intersects(Ray *ray);
	double intersectsWhen(Ray *ray);
};

#endif //PHOTON_POLYGON_H

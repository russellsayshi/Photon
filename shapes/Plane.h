#include "../util/Point.h"
#include "../util/Ray.h"
#include "../util/Vec3.h"

#ifndef PHOTON_PLANE_H
#define PHOTON_PLANE_H


class Plane : public Shape {
public:
	Vec3* normal;
	double dotBoi;

	Plane() : Plane(0, 0, 0, 1) {}

	Plane(double a, double b, double c, double d)
			: normal(new Vec3(a, b, c)), dotBoi(d) {}

	Plane(double a, double b, double c, double x, double y, double z) : Plane(a, b, c, 0) {
		double d = a * x + b * y + c * z;
		dotBoi = d;
	}

	bool intersects(Ray *ray);
	double intersectsWhen(Ray *ray);
};

#endif //PHOTON_PLANE_H
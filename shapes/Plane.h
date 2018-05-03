#include "../util/Ray.h"
#include "../util/Vec3.h"
#include "Shape.h"

#ifndef PHOTON_PLANE_H
#define PHOTON_PLANE_H


class Plane : public Shape {
public:
	Vec3 normal;
	double dotBoi;

	Plane() : Plane(0, 0, 0, 1) {}

	Plane(double a, double b, double c, double d)
			: normal(Vec3(a, b, c)), dotBoi(d) {}

	Plane(double a, double b, double c, double x, double y, double z) : Plane(a, b, c, 0) {
		Vec3 tv = Vec3(a,b,c);
		Vec3 tp = Vec3(x,y,z);
		dotBoi = (double)tv.dot(tp);
	}

	bool intersects(Ray *ray);
	double intersectsWhen(Ray *ray);
};

#endif //PHOTON_PLANE_H

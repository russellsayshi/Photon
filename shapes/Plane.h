#include "../util/Point.h"
#include "../util/Ray.h"
#include "../util/Vec3.h"

#ifndef PHOTON_PLANE_H
#define PHOTON_PLANE_H


class Plane {
public:
	Vec3* normal;
	double dotBoi;

	Plane() : Plane(0, 0, 0, 1) {}

	Plane(float a, float b, float c, float d)
			: normal(new Vec3(a, b, c)), dotBoi(d) {}

	bool intersects(Ray *r);
	float intersectsWhen(Ray *ray);
};

#endif //PHOTON_PLANE_H
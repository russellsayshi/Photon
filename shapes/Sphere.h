#include "../util/Point.h"
#include "../util/Ray.h"

#ifndef PHOTON_SPHERE_H
#define PHOTON_SPHERE_H


class Sphere : public Shape {
public:
	Point *center;
	float radius;

	Sphere() : Sphere(0, 0, 0, 1) {}

	Sphere(float x, float y, float z, float radius)
			: center(new Point(x, y, z)), radius(radius) {}

	bool intersects(Ray *ray);
	float intersectsWhen(Ray *ray);
};

#endif //PHOTON_SPHERE_H
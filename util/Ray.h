#include "Point.h"
#include "Vec3.h"

#ifndef PHOTON_RAY_H
#define PHOTON_RAY_H

struct Ray {
	Point *point;
	Vec3 *vector;

	Ray() : Ray(0, 0, 0, 0, 0, 0) {}

	Ray(float Vx, float Vy, float Vz)
			: Ray(0, 0, 0, Vx, Vy, Vz) {}

	Ray(float Px, float Py, float Pz, float Vx, float Vy, float Vz)
			: point(new Point(Px, Py, Pz)), vector(new Vec3(Vx, Vy, Vz)) {}

	Ray(float Px, float Py, float Pz, Vec3* vec)
			: point(new Point(Px, Py, Pz)), vector(vec) {}
};

#endif

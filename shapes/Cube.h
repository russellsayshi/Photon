#include "../util/Ray.h"
#include "Plane.h"

#ifndef PHOTON_CUBE_H
#define PHOTON_CUBE_H


class Cube : public Shape {
public:
	Vec3 center;
	double radius;	// radius of a circumscribed sphere within the cube
	Plane* planes[6];

	Cube() : Cube(0, 0, 0, 1) {}

	Cube(double x, double y, double z, double r) : center(Vec3(x, y, z)), radius(r) {
		planes[0] = new Plane(1,0,0,x+r,y,z);
		planes[1] = new Plane(1,0,0,x-r,y,z);
		planes[2] = new Plane(0,1,0,x,y+r,z);
		planes[3] = new Plane(0,1,0,x,y-r,z);
		planes[4] = new Plane(0,0,1,x,y,z+r);
		planes[5] = new Plane(0,0,1,x,y,z-r);
		// dx, dy, dz, x, y, z
	}

	bool intersects(Ray *ray);
	double intersectsWhen(Ray *ray);
};

#endif //PHOTON_CUBE_H

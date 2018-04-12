#ifndef PHOTON_POINT_H
#define PHOTON_POINT_H

struct Point {
	float x, y, z;

	Point() : Point(0, 0, 0) {}

	Point(float x, float y, float z)
			: x(x), y(y), z(z) {}
};

#endif
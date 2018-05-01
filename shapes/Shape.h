#include "../util/Point.h"
#include "../util/Ray.h"
#include "../util/Vec3.h"

#ifndef PHOTON_SHAPE_H
#define PHOTON_SHAPE_H


class Shape {
protected:
	Shape();

public:

	virtual bool intersects(Ray *ray);
	virtual double intersectsWhen(Ray *ray);
};

#endif //PHOTON_PLANE_H

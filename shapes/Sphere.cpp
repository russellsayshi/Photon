#include "Sphere.h"

bool Sphere::intersects(Ray *r) {
	float a = r->vector->x * r->vector->x + r->vector->y * r->vector->y + r->vector->z * r->vector->z;
	float b = (r->point->x - center->x) * (r->point->x - center->x);
	float c = (r->point->y - center->y) * (r->point->y - center->y);
	float d = (r->point->z - center->z) * (r->point->z - center->z);
	float e = radius * radius;
	float alpha = a * (b + c + d - e);
	float beta = (r->vector->x * (r->point->x - center->x) +
				  r->vector->y * (r->point->y - center->y) +
				  r->vector->z * (r->point->z - center->z)) * (r->vector->x * (r->point->x - center->x) +
															   r->vector->y * (r->point->y - center->y) +
															   r->vector->z * (r->point->z - center->z));
	return alpha < beta;
}
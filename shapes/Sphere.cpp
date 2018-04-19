#include "Sphere.h"
#include <cmath>

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

float Sphere::intersectsWhen(Ray *ray) {
	float x1 = ray->point->x;
	float y1 = ray->point->y;
	float z1 = ray->point->z;
	float x2 = ray->vector->x + ray->point->x;
	float y2 = ray->vector->y + ray->point->y;
	float z2 = ray->vector->z + ray->point->z;
	float x3 = center->x;
	float y3 = center->y;
	float z3 = center->z;
	float r = radius;
	float a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
	float b = 2 * ((x2-x1)*(x1-x3) + (y2-y1)*(y1-y3) + (z2-z1)*(z1-z3));
	float c = x3*x3 + y3*y3 + z3*z3 + x1*x1 + y1*y1 + z1*z1 - 2*(x3*x1 + y3*y1 + z3*z1) - r * r;
	float det = b*b - 4 * a * c;
	if(det < 0) return -1;
	float t = (-b + (float)sqrt(det))/(2*a);
	return -t;
}

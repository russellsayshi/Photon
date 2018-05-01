#include "Sphere.h"
#include <cmath>

bool Sphere::intersects(Ray *r) {
	double a = r->vector->x * r->vector->x + r->vector->y * r->vector->y + r->vector->z * r->vector->z;
	double b = (r->point->x - center->x) * (r->point->x - center->x);
	double c = (r->point->y - center->y) * (r->point->y - center->y);
	double d = (r->point->z - center->z) * (r->point->z - center->z);
	double e = radius * radius;
	double alpha = a * (b + c + d - e);
	double beta = (r->vector->x * (r->point->x - center->x) +
				  r->vector->y * (r->point->y - center->y) +
				  r->vector->z * (r->point->z - center->z)) * (r->vector->x * (r->point->x - center->x) +
															   r->vector->y * (r->point->y - center->y) +
															   r->vector->z * (r->point->z - center->z));
	return alpha < beta;
}

double Sphere::intersectsWhen(Ray *r) {
	double x1 = r->point->x;
	double y1 = r->point->y;
	double z1 = r->point->z;
	double x2 = r->vector->x + r->point->x;
	double y2 = r->vector->y + r->point->y;
	double z2 = r->vector->z + r->point->z;
	double x3 = center->x;
	double y3 = center->y;
	double z3 = center->z;
	double rad = radius;
	double a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
	double b = 2 * ((x2-x1)*(x1-x3) + (y2-y1)*(y1-y3) + (z2-z1)*(z1-z3));
	double c = x3*x3 + y3*y3 + z3*z3 + x1*x1 + y1*y1 + z1*z1 - 2*(x3*x1 + y3*y1 + z3*z1) - rad * rad;
	double det = b*b - 4 * a * c;
	if(det < 0) {
		return -1;
	}
	double t = (-b + (double)sqrt(det))/(2*a);
	return -t * (double)(ray->vector->mag());
}

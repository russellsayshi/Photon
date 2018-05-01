#include "Sphere.h"
#include <cmath>

bool Sphere::intersects(Ray *ray) {
	double a = ray->vectoray->x * ray->vectoray->x + ray->vectoray->y * ray->vectoray->y + ray->vectoray->z * ray->vectoray->z;
	double b = (ray->point->x - centeray->x) * (ray->point->x - centeray->x);
	double c = (ray->point->y - centeray->y) * (ray->point->y - centeray->y);
	double d = (ray->point->z - centeray->z) * (ray->point->z - centeray->z);
	double e = radius * radius;
	double alpha = a * (b + c + d - e);
	double beta = (ray->vectoray->x * (ray->point->x - centeray->x) +
				  ray->vectoray->y * (ray->point->y - centeray->y) +
				  ray->vectoray->z * (ray->point->z - centeray->z)) * (ray->vectoray->x * (ray->point->x - centeray->x) +
															   ray->vectoray->y * (ray->point->y - centeray->y) +
															   ray->vectoray->z * (ray->point->z - centeray->z));
	return alpha < beta;
}

double Sphere::intersectsWhen(Ray *ray) {
	double x1 = ray->point->x;
	double y1 = ray->point->y;
	double z1 = ray->point->z;
	double x2 = ray->vector->x + ray->point->x;
	double y2 = ray->vector->y + ray->point->y;
	double z2 = ray->vector->z + ray->point->z;
	double x3 = center->x;
	double y3 = center->y;
	double z3 = center->z;
	double r = radius;
	double a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
	double b = 2 * ((x2-x1)*(x1-x3) + (y2-y1)*(y1-y3) + (z2-z1)*(z1-z3));
	double c = x3*x3 + y3*y3 + z3*z3 + x1*x1 + y1*y1 + z1*z1 - 2*(x3*x1 + y3*y1 + z3*z1) - r * r;
	double det = b*b - 4 * a * c;
	if(det < 0) return -1;
	double t = (-b + (double)sqrt(det))/(2*a);
	return -t;
}
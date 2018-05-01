#include "Polygon.h"
#include <cmath>

bool Polygon::intersects(Ray* ray) {
	double a = normal.x;
	double b = normal.y;
	double c = normal.z;
	double e = ray->vector->x;
	double g = ray->vector->y;
	double i = ray->vector->z;
	double denominator = a*e + b*g + c*i;
	if(denominator == 0) {
		return false;
	}
	return true;
}

double Polygon::intersectsWhen(Ray* ray) {
	double a = normal.x;
	double b = normal.y;
	double c = normal.z;
	double d = dotBoi;
	double e = ray->vector->x;
	double f = ray->point->x;
	double g = ray->vector->y;
	double h = ray->point->y;
	double i = ray->vector->z;
	double j = ray->point->z;
	double numerator = a*f + b*h + c*j + d;
	double denominator = a*e + b*g + c*i;
	double ans = -1 * numerator / denominator;
	if(ans < 0) {
		return -1;
	}
	return ans * (double)(ray->vector->mag());
}
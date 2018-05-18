#include "Cube.h"
#include <cmath>
#include <iostream>

bool Cube::intersects(Ray* ray) {
	return false;
}

double Cube::intersectsWhen(Ray* ray) {
	double distances[6];
	//std::cout << *(ray->point) << std::endl;
	//std::cout << *(ray->vector) << std::endl;
	//std::cout << "---------------------------------------" << std::endl;
	for(int i = 0; i < 6; i++) {
		distances[i] = planes[i]->intersectsWhen(ray);
		//std::cout << distances[i] << std::endl;
	}
	double closestValid = 1000;
	/*
	for(int i = 0; i < 6; i++) {
		Vec3 distancedVec = (ray->vector->norm()) * distances[i];
		Vec3 position = *(ray->point) + distancedVec;
		Ray* rtemp = new Ray((position.x), (position.y), (position.z), position.x - center.x, position.y - center.y, position.z - center.z);
		double distances2[6];
		for(int ii = 0; ii < 6; ii++) {
			distances2[ii] = planes[ii]->intersectsWhen(rtemp);
		}
		double closestPositive = 1000;	// closest intercepting plane in the direction of the center
		for(int ii = 0; ii < 6; ii++) {
			if(distances2[ii] > 0 && distances2[ii] < closestPositive) {
				closestPositive = distances2[ii];
			}
		}
		// below is never true?
		if(closestValid > distances[i] && !(closestPositive < rtemp->vector->mag())) {
			closestValid = distances[i];
		}
	}
	*/
	for(int i = 0; i < 6; i++) {	// eliminate impossible candidates
		//std::cout << "--------------------------------------------" << std::endl;
		Vec3 posVec = (ray->vector->norm() * distances[i]) - *(ray->point);		// I really feel like this shouldnt be a minus buuuuut...
		//std::cout << "distance to interception point = " << distances[i] << std::endl;
		//std::cout << "ray interception point = " << posVec << std::endl;
		Ray* toCenter = new Ray(posVec.x, posVec.y, posVec.z, posVec.x - center.x, posVec.y - center.y, posVec.z - center.z); //maybe switch center and position values? idk
		bool noShot = false;
		for(int ii = 0; !noShot && ii < 6; ii++) {
			double intersect = planes[ii]->intersectsWhen(toCenter);
			//std::cout << "centerRay intersect #" << ii+1 << " = " << intersect << std::endl;
			//std::cout << "magnitude = " << toCenter->vector->mag() << std::endl;
			if(intersect > 0 && intersect < toCenter->vector->mag()) {
				//std::cout << "no shot!" << std::endl;
				noShot = true;
			}
		}
		if(noShot) {
			distances[i] = -1;
		}
	}
	//std::cout << "----------------------------------------------" << std::endl;
	//std::cout << "----------------------------------------------" << std::endl;

	for(int i = 0; i < 6; i++) {
		if(distances[i] > 0 && distances[i] < closestValid) {
			closestValid = distances[i];
		}
	}
	if(closestValid == 1000) {	//if no valid intercepts
		////std::cout << "still 1000" << std::endl;
		closestValid = -1;
	} else {
		//std::cout << closestValid << std::endl;
	}
	return closestValid;
}

/*

ok so from point of contact on surface and the center point:
if 
	(closest intersect among the planes along the line passing between the point and the center) 
		< (distance between point and center) 
then 
	its a valid point on the surface

BASICALLY: if you can get to the center from a point without intersecting any of the planes, 
then you're on the surface

MUST CHECK FOR ALL PLANE INTERSECTIONS

*/

/*

ok so it looks like the rays are intersecting on the plane furthest back?

*/
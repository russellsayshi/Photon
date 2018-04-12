#include <iostream>
#include "util/Vec3.h"
#include "util/Point.h"
#include "util/Ray.h"
#include "shapes/Sphere.h"

int main() {
	Sphere* spheres[3];
	spheres[0] = new Sphere(0, 0, 0, 1);
	spheres[1] = new Sphere(0, 3, 0, 1);
	spheres[2] = new Sphere(0, 6, 0, 1);

	float xVal = 15.0;
	float yVal = 0.0;
	float zVal = 0.0;

	int height = 50;
	int width = 100;

	double fov = 0.5;

	Ray *rays[height][width];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			auto deltaZ = (float)(fov * ((height - 2.0 * ((float) i)) / height));
			auto deltaY = (float)(fov * ((width - 2.0 * ((float) j)) / width));
			rays[i][j] = new Ray(xVal, yVal, zVal, 1, deltaY, deltaZ);
		}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			for (int k = 0; k < 3; k++)
				if (spheres[k]->intersects(rays[i][j])) {
					std::cout << '#';
					break;
				} else if (k == 2)
					std::cout << '.';
		std::cout << std::endl;
	}
}

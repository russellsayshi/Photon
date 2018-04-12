#include <iostream>

#include <SDL2/SDL.h>

#include "window.h"

#include "util/Vec3.h"
#include "util/Ray.h"
#include "shapes/Sphere.h"


int main(int argc, char* argv[]) {
	int height = 640;
	int width = 640;

	photon::win window("apollo drizzle", height, width);

	window.fill(Colors::pink);

	Sphere* spheres[5];
	spheres[0] = new Sphere(0, 0, 0, 1);
	spheres[1] = new Sphere(0, 3, 0, 1);
	spheres[2] = new Sphere(0, 6, 0, 1);
	spheres[3] = new Sphere(0, 9, 0, 1);
	spheres[4] = new Sphere(0, 12, 0, 1);

	float xVal = 15.0;
	float yVal = 0.0;
	float zVal = 0.0;

	double zoom = .5;

	Ray *rays[height][width];

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++) {
			auto deltaZ = (float)(zoom * ((height - 2.0 * ((float)row)) / height));
			auto deltaY = (float)(zoom * ((width - 2.0 * ((float)col)) / width));
			rays[row][col] = new Ray(xVal, yVal, zVal, 1, deltaY, deltaZ);
		}

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			for (Sphere* s : spheres)
				if (s->intersects(rays[row][col])) {
					window.set_pixel(row, col, Colors::lightBlue);
					break;
				}

	window.update();
	window.get_key();

	return 0;
}


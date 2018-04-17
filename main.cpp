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

	const int numSpheres = 100;
	Sphere* spheres[numSpheres];
	for(int i = 0; i < numSpheres; i++)
		spheres[i] = new Sphere(0, i * 3, 0, .5);

	const float xCam = 20.0;
	const float yCam = 0.0;
	const float zCam = 0.0;

	double fov = .5;

	Ray *rays[height][width];

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++) {
			auto deltaZ = (float)(fov * ((height - 2.0 * ((float)row)) / height));
			auto deltaY = (float)(fov * ((width - 2.0 * ((float)col)) / width));
			rays[row][col] = new Ray(xCam, yCam, zCam, 1, deltaY, deltaZ);
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


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

	window.fill(Colors::white);

	const int numSpheres = 10;

	Sphere* spheres[numSpheres];
	for(int i = 0; i < numSpheres; i++)
		spheres[i] = new Sphere(0, i * 3, 0, i);

	const float xCam = 30.0;
	const float yCam = 15.0;
	const float zCam = 0.0;

	double fov = .5;

	Ray *rays[height][width];

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++) {
			auto deltaZ = (float)(fov * ((height - 2.0 * ((float)row)) / height));
			auto deltaY = (float)(fov * ((width - 2.0 * ((float)col)) / width));
			rays[row][col] = new Ray(xCam, yCam, zCam, 1, deltaY, deltaZ);
		}

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			float tMax = 10000;
			bool multi = false;
			int sphereMax = -1;
			for (int sphere = 0; sphere < numSpheres; sphere++) {
				Sphere* s = spheres[sphere];
				float t = s->intersectsWhen(rays[row][col]);
				if (t < tMax && t > 0) {
					if(tMax != 10000) multi = true;
					tMax = t;
					sphereMax = sphere;
					//std::cout << t << std::endl;
				}
			}
			if(tMax != 10000) {
				Colors::color c = Colors::color(sphereMax * 200, (int)(255-tMax*30), (int)(100 + tMax*30));
				window.set_pixel(row, col, c);
			}
		}
	}

	window.update();
	window.get_key();

	return 0;
}
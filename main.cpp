#include <iostream>

#include <SDL2/SDL.h>

#include "window.h"
#include "window_event.h"
#include "util/Vec3.h"
#include "util/Ray.h"
#include "shapes/Sphere.h"
#include "shapes/Plane.h"


int main(int argc, char* argv[]) {
	int height = 640;
	int width = 640;

	photon::win window("apollo drizzle", height, width);

	window.fill(Colors::white);

	const int numSpheres = 10;
	const int numPlanes = 4;
	const int numShapes = numSpheres + numPlanes;

	Shape* shapes[numShapes];

	for(int i = 0; i < numSpheres; i++)
		shapes[i] = new Sphere(0, 0, -i, 2);

	shapes[numSpheres + 0] = new Plane(0,0,1,5,5,5);
	shapes[numSpheres + 1] = new Plane(0,0,-1,5,-5,-5);
	shapes[numSpheres + 2] = new Plane(0,1,0,5,5,5);
	shapes[numSpheres + 3] = new Plane(0,-1,0,5,-5,-5);


	/*
	planes[0] = new Plane(0,0,1,1);
	planes[1] = new Plane(0,0,-1,-1);
	planes[2] = new Plane(0,1,0,1);
	planes[3] = new Plane(0,-1,0,-1);
	*/
	bool animated = true;

	const float xCam = 15.0;
	const float yCam = 0.0;
	const float zCam = 0.0;

	double fov = .5;
	float animVar = 0;
	Ray *rays[height][width];

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++) {
			auto deltaZ = (float)(fov * ((height - 2.0 * ((float)row)) / height));
			auto deltaY = (float)(fov * ((width - 2.0 * ((float)col)) / width));
			rays[row][col] = new Ray(xCam, yCam, zCam, 1, deltaY, deltaZ);
		}
	while(true) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				float tMax = 10000;
				bool multi = false;
				int shapeMax = -1;
				for (int shape = 0; shape < numShapes; shape++) {
					Shape* s = shapes[shape];
					float t = s->intersectsWhen(rays[row][col]);
					if (t < tMax && t > 0) {
						if(tMax != 10000) multi = true;
						tMax = t;
						shapeMax = shape;
						//std::cout << t << std::endl;
					}
				}
				if(tMax != 10000) {
					Colors::color c = Colors::color(shapeMax * 200, (int)(255-tMax*10), (int)(100 + tMax*10));
					window.set_pixel(row, col, c);
				}
			}
		}
		if(animated) {
			for(int i = 0; i < numSpheres; i++) {
				((Sphere*)(shapes[i]))->center.x = 3 * sin((animVar +i) * cos(2 * animVar));
				((Sphere*)(shapes[i]))->center.y = sin(animVar + i) * 5;
				((Sphere*)(shapes[i]))->center.z = 5 - i + cos(1.5f * animVar + 2*i);
				((Sphere*)(shapes[i]))->radius = (float)(2+sin(animVar + i));
			}
			animVar += 0.01f;
			window.update();
		} else {
			window.update();
			break;
		}
		photon::window_event event;
		while(!(event = window.get_event()).is_empty()) {
			if(event.get_type() == event.QUIT) {
				return 0;
			} else if(event.get_type() == event.KEYDOWN) {
				return 0;
			}
		}
	}
	window.get_key();

	return 0;
}

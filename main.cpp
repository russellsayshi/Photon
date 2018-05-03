#include <iostream>

#include <SDL2/SDL.h>

#include "window.h"
#include "window_event.h"
#include "util/Vec3.h"
#include "util/Ray.h"
#include "shapes/Sphere.h"
#include "shapes/Plane.h"
#include "Matrix.h"
#include <cmath>

const int width = 640;
const int height = 640;

void rotate_all_rays_by_matrix(Matrix mat, Ray* rays[][height]) {
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			Vec3* prev = rays[row][col]->vector;
			rays[row][col]->vector = new Vec3(mat * *(rays[row][col]->vector));
			delete prev;
		}
	}
}

void update_ray_positions_to_match_camera(Vec3 new_position, Ray* rays[][height]) {
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			Vec3* prev = rays[row][col]->point;
			rays[row][col]->point = new Vec3(new_position);
			delete prev;
		}
	}
}

int main(int argc, char* argv[]) {
	photon::win window("apollo drizzle", width, height);

	window.fill(Colors::white);

	const int numSpheres = 10;
	const int numPlanes = 4;
	const int numShapes = numSpheres;

	Shape* shapes[numShapes];

	for(int i = 0; i < numSpheres; i++)
		shapes[i] = new Sphere(0, 0, -i, 2);

	//shapes[numSpheres + 0] = new Plane(0,0,1,5,5,5);
	//shapes[numSpheres + 1] = new Plane(0,0,-1,5,-5,-5);
	//shapes[numSpheres + 2] = new Plane(0,1,0,5,5,5);
	//shapes[numSpheres + 3] = new Plane(0,-1,0,5,-5,-5);

	Vec3 current_rotation_x(1, 0, 0);
	Vec3 current_rotation_y(0, 1, 0);
	Vec3 current_rotation_z(0, 0, 1);
	/*
	planes[0] = new Plane(0,0,1,1);
	planes[1] = new Plane(0,0,-1,-1);
	planes[2] = new Plane(0,1,0,1);
	planes[3] = new Plane(0,-1,0,-1);
	*/
	bool animated = false;

	Vec3 camera_position(15, 0, 0);

	double fov = .5;
	float animVar = 0;
	Ray *rays[height][width];

	Matrix rotation_x = Matrix::x_rotation(M_PI/60);
	Matrix rotation_y = Matrix::y_rotation(M_PI/60);
	Matrix rotation_z = Matrix::z_rotation(M_PI/60);
	Matrix rotation_x_opp = Matrix::x_rotation(-M_PI/60);
	Matrix rotation_y_opp = Matrix::y_rotation(-M_PI/60);
	Matrix rotation_z_opp = Matrix::z_rotation(-M_PI/60);
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++) {
			auto deltaZ = (float)(fov * ((height - 2.0 * ((float)row)) / height));
			auto deltaY = (float)(fov * ((width - 2.0 * ((float)col)) / width));
			rays[row][col] = new Ray(camera_position.x, camera_position.y, camera_position.z, 1, deltaY, deltaZ);
		}
	while(true) {
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				int v = ((row / 50 % 2) + (col / 50 % 2)) % 2;
				if(v == 1) {
					window.set_pixel(col, row, Colors::white);
				} else {
					window.set_pixel(col, row, Colors::gray);
				}

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
					Colors::color c = Colors::color(shapeMax * 200, (int)(255-5*10), (int)(100 + 5*10));
					window.set_pixel(col, row, c);
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
		}
		window.update();
		photon::window_event event;
		while(!(event = window.get_event()).is_empty()) {
			if(event.get_type() == event.QUIT) {
				return 0;
			} else if(event.get_type() == event.KEYDOWN) {
				int key = event.get_key();
				switch(key) {
					case 27:
						//escape
						return 0;
					case (int)('e'):
						rotate_all_rays_by_matrix(rotation_x, rays);
						current_rotation_x = rotation_x * current_rotation_x;
						current_rotation_y = rotation_x * current_rotation_y;
						current_rotation_z = rotation_x * current_rotation_z;
						break;
					case (int)('q'):
						rotate_all_rays_by_matrix(rotation_x_opp, rays);
						current_rotation_x = rotation_x_opp * current_rotation_x;
						current_rotation_y = rotation_x_opp * current_rotation_y;
						current_rotation_z = rotation_x_opp * current_rotation_z;
						break;
					case (int)('s'):
						rotate_all_rays_by_matrix(rotation_y, rays);
						current_rotation_x = rotation_y * current_rotation_x;
						current_rotation_y = rotation_y * current_rotation_y;
						current_rotation_z = rotation_y * current_rotation_z;
						break;
					case (int)('w'):
						rotate_all_rays_by_matrix(rotation_y_opp, rays);
						current_rotation_x = rotation_y_opp * current_rotation_x;
						current_rotation_y = rotation_y_opp * current_rotation_y;
						current_rotation_z = rotation_y_opp * current_rotation_z;
						break;
					case (int)('a'):
						rotate_all_rays_by_matrix(rotation_z, rays);
						current_rotation_x = rotation_z * current_rotation_x;
						current_rotation_y = rotation_z * current_rotation_y;
						current_rotation_z = rotation_z * current_rotation_z;
						break;
					case (int)('d'):
						rotate_all_rays_by_matrix(rotation_z_opp, rays);
						current_rotation_x = rotation_z_opp * current_rotation_x;
						current_rotation_y = rotation_z_opp * current_rotation_y;
						current_rotation_z = rotation_z_opp * current_rotation_z;
						break;
					case (int)('k'):
						camera_position = camera_position + current_rotation_x;
						update_ray_positions_to_match_camera(camera_position, rays);
						break;
					case (int)('i'):
						camera_position = camera_position - current_rotation_x;
						update_ray_positions_to_match_camera(camera_position, rays);
						break;
					case (int)('j'):
						camera_position = camera_position + current_rotation_y;
						update_ray_positions_to_match_camera(camera_position, rays);
						break;
					case (int)('l'):
						camera_position = camera_position - current_rotation_y;
						update_ray_positions_to_match_camera(camera_position, rays);
						break;
					case (int)('u'):
						camera_position = camera_position + current_rotation_z;
						update_ray_positions_to_match_camera(camera_position, rays);
						break;
					case (int)('o'):
						camera_position = camera_position - current_rotation_z;
						update_ray_positions_to_match_camera(camera_position, rays);
						break;
				}
			}
		}
	}
	window.get_key();

	return 0;
}

#include <stdio.h>
#include <iostream>
#include <math.h>

#define h 10
#define w 10

using namespace std;

class ray {
public:
	double x;
	double y;
	double z;
	double dx;
	double dy;
	double dz;
	ray(double x1, double y1, double z1, double dx1, double dy1, double dz1) {
		x = x1;
		y = y1;
		z = z1;
		dx = dx1;
		dy = dy1;
		dz = dz1;
	}
};

class func {
public:
	string type;
};

class plane: public func {	
public:
	string type = "plane";
	double dx;
	double dy;
	double dz;
	double c;
	plane(double dx1, double dy1, double dz1, double c1) {
		dx = dx1;
		dy = dy1;
		dz = dz1;
		c = c1;
	}
};

class camera {
public:
	double x;
	double y;
	double z;
	double azimuth;		// radians between center ray and the x axis in the x-y plane (right is positive)
	double elevation;	// radians between center ray and the x-y plane (above is positive)
	double fov;
	camera(double x1, double y1, double z1, double az, double el, double fo) {
		x = x1;
		y = y1;
		z = z1;
		azimuth = az;
		elevation = el;
		fov = fo;
	}
};

char screen[h][w];

char check(ray* r, func** f, numFunc) {
	for(int i = 0; i < numFunc, i++) {
		if(f[i]->type = "plane") {
			if(ray->x)
		}
	}
}

void printScreen() {
	for(int i = 0; i < h; ++i) {
		for(int ii = 0; ii < w; ii++) {
			screen[i][ii] = check()
			cout << screen[i][ii];
		}
		cout << endl;
	}
}

int main() {
	int funcCouunt = 1;		// currently holds this many functions
	func funcs[funcCouunt];

	for(int i = 0; i < h; ++i) {
		for(int ii = 0; ii < w; ii++) {
			screen[i][ii] = ' ';
		}
	}

	printScreen();
}
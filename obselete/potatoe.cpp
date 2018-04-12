#include <stdio.h>
#include <iostream>
#include <math.h>

#define height 10
#define width 10
#define numFuncs 3

using namespace std;

class vec {
public:
	double x;
	double y;
	double z;
	vec() {
		x = 0;
		y = 0;
		z = 0;
	}
	vec(double x1, double y1, double z1) {
		x = x1;
		y = y1;
		z = z1;
	}
};

double distance(vec* a, vec* b) {
	double dx = a->x - b->x;
	double dy = a->y - b->y;
	double dz = a->z - b->z;
	double t1 = pow(dx, 2.0) + pow(dy, 2.0) + pow(dz, 2.0);
	double t2 = sqrt(t1);
	return t2;
}

class ray {
public:
	vec* p;
	vec* dp;
	ray() {
		p = new vec();
		dp = new vec();
	}
	ray(double x, double y, double z, double dx, double dy, double dz) {
		p = new vec(x, y, z);
		dp = new vec(dx, dy, dz);
	}
};

class func {
public:
	string type;
};

class plane: public func {	
public:
	vec* n;
	double c;
	plane() {
		type = "plane";
		n = new vec();
		c = 0;
	}
	plane(double dx, double dy, double dz, double c1) {
		type = "plane";
		n = new vec(dx, dy, dz);
		c = c1;
	}
	plane(double x, double y, double z, double dx, double dy, double dz) {
		type = "plane";
		n = new vec(dx, dy, dz);
		c = 0;		// how does this get calculated from a point?
	}
};

class sphere: public func {
public:
	vec* c;
	double r;
	sphere() {
		type = "sphere";
		c = new vec();
		r = 1;
	}
	sphere(double x, double y, double z, double rad) {
		type = "sphere";
		c = new vec(x, y, z);
		r = rad;
	}
};

ray* rays[height][width];			// should be a passed parameter
func* funcs[numFuncs];	// should be a passed parameter
char screen[height][width];		// should be a class and a passed parameter

class camera {
public:
	vec* p;
	double azimuth;		// degrees between center ray and the x axis in the x-y plane (right is positive)
	double elevation;	// degrees between center ray and the x-y plane (above is positive)
	double rotation;	// degrees between up vector on screen and closest line to z axis in the camera's screen (clockwise is positive aka tilting right is positive)
	double fov;			// degrees (90 degrees recomended for testing - easy angle)
	camera() {
		p = new vec();
		azimuth = 0;
		elevation = 0;
		rotation = 0;
		fov = 90;
	}
	camera(double x, double y, double z, double az, double el, double ro, double fo) {
		p = new vec(x, y, z);
		azimuth = az;
		elevation = el;
		rotation = ro;
		fov = fo;
	}
};

char check(ray* r) {
	for(int ii = 0; ii < numFuncs; ii++) {
		if(funcs[ii]->type == "sphere") {
			double a = r->dp->x;
			double b = r->p->x;
			double c = ((sphere*)funcs[ii])->c->x;
			double d = r->dp->y;
			double e = r->p->y;
			double f = ((sphere*)funcs[ii])->c->y;
			double g = r->dp->z;
			double h = r->p->z;
			double i = ((sphere*)funcs[ii])->c->z;
			double r = ((sphere*)funcs[ii])->r;
			double alpha1 = a*a + d*d + g*g;
			double alpha2 = (b-c)*(b-c);
			double alpha3 = (e-f)*(e-f);
			double alpha4 = (h-i)*(h-i);
			double alpha5 = r*r;
			double alpha = 4.0 * alpha1 * (alpha2 + alpha3 + alpha4 - alpha5);
			//cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " ";
			//cout << alpha1 << " " << alpha2 << " " << alpha3 << " " << alpha4 << " " << alpha5 << " " << alpha << " ";
			double beta = 4.0 * (a*(b-c) + d*(e-f) + g*(h-i)) * (a*(b-c) + d*(e-f) + g*(h-i));
			//cout << beta << " ";
			if(alpha < beta) {
				return '#';
			}
		}
	}
	return '.';
}

void printScreen() {
	for(int i = 0; i < height; ++i) {
		for(int ii = 0; ii < width; ii++) {
			screen[i][ii] = check(rays[i][ii]);
			cout << screen[i][ii];
		}
		cout << endl;
	}
}

int main() {
				//		  x,y,z,r
	funcs[0] = new sphere(0,0,0,1);
	funcs[1] = new sphere(0,3,0,1);
	funcs[2] = new sphere(0,6,0,1);

	double xVal = 15.0;
	double yVal = 0.0;
	double zVal = 0.0;

	int tempheight = 50;
	int tempwidth = 100;

	double fovBoi = 0.5;

	ray* rs[tempheight][tempwidth];

	for(int i = 0; i < tempheight; i++) {
		for(int ii = 0; ii < tempwidth; ii++) {
			double deltaZ = fovBoi*((tempheight-2.0*((double)i))/tempheight);
			//cout << deltaY;
			double deltaY = fovBoi*((tempwidth-2.0*((double)ii))/tempwidth);
			//cout << deltaZ;
							//  x,    y,    z,    dx,dy,     dz
			rs[i][ii] = new ray(xVal, yVal, zVal, 1, deltaY, deltaZ);
		}
	}

	for(int i = 0; i < tempheight; i++) {
		for(int ii = 0; ii < tempwidth; ii++) {
			cout << check(rs[i][ii]);	
		}
		cout << endl;
	}	

	/*
	for(int i = 0; i < h; ++i) {
		for(int ii = 0; ii < w; ii++) {
			screen[i][ii] = ' ';
		}
	}

	printScreen();
	*/
}
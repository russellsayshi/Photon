#ifndef CAMERA_HEADER
#define CAMERA_HEADER
#include <cmath>
#include "Vec3.h"
namespace photon {
	class Camera {
	    public:
		Vec3 position;
		Vec3 look;
		Vec3 w, u, v;
		double windowWidth;
		Camera() {
		    position = Vec3(0.0, 0.0, 0.0);
		    look = Vec3(0.0, 0.0, 0.0);
		    windowWidth = 1000;
		    calculateNormals();
		}

		Camera(Vec3 p, Vec3 l, double ww) : position(p), look(l), windowWidth(ww) {
		    calculateNormals();
		}
		
		void calculateNormals(){
		    w = (look - position).norm();
		    up = Vec3(0.0, 1.0, 0.0);
		    u = up.cross(w).norm();
		    v = w.cross(u);
		}
	};
}
#endif

/*
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
*/

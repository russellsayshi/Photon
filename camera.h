#ifndef CAMERA_HEADER
#define CAMERA_HEADER
#include <cmath>
#include "Vec3.h"

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

#endif

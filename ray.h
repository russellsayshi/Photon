#ifdef RAY_HEADER
#define RAY_HEADER

#include <iostream>
#include <cmath>
#include <string>
#include "Vec3.h"

class Ray{
    public:
        Vec3 origin;
        Vec3 direction;
        int numReflections;

        Ray() : origin(Vec3()), direction(Vec3()), numReflections(-1) { }
        Ray(Vec3 o, Vec3 d, int r) : origin(o), numReflections(r) {
            direction = d.norm();
        }
}

#endif
            

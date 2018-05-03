#include "util/Vec3.h"

#ifndef PHOTON_MATRIX_HEADER
#define PHOTON_MATRIX_HEADER

class Matrix {
private:
	Matrix();
protected:
	float vals[3][3];
public:
	Vec3 operator*(Vec3 other);
	static Matrix x_rotation(float theta);
	static Matrix y_rotation(float theta);
	static Matrix z_rotation(float theta);
};

#endif

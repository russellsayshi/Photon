#include "Matrix.h"

Matrix::Matrix() {}

Vec3 Matrix::operator*(Vec3 other) {
	return Vec3(other.x * vals[0][0] + other.y * vals[0][1] + other.z * vals[0][2],
		    other.x * vals[1][0] + other.y * vals[1][1] + other.z * vals[1][2],
		    other.x * vals[2][0] + other.y * vals[2][1] + other.z * vals[2][2]);
}

Matrix Matrix::x_rotation(float theta) {
	Matrix ret;
	ret.vals[0][0] = 1;
	ret.vals[0][1] = 0;
	ret.vals[0][2] = 0;

	ret.vals[1][0] = 0;
	ret.vals[1][1] = cos(theta);
	ret.vals[1][2] = -sin(theta);

	ret.vals[2][0] = 0;
	ret.vals[2][1] = sin(theta);
	ret.vals[2][2] = cos(theta);
	return ret;
}

Matrix Matrix::y_rotation(float theta) {
	Matrix ret;
	ret.vals[0][0] = cos(theta);
	ret.vals[0][1] = 0;
	ret.vals[0][2] = sin(theta);

	ret.vals[1][0] = 0;
	ret.vals[1][1] = 1;
	ret.vals[1][2] = 0;

	ret.vals[2][0] = -sin(theta);
	ret.vals[2][1] = 0;
	ret.vals[2][2] = cos(theta);
	return ret;
}

Matrix Matrix::z_rotation(float theta) {
	Matrix ret;
	ret.vals[0][0] = cos(theta);
	ret.vals[0][1] = -sin(theta);
	ret.vals[0][2] = 0;

	ret.vals[1][0] = sin(theta);
	ret.vals[1][1] = cos(theta);
	ret.vals[1][2] = 0;

	ret.vals[2][0] = 0;
	ret.vals[2][1] = 0;
	ret.vals[2][2] = 1;
	return ret;
}

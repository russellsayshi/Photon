#include <iostream>
#include <cstring>
#include <cmath>

/*
************************************************
 WARNING this file is CURSED only write code if
     already you have made your offering
***********************************************
*/

/*
#define X_RES 40
#define Y_RES 50


void render(bool pixels[][Y_RES]) {
	for(int x = 0; x < X_RES; x++) {
		for(int y = 0; y < X_RES; y++) {
			std::cout << (pixels[X_RES][Y_RES] ? "# " : ". ");
		}
	}
}


class float3 {
public:
	float v1, v2, v3;

public:
	float3(float a, float b, float c) : v1(a), v2(b), v3(c) {}

	float3 operator-(float3 other) {
		return float3(v1-other.v1, v2-other.v2, v3-other.v3);
	}

	float dotProduct(float3 other) {
		return v1*other.v1 + v2*other.v2 + v3*other.v3;
	}

	float3 operator*(float other) {
		return float3(v1*other, v2*other, v3*other);
	}

	float3 operator+(float3 other) {
		return float3(v1+other.v1, v2+other.v2, v3+other.v3);
	}
};

float dot(float3 a, float3 b) {
	return a.dotProduct(b);
}
class UnitVec : public float3 {
public:
	UnitVec(float a, float b, float c) : float3(0, 0, 0) {
		float magnitude = sqrt(a*a + b*b + c*c);
		a /= magnitude;
		b /= magnitude;
		c /= magnitude;
		v1 = a;
		v2 = b;
		v3 = c;
	}

	UnitVec(float3 a) : UnitVec(a.v1, a.v2, a.v3) {}

	UnitVec operator*(float other) {
		UnitVec a(float3::operator*(other));
		return a;
	}
};

UnitVec operator*(float f, UnitVec vec) {
	return vec * f;
}

float3 operator*(float f, float3 vec) {
	return vec * f;
}


UnitVec operator/(UnitVec vec, float f) {
	return vec * (1/f);
}

float3 operator/(float3 vec, float f) {
	return vec * (1/f);
}

class ray {
public:
	float3 start;
	UnitVec vector;
	ray(float3 start, UnitVec vector) 
		: start(start), vector(vector) {}
};

bool intersects(float3 c, float r, ray ray) {
	float3 s = ray.start;
	UnitVec d = ray.vector;

	// Calculate ray start's offset from the sphere center
	float3 p = s - c;

	float rSquared = r * r;
	float p_d = dot(p, d);

	// The sphere is behind or surrounding the start point.
	if(p_d > 0 || dot(p, p) < rSquared) {
 		//return NO_COLLISION;
		return false;
	}

	// Flatten p into the plane passing through c perpendicular to the ray.
	// This gives the closest approach of the ray to the center.
	float3 a = p - p_d * d;

	float aSquared = dot(a, a);

	// Closest approach is outside the sphere.
	if(aSquared > rSquared) {
  		//return 999999;
		return false;
	}

	// Calculate distance from plane where ray enters/exits the sphere.    
	float h = sqrt(rSquared - aSquared);

	// Calculate intersection point relative to sphere center.
	float3 i = a - h * d;

	float3 intersection = c + i;
	float3 normal = i/r;
	// We've taken a shortcut here to avoid a second square root.
	// Note numerical errors can make the normal have length slightly different from 1.
	// If you need higher precision, you may need to perform a conventional normalization.

	//return (intersection, normal);
	return true;
}

int main(int argc, char** argv) {
	bool pixels[X_RES][Y_RES];
	memset(pixels, 0, X_RES*Y_RES*sizeof(bool));
	
	render(pixels);
	
	return 0;
}*/

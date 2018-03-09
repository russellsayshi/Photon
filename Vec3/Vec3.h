#ifndef VEC3_HEADER
#define VEC3_HEADER

#include <iostream>
#include <cmath>
#include <string>

class Vec3 {
    float x, y, z;
public:
    //constructors
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    //getters
    float getX() { return x; }
    float getY() { return y; }
    float getZ() { return z; }

    //setters
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }

    //operators
    Vec3 operator+(const Vec3& other) { return Vec3 (this->x + other.x, this->y + other.y, this->z + other.z); } //addition
    Vec3& operator+=(const Vec3& other) { return *this = *this + other; } //compound assignment addition
    Vec3 operator-(const Vec3& other) { return Vec3 (this->x - other.x, this->y - other.y, this->z - other.z); } //subtraction
    Vec3& operator-=(const Vec3& other) { return *this = *this - other; } //compound assignment subtraction
    Vec3 operator*(const float f) { return Vec3 (this->x * f, this->y * f, this->z * f); } //multiplication by scalar
    Vec3& operator*=(const float f) { return *this = *this * f; } //compound assignment multiplication
    bool operator==(const Vec3& other) { return abs(this->x - other.x) < .001 && abs(this->y - other.y) < .001 && abs(this->z - other.z) < .001; } //equality
    bool operator!=(const Vec3& other) { return !(*this == other); } //not equal to
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v) { return os << "[" << v.x << ", " << v.y << ", " << v.z << "]"; } //stream insertion
    
    //dot and cross products
    float dot(const Vec3& other) { return this->x * other.x + this->y * other.y + this->z * other.z; } //dot product
    Vec3 cross(const Vec3& other) { return Vec3 (this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x); } //cross product

    //other methods
    float mag() { return sqrt(this->x * this->x + this->y * this->y + this->z * this->z); } //returns the magnitude
    Vec3 norm() { float l = this->mag(); return Vec3 (this->x / l, this->y / l, this->z / l); } //returns a normalized vector
};

#endif

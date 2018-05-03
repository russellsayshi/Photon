#ifndef VEC3_HEADER
#define VEC3_HEADER

#include <iostream>
#include <cmath>
#include <string>

struct Vec3 {
    float x, y, z;

    //constructors
    Vec3() : x(0), y(0), z(0) {}
    Vec3(const float x, const float y, const float z) : x(x), y(y), z(z) {}
    Vec3(const Vec3& other) : x(other.x), y(other.y), z(other.z) {}

    //operators
    Vec3 operator+(const Vec3& other) const { return Vec3 (this->x + other.x, this->y + other.y, this->z + other.z); } //addition
    Vec3& operator+=(const Vec3& other) { return *this = *this + other; } //compound assignment addition
    Vec3 operator-(const Vec3& other) const { return Vec3 (this->x - other.x, this->y - other.y, this->z - other.z); } //subtraction
    Vec3& operator-=(const Vec3& other) { return *this = *this - other; } //compound assignment subtraction
    Vec3 operator*(const float f) const { return Vec3 (this->x * f, this->y * f, this->z * f); } //multiplication by scalar
    Vec3& operator*=(const float f) { return *this = *this * f; } //compound assignment multiplication
    bool operator==(const Vec3& other) const { return abs(this->x - other.x) < .001 && abs(this->y - other.y) < .001 && abs(this->z - other.z) < .001; } //equality
    bool operator!=(const Vec3& other) const { return !(*this == other); } //not equal to
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v) { return os << "[" << v.x << ", " << v.y << ", " << v.z << "]"; } //stream insertion
    
    //dot and cross products
    float dot(const Vec3& other) const { return this->x * other.x + this->y * other.y + this->z * other.z; } //dot product
    Vec3 cross(const Vec3& other) const { return Vec3 (this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x); } //cross product

    //other methods
    float mag() const { return sqrt(this->x * this->x + this->y * this->y + this->z * this->z); } //returns the magnitude
    Vec3 norm() const { float l = this->mag(); return Vec3 (this->x / l, this->y / l, this->z / l); } //returns a normalized vector
};

#endif

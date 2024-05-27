#include "../lib/Vector3.h"

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z) {}

Vector3& Vector3::operator=(const Vector3& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector3::~Vector3() {}

Vector3 Vector3::operator+(const Vector3& v) {
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3& Vector3::operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

float Vector3::operator*(const Vector3& v) {
    return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::operator%(const Vector3& v) {
    return Vector3(
                y * v.z - z * v.y,
                z * v.x - x * v.z,
                x * v.y - y * v.x
            );
}

Vector3& Vector3::scale(float s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

float Vector3::length() {
    return sqrt(x*x + y*y + z*z);
}

Vector3& Vector3::normalize() {
    float len = length();
    x /= len;
    y /= len;
    z /= len;
    return *this;
}

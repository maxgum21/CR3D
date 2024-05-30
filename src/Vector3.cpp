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

Vector3& Vector3::scale(float s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

float Vector3::length() const {
    return sqrt(x*x + y*y + z*z);
}

Vector3& Vector3::normalize() {
    float len = length();
    x /= len;
    y /= len;
    z /= len;
    return *this;
}

Vector3 Vector3::normalized() const {
    float len = length();
    return Vector3(
            x / len,
            y / len,
            z / len);
}

Vector3 Vector3::operator+(const Vector3& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

float Vector3::operator*(const Vector3& v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::operator%(const Vector3& v) const {
    return Vector3(
                y * v.z - z * v.y,
                z * v.x - x * v.z,
                x * v.y - y * v.x
            );
}


Vector3 Vector3::operator*(float t) const {
    return Vector3(*this).scale(t);
}

float Vector3::getDistance(const Vector3& a, const Vector3& b) {
    return (a - b).length();
}

Vector3 Vector3::lerp(const Vector3& a, const Vector3& b, float t) {
    return a + ((b - a) * t);
}

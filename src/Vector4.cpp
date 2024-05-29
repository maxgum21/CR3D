#include "../lib/Vector4.h"

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
Vector4::Vector4(const Vector4& v)
    : x(v.x), y(v.y), z(v.z), w(v.w) {}

Vector4& Vector4::operator=(const Vector4& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

Vector4::~Vector4() {}

Vector4& Vector4::operator+=(const Vector4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

Vector4& Vector4::operator-=(const Vector4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

Vector4& Vector4::scale(float s) {
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
}

float Vector4::length() const {
    return sqrt(x*x + y*y + z*z + w*w);
}

Vector4& Vector4::normalize() {
    float len = length();
    x /= len;
    y /= len;
    z /= len;
    w /= len;
    return *this;
}

Vector4 Vector4::normalized() const {
    float len = length();
    return Vector4(
            x / len,
            y / len,
            z / len,
            w / len);
}


Vector4 Vector4::operator+(const Vector4& v) const {
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4 Vector4::operator-(const Vector4& v) const {
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

float Vector4::operator*(const Vector4& v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

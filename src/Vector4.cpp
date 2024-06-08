#include "../lib/Vector4.h"
#include <math.h>

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
Vector4::Vector4(const Vector4& v)
    : x(v.x), y(v.y), z(v.z), w(v.w) {}

Vector4::Vector4(const Vector2& v)
    : x(v.x), y(v.y), z(0), w(1) {}

Vector4::Vector4(const Vector3& v)
    : x(v.x), y(v.y), z(v.z), w(1) {}

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

Vector4 Vector4::operator*(float t) const {
    return Vector4(*this).scale(t);
}

float Vector4::getDistance(const Vector4& a, const Vector4& b) {
    return (a - b).length();
}

Vector4 Vector4::lerp(const Vector4& a, const Vector4& b, float t) {
    return a + ((b - a) * t);
}

void Vector4::operator<<(std::stringstream& stream) const {
    stream << x << ' ' << y << ' ' << z << ' ' << w << '\n';
}

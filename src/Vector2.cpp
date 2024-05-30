#include "../lib/Vector2.h"
#include <cmath>

Vector2::Vector2(float x, float y) : x(x), y(y) {}
Vector2::Vector2(const Vector2& v)
    : x(v.x), y(v.y) {}

Vector2& Vector2::operator=(const Vector2& v) {
    x = v.x;
    y = v.y;
    return *this;
}

Vector2::~Vector2() {}

Vector2& Vector2::operator+=(const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}


Vector2& Vector2::scale(float s) {
    x *= s;
    y *= s;
    return *this;
}

float Vector2::length() const {
    return sqrt(x*x + y*y);
}

Vector2& Vector2::normalize() {
    float len = length();
    x /= len;
    y /= len;
    return *this;
}

Vector2 Vector2::normalized() const {
    float len = length();
    return Vector2(
            x / len,
            y / len
            );
}


Vector2 Vector2::operator+(const Vector2& v) const {
    return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v) const {
    return Vector2(x - v.x, y - v.y);
}

float Vector2::operator*(const Vector2& v) const {
    return x * v.x + y * v.y;
}

float Vector2::operator%(const Vector2& v) const {
    return (x * v.y) - (y * v.x);
}

Vector2 Vector2::operator*(const float t) const {
    return Vector2(*this).scale(t);
}

float Vector2::getDistance(const Vector2& a, const Vector2& b) {
    return (a - b).length();
}

Vector2 Vector2::lerp(const Vector2& a, const Vector2& b, float t) {
    return a + ((b - a) * t);
}

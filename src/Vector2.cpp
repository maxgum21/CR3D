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

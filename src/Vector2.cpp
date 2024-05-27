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

Vector2 Vector2::operator+(const Vector2& v) {
    return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v) {
    return Vector2(x - v.x, y - v.y);
}

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

float Vector2::operator*(const Vector2& v) {
    return x * v.x + y * v.y;
}

float Vector2::operator%(const Vector2& v) {
    return x * v.y - y * v.x;
}

Vector2& Vector2::scale(float s) {
    x *= s;
    y *= s;
    return *this;
}

float Vector2::length() {
    return sqrt(x*x + y*y);
}

Vector2& Vector2::normalize() {
    float len = length();
    x /= len;
    y /= len;
    return *this;
}

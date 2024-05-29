#include "../lib/Matrix2x2.h"
#include "../lib/Vector2.h"

Matrix2x2::Matrix2x2()
    : m00(0), m01(0),
      m10(0), m11(0) {}


Matrix2x2::Matrix2x2(float s)
    : m00(s), m01(0),
      m10(0), m11(s)  {}


Matrix2x2::Matrix2x2(float m00, float m01,
                     float m10, float m11) 
    : m00(m00), m01(m01),
      m10(m10), m11(m11) {} 

Matrix2x2::Matrix2x2(const Vector2& a, const Vector2& b)
    : m00(a.x), m01(a.y), m10(b.x), m11(b.y) {}

Matrix2x2::Matrix2x2(const Matrix2x2& m)
    : m00(m.m00), m01(m.m01),
      m10(m.m10), m11(m.m11) {} 

Matrix2x2::~Matrix2x2() {}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& m) {
    m00 = m.m00;
    m01 = m.m01;
    m10 = m.m10;
    m11 = m.m11;
    return *this;
}

Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& m) {
    m00 += m.m00;
    m01 += m.m01;
    m10 += m.m10;
    m11 += m.m11;
    return *this;
}

Matrix2x2& Matrix2x2::operator-=(const Matrix2x2& m) {
    m00 -= m.m00;
    m01 -= m.m01;
    m10 -= m.m10;
    m11 -= m.m11;
    return *this;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& m) const {
    return Matrix2x2(
            m00 + m.m00,  m01 + m.m01,
            m10 + m.m10,  m11 + m.m11
            );
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& m) const {
    return Matrix2x2(
            m00 - m.m00,  m01 - m.m01,
            m10 - m.m10,  m11 - m.m11
            );
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2& m) const {
    return Matrix2x2(
            m00 * m.m00 + m01 * m.m10,  m00 * m.m01 + m01 * m.m11,
            m10 * m.m00 + m11 * m.m10,  m10 * m.m01 + m11 * m.m11
            );
}

Vector2 Matrix2x2::operator*(const Vector2& v) const {
    return Vector2(
            m00 * v.x + m01 * v.y,
            m10 * v.x + m11 * v.y
            );
}


Matrix2x2& Matrix2x2::transpose() {
    float temp = m01;
    m01 = m10;
    m10 = temp;
    return *this;
}

Matrix2x2 Matrix2x2::transposed() const {
    return Matrix2x2(m00, m10,
                     m01, m11);
}

Matrix2x2& Matrix2x2::invert() {
    float d = det();

    float n_m00 = -m11;
    float n_m01 = m10;
    float n_m10 = -m11;
    float n_m11 = m01;

    m00 = n_m00 / d;
    m01 = n_m01 / d;
    m10 = n_m10 / d;
    m11 = n_m11 / d;
    return *this;
}

Matrix2x2 Matrix2x2::inverted() const {
    float d = det();
    return Matrix2x2(
            -m11 / d, m01 / d,
            m10 / d, -m11 / d
            );
}

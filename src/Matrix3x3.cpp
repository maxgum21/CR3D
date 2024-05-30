#include "../lib/Matrix3x3.h"
#include <cmath>

Matrix3x3::Matrix3x3()
    : m00(0), m01(0), m02(0),
      m10(0), m11(0), m12(0), 
      m20(0), m21(0), m22(0) {}


Matrix3x3::Matrix3x3(float s)
    : m00(s), m01(0), m02(0),
      m10(0), m11(s), m12(0),
      m20(0), m21(0), m22(s) {}


Matrix3x3::Matrix3x3(float m00, float m01, float m02,
                     float m10, float m11, float m12,
                     float m20, float m21, float m22) 
    : m00(m00), m01(m01), m02(m02),
      m10(m10), m11(m11), m12(m12),
      m20(m20), m21(m21), m22(m22) {} 

Matrix3x3::Matrix3x3(const Vector3& a, const Vector3& b, const Vector3& c)
    : m00(a.x), m01(a.y), m02(a.z),
      m10(b.x), m11(b.y), m12(b.z),
      m20(c.x), m21(c.y), m22(c.z) {}

Matrix3x3::Matrix3x3(const Matrix3x3& m) 
    : m00(m.m00), m01(m.m01), m02(m.m02),
      m10(m.m10), m11(m.m11), m12(m.m12),
      m20(m.m20), m21(m.m21), m22(m.m22) {} 

Matrix3x3::~Matrix3x3() {}

Matrix3x3& Matrix3x3::operator=(const Matrix3x3& m) {
    m00 = m.m00; m01 = m.m01; m02 = m.m02;
    m10 = m.m10; m11 = m.m11; m12 = m.m12;
    m20 = m.m20; m21 = m.m21; m22 = m.m22;
    return *this;
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& m) {
    m00 += m.m00; m01 += m.m01; m02 += m.m02;
    m10 += m.m10; m11 += m.m11; m12 += m.m12;
    m20 += m.m20; m21 += m.m21; m22 += m.m22;
    return *this;
}

Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& m) {
    m00 -= m.m00; m01 -= m.m01; m02 -= m.m02;
    m10 -= m.m10; m11 -= m.m11; m12 -= m.m12;
    m20 -= m.m20; m21 -= m.m21; m22 -= m.m22;
    return *this;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& m) const {
    return Matrix3x3(
            m00 + m.m00,  m01 + m.m01, m02 + m.m02,
            m10 + m.m10,  m11 + m.m11, m12 + m.m02,
            m20 + m.m20,  m21 + m.m21, m22 + m.m22
            );
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& m) const {
    return Matrix3x3(
            m00 - m.m00,  m01 - m.m01, m02 - m.m02,
            m10 - m.m10,  m11 - m.m11, m02 - m.m02,
            m20 - m.m20,  m21 - m.m21, m22 - m.m22
            );
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& m) const {
    return Matrix3x3(
            m00*m.m00+m01*m.m10+m02*m.m20,
            m00*m.m01+m01*m.m11+m02*m.m21,
            m00*m.m02+m01*m.m12+m02*m.m22,

            m10*m.m00+m11*m.m10+m12*m.m20,
            m10*m.m01+m11*m.m11+m12*m.m21,
            m10*m.m02+m11*m.m12+m12*m.m22,

            m20*m.m00+m21*m.m10+m22*m.m20,
            m20*m.m01+m21*m.m11+m22*m.m21,
            m20*m.m02+m21*m.m12+m22*m.m22
            );
}

Vector3 Matrix3x3::operator*(const Vector3& v) const {
    return Vector3(
            m00 * v.x + m01 * v.y + m02 * v.z,
            m10 * v.x + m11 * v.y + m12 * v.z,
            m20 * v.x + m21 * v.y + m22 * v.z
            );
}

Matrix3x3& Matrix3x3::scale(const float s) {
    m00 *= s;
    m01 *= s;
    m02 *= s;

    m10 *= s;
    m11 *= s;
    m12 *= s;

    m20 *= s;
    m21 *= s;
    m22 *= s;

    return *this;

}

Matrix3x3 Matrix3x3::scaled(const float s) const {
    return Matrix3x3(*this).scale(s);
}

void fSwap(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
}

Matrix3x3& Matrix3x3::transpose() {
    fSwap(m01, m10);
    fSwap(m02, m20);
    fSwap(m12, m21);
    return *this;
}

Matrix3x3 Matrix3x3::transposed() const {
    return Matrix3x3(m00, m10, m20,
                     m01, m11, m21,
                     m02, m12, m22);
}

Matrix3x3& Matrix3x3::invert() {
    float d = det();

    if (!d) return *this;

    float n00 = m11*m22 - m12*m21;
    float n01 = m12*m20 - m10*m22;
    float n02 = m10*m21 - m11*m20;

    float n10 = m02*m21 - m01*m22;
    float n11 = m00*m22 - m20*m02;
    float n12 = m01*m20 - m00*m21;

    float n20 = m01*m12 - m11*m02;
    float n21 = m02*m21 - m00*m12;
    float n22 = m00*m11 - m10*m01;

    m00 = n00 / d;
    m01 = n10 / d;
    m02 = n20 / d;

    m10 = n01 / d;
    m11 = n11 / d;
    m12 = n21 / d;

    m20 = n02 / d;
    m21 = n12 / d;
    m22 = n22 / d;

    return *this;
}

Matrix3x3 Matrix3x3::inverted() const {
    return Matrix3x3(*this).invert();
}

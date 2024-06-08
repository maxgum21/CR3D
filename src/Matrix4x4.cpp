#include "../lib/Matrix4x4.h"

Matrix4x4::Matrix4x4()
    : m00(0), m01(0), m02(0), m03(0),
      m10(0), m11(0), m12(0), m13(0), 
      m20(0), m21(0), m22(0), m23(0), 
      m30(0), m31(0), m32(0), m33(0) {}


Matrix4x4::Matrix4x4(float s)
    : m00(s), m01(0), m02(0), m03(0),
      m10(0), m11(s), m12(0), m13(0), 
      m20(0), m21(0), m22(s), m23(0), 
      m30(0), m31(0), m32(0), m33(s) {}


Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03,
                     float m10, float m11, float m12, float m13,
                     float m20, float m21, float m22, float m23,
                     float m30, float m31, float m32, float m33) 
    : m00(m00), m01(m01), m02(m02), m03(m03),
      m10(m10), m11(m11), m12(m12), m13(m13),
      m20(m20), m21(m21), m22(m22), m23(m23),
      m30(m30), m31(m31), m32(m32), m33(m33) {}

Matrix4x4::Matrix4x4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d)
    : m00(a.x), m01(a.y), m02(a.z), m03(a.w),
      m10(b.x), m11(b.y), m12(b.z), m13(b.w),
      m20(c.x), m21(c.y), m22(c.z), m23(c.w),
      m30(d.x), m31(d.y), m32(d.z), m33(d.w) {}

Matrix4x4::Matrix4x4(const Matrix4x4& m) 
    : m00(m.m00), m01(m.m01), m02(m.m02), m03(m.m03),
      m10(m.m10), m11(m.m11), m12(m.m12), m13(m.m13),
      m20(m.m20), m21(m.m21), m22(m.m22), m23(m.m23),
      m30(m.m30), m31(m.m31), m32(m.m32), m33(m.m33) {} 

Matrix4x4::~Matrix4x4() {}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& m) {
    m00 = m.m00; m01 = m.m01; m02 = m.m02; m03 = m.m03;
    m10 = m.m10; m11 = m.m11; m12 = m.m12; m13 = m.m13;
    m20 = m.m20; m21 = m.m21; m22 = m.m22; m23 = m.m23;
    m30 = m.m30; m31 = m.m31; m32 = m.m32; m33 = m.m33;
    return *this;
}

Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& m) {
    m00 += m.m00; m01 += m.m01; m02 += m.m02; m03 += m.m03;
    m10 += m.m10; m11 += m.m11; m12 += m.m12; m13 += m.m13;
    m20 += m.m20; m21 += m.m21; m22 += m.m22; m23 += m.m23;
    m30 += m.m30; m31 += m.m31; m32 += m.m32; m33 += m.m33;
    return *this;
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& m) {
    m00 -= m.m00; m01 -= m.m01; m02 -= m.m02; m03 -= m.m03;
    m10 -= m.m10; m11 -= m.m11; m12 -= m.m12; m13 -= m.m13;
    m20 -= m.m20; m21 -= m.m21; m22 -= m.m22; m23 -= m.m23;
    m30 -= m.m30; m31 -= m.m31; m32 -= m.m32; m33 -= m.m33;
    return *this;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& m) const {
    return Matrix4x4(
            m00 + m.m00,  m01 + m.m01, m02 + m.m02, m03 + m.m03,
            m10 + m.m10,  m11 + m.m11, m12 + m.m12, m13 + m.m13,
            m20 + m.m20,  m21 + m.m21, m22 + m.m22, m23 + m.m23,
            m30 + m.m30,  m31 + m.m31, m32 + m.m32, m33 + m.m33
            );
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& m) const {
    return Matrix4x4(
            m00 - m.m00,  m01 - m.m01, m02 - m.m02, m03 - m.m03,
            m10 - m.m10,  m11 - m.m11, m12 - m.m12, m13 - m.m13,
            m20 - m.m20,  m21 - m.m21, m22 - m.m22, m23 - m.m23,
            m30 - m.m30,  m31 - m.m31, m32 - m.m32, m33 - m.m33
            );
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& m) const {
    return Matrix4x4(
            m00*m.m00+m01*m.m10+m02*m.m20+m03*m.m30,
            m00*m.m01+m01*m.m11+m02*m.m21+m03*m.m31,
            m00*m.m02+m01*m.m12+m02*m.m22+m03*m.m32,
            m00*m.m03+m01*m.m13+m02*m.m23+m03*m.m33,

            m10*m.m00+m11*m.m10+m12*m.m20+m13*m.m30,
            m10*m.m01+m11*m.m11+m12*m.m21+m13*m.m31,
            m10*m.m02+m11*m.m12+m12*m.m22+m13*m.m32,
            m10*m.m03+m11*m.m13+m12*m.m23+m13*m.m33,

            m20*m.m00+m21*m.m10+m22*m.m20+m23*m.m30,
            m20*m.m01+m21*m.m11+m22*m.m21+m23*m.m31,
            m20*m.m02+m21*m.m12+m22*m.m22+m23*m.m32,
            m20*m.m03+m21*m.m13+m22*m.m23+m23*m.m33,

            m30*m.m00+m31*m.m10+m32*m.m20+m33*m.m30,
            m30*m.m01+m31*m.m11+m32*m.m21+m33*m.m31,
            m30*m.m02+m31*m.m12+m32*m.m22+m33*m.m32,
            m30*m.m03+m31*m.m13+m32*m.m23+m33*m.m33
            );
}

Vector4 Matrix4x4::operator*(const Vector4& v) const {
    return Vector4(
            m00 * v.x + m01 * v.y + m02 * v.z + m03 * v.w,
            m10 * v.x + m11 * v.y + m12 * v.z + m13 * v.w,
            m20 * v.x + m21 * v.y + m22 * v.z + m23 * v.w,
            m30 * v.x + m31 * v.y + m32 * v.z + m33 * v.w
            );
}

Matrix4x4& Matrix4x4::scale(const float s) {
    m00 *= s;
    m01 *= s;
    m02 *= s;
    m03 *= s;

    m10 *= s;
    m11 *= s;
    m12 *= s;
    m13 *= s;

    m20 *= s;
    m21 *= s;
    m22 *= s;
    m23 *= s;

    m30 *= s;
    m31 *= s;
    m32 *= s;
    m33 *= s;

    return *this;
}

Matrix4x4 Matrix4x4::scaled(const float s) const {
    return Matrix4x4(*this).scale(s);
}

Matrix4x4& Matrix4x4::transpose() {
    fSwap(m01, m10);
    fSwap(m02, m20);
    fSwap(m03, m30);


    fSwap(m12, m21);
    fSwap(m13, m31);

    fSwap(m23, m32);
    return *this;
}

Matrix4x4 Matrix4x4::transposed() const {
    return Matrix4x4(m00, m10, m20, m30,
                     m01, m11, m21, m30,
                     m01, m11, m21, m30,
                     m03, m13, m23, m33);
}

Matrix4x4& Matrix4x4::invert() {
    float d = det();

    if (!d) return *this;

    float n00 = Matrix3x3(m11, m12, m13,
                          m21, m22, m23,
                          m31, m32, m33).det();

    float n01 = Matrix3x3(m01, m02, m03,
                          m21, m22, m23,
                          m31, m32, m33).det();

    float n02 = Matrix3x3(m01, m02, m03,
                          m11, m12, m13,
                          m31, m32, m33).det();

    float n03 = Matrix3x3(m01, m02, m03,
                          m11, m12, m13,
                          m21, m22, m23).det();



    float n10 = Matrix3x3(m10, m12, m13,
                          m20, m22, m23,
                          m30, m32, m33).det();

    float n11 = Matrix3x3(m00, m02, m03,
                          m20, m22, m23,
                          m30, m32, m33).det();

    float n12 = Matrix3x3(m00, m02, m03,
                          m10, m12, m13,
                          m30, m32, m33).det();

    float n13 = Matrix3x3(m00, m02, m03,
                          m10, m12, m13,
                          m20, m22, m23).det();


    float n20 = Matrix3x3(m10, m11, m13,
                          m20, m21, m23,
                          m30, m31, m33).det();

    float n21 = Matrix3x3(m00, m01, m03,
                          m20, m21, m23,
                          m30, m31, m33).det();

    float n22 = Matrix3x3(m00, m01, m03,
                          m10, m11, m13,
                          m30, m31, m33).det();

    float n23 = Matrix3x3(m00, m01, m03,
                          m10, m11, m13,
                          m20, m21, m23).det();


    float n30 = Matrix3x3(m10, m11, m12,
                          m20, m21, m22,
                          m30, m31, m32).det();

    float n31 = Matrix3x3(m00, m01, m02,
                          m20, m21, m22,
                          m30, m31, m32).det();

    float n32 = Matrix3x3(m00, m01, m02,
                          m10, m11, m12,
                          m30, m31, m32).det();

    float n33 = Matrix3x3(m00, m01, m02,
                          m10, m11, m12,
                          m20, m21, m22).det();




    m00 = n00 / d;
    m01 = -n01 / d;
    m02 = n02 / d;
    m03 = -n03 / d;

    m10 = -n10 / d;
    m11 = n11 / d;
    m12 = -n12 / d;
    m13 = n13 / d;

    m20 = n20 / d;
    m21 = -n21 / d;
    m22 = n22 / d;
    m23 = -n23 / d;

    m30 = -n30 / d;
    m31 = n31 / d;
    m32 = -n32 / d;
    m33 = n33 / d;

    return *this;
}

Matrix4x4 Matrix4x4::inverted() const {
    return Matrix4x4(*this).invert();
}

Matrix4x4& Matrix4x4::scale(const Vector3& scale){
    this->m00 = this->m00 * scale.x;
    this->m01 = this->m01 * scale.x;
    this->m02 = this->m02 * scale.x;
    this->m03 = this->m03 * scale.x;
    this->m10 = this->m10 * scale.y;
    this->m11 = this->m11 * scale.y;
    this->m12 = this->m12 * scale.y;
    this->m13 = this->m13 * scale.y;
    this->m20 = this->m20 * scale.z;
    this->m21 = this->m21 * scale.z;
    this->m22 = this->m22 * scale.z;
    this->m23 = this->m23 * scale.z;
    
    return *this;
}

Matrix4x4& Matrix4x4::rotate(const Vector3& eulerAxis, float angle){
    float c = (float) cos(angle);
    float s = (float) sin(angle);
    float oneminusc = 1.0f - c;
    float xy = eulerAxis.x*eulerAxis.y;
    float yz = eulerAxis.y*eulerAxis.z;
    float xz = eulerAxis.x*eulerAxis.z;
    float xs = eulerAxis.x*s;
    float ys = eulerAxis.y*s;
    float zs = eulerAxis.z*s;

    float f00 = eulerAxis.x*eulerAxis.x*oneminusc+c;
    float f01 = xy*oneminusc+zs;
    float f02 = xz*oneminusc-ys;
    float f10 = xy*oneminusc-zs;
    float f11 = eulerAxis.y*eulerAxis.y*oneminusc+c;
    float f12 = yz*oneminusc+xs;
    float f20 = xz*oneminusc+ys;
    float f21 = yz*oneminusc-xs;
    float f22 = eulerAxis.z*eulerAxis.z*oneminusc+c;

    float t00 = this->m00 * f00 + this->m01 * f01 + this->m02 * f02;
    float t01 = this->m10 * f00 + this->m11 * f01 + this->m12 * f02;
    float t02 = this->m20 * f00 + this->m21 * f01 + this->m22 * f02;
    float t03 = this->m30 * f00 + this->m31 * f01 + this->m32 * f02;
    float t10 = this->m00 * f10 + this->m01 * f11 + this->m02 * f12;
    float t11 = this->m10 * f10 + this->m11 * f11 + this->m12 * f12;
    float t12 = this->m20 * f10 + this->m21 * f11 + this->m22 * f12;
    float t13 = this->m30 * f10 + this->m31 * f11 + this->m32 * f12;

    this->m02 = this->m00 * f20 + this->m01 * f21 + this->m02 * f22;
    this->m12 = this->m10 * f20 + this->m11 * f21 + this->m12 * f22;
    this->m22 = this->m20 * f20 + this->m21 * f21 + this->m22 * f22;
    this->m32 = this->m30 * f20 + this->m31 * f21 + this->m32 * f22;
    this->m00 = t00;
    this->m10 = t01;
    this->m20 = t02;
    this->m30 = t03;
    this->m01 = t10;
    this->m11 = t11;
    this->m21 = t12;
    this->m31 = t13;

    //this->transpose();

    return *this;}

Matrix4x4& Matrix4x4::translate(const Vector3& vec) {
    /*
    this->m30 += this->m00 * vec.x + this->m10 * vec.y + this->m20 * vec.z;
    this->m31 += this->m01 * vec.x + this->m11 * vec.y + this->m21 * vec.z;
    this->m32 += this->m02 * vec.x + this->m12 * vec.y + this->m22 * vec.z;
    this->m33 += this->m03 * vec.x + this->m13 * vec.y + this->m23 * vec.z;
    */

    *this = (*this) * Matrix4x4::translationMat(vec);

    /*
    Matrix4x4 trans = Matrix4x4(1);
    trans.m03 = vec.x;
    trans.m13 = vec.y;
    trans.m23 = vec.z;
    */

    //*this = trans * *this;

    //*this = *this * trans;

    return *this;
}


void Matrix4x4::operator<<(std::stringstream& stream) const {
    stream << '|' << m00 << ' ' << m01 << ' ' << m02 << ' ' << m03 << '|' << '\n'; 
    stream << '|' << m10 << ' ' << m11 << ' ' << m12 << ' ' << m13 << '|' << '\n'; 
    stream << '|' << m20 << ' ' << m21 << ' ' << m22 << ' ' << m23 << '|' << '\n'; 
    stream << '|' << m30 << ' ' << m31 << ' ' << m32 << ' ' << m33 << '|' << '\n'; 
}


Matrix4x4 Matrix4x4::translationMat(const Vector3& vec) {
    Matrix4x4 res(1);

    res.m03 = vec.x;
    res.m13 = vec.y;
    res.m23 = vec.z;

    return res;
}

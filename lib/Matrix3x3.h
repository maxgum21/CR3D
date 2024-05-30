#ifndef INCLUDE_MATRIX3X3_H
#define INCLUDE_MATRIX3X3_H

#include "defs.h"
#include "Vector3.h"

class Matrix3x3 {
    public:
        Matrix3x3();
        Matrix3x3(float s);
        Matrix3x3(float m00, float m01, float m02,
                  float m10, float m11, float m12,
                  float m20, float m21, float m22);
        Matrix3x3(const Vector3& a, const Vector3& b, const Vector3& c);
        Matrix3x3(const Matrix3x3& m);
        ~Matrix3x3();

        Matrix3x3& operator=(const Matrix3x3& m);

        Matrix3x3& operator+=(const Matrix3x3& m);
        Matrix3x3& operator-=(const Matrix3x3& m);

        Matrix3x3 operator+(const Matrix3x3& m) const;
        Matrix3x3 operator-(const Matrix3x3& m) const;
        Matrix3x3 operator*(const Matrix3x3& m) const;
        Vector3 operator*(const Vector3& v) const;

        Matrix3x3& scale(const float s);
        Matrix3x3 scaled(const float s) const;

        inline float det() const { return m00*m11*m22 + m01*m12*m20 + m10*m21*m02 -\
                                          m02*m11*m20 - m01*m10*m22 - m12*m21*m00; }

        Matrix3x3& transpose();
        Matrix3x3 transposed() const;

        Matrix3x3& invert();
        Matrix3x3 inverted() const; 
            
        float m00, m01, m02;
        float m10, m11, m12;
        float m20, m21, m22;
};

void fSwap(float& a, float& b);

#endif

#ifndef INCLUDE_MATRIX2X2_H
#define INCLUDE_MATRIX2X2_H

#include "../lib/Vector2.h"

class Matrix2x2 {
    public:
        Matrix2x2();
        Matrix2x2(float s);
        Matrix2x2(float m00, float m01,
                  float m10, float m11);
        Matrix2x2(const Vector2& a, const Vector2& b);
        Matrix2x2(const Matrix2x2& m);
        ~Matrix2x2();

        Matrix2x2& operator=(const Matrix2x2& m);

        Matrix2x2& operator+=(const Matrix2x2& m);
        Matrix2x2& operator-=(const Matrix2x2& m);

        Matrix2x2 operator+(const Matrix2x2& m) const;
        Matrix2x2 operator-(const Matrix2x2& m) const;
        Matrix2x2 operator*(const Matrix2x2& m) const;
        Vector2 operator*(const Vector2& v) const;

        Matrix2x2& scale(const float s);
        Matrix2x2 scaled(const float s) const;

        inline float det() const { return m00 * m11 - m01 * m10; }

        Matrix2x2& transpose();
        Matrix2x2 transposed() const;

        Matrix2x2& invert();
        Matrix2x2 inverted() const; 

    private:

        float m00, m01;
        float m10, m11;
};

#endif

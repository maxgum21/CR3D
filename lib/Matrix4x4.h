#ifndef INCLUDE_MATRIX4X4_H
#define INCLUDE_MATRIX4X4_H

#include "defs.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3x3.h"
#include <strstream>

class Matrix4x4 {
    public:
        Matrix4x4();
        Matrix4x4(float s);
        Matrix4x4(float m00, float m01, float m02, float m03,
                  float m10, float m11, float m12, float m13,
                  float m20, float m21, float m22,  float m23,
                  float m30, float m31, float m32,  float m33);
        Matrix4x4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d);
        Matrix4x4(const Matrix4x4& m);
        ~Matrix4x4();

        Matrix4x4& operator=(const Matrix4x4& m);

        Matrix4x4& operator+=(const Matrix4x4& m);
        Matrix4x4& operator-=(const Matrix4x4& m);

        Matrix4x4 operator+(const Matrix4x4& m) const;
        Matrix4x4 operator-(const Matrix4x4& m) const;
        Matrix4x4 operator*(const Matrix4x4& m) const;
        Vector4 operator*(const Vector4& v) const;

        static Matrix4x4 translationMat(const Vector3& vec);

        Matrix4x4& scale(const float s);
        Matrix4x4 scaled(const float s) const;

        Matrix4x4& rotate(const Vector3& eulerAxis, float angle);
        Matrix4x4& translate(const Vector3& vec);
        Matrix4x4& scale(const Vector3& scale);

        inline float det() const { return m03*m12*m21*m30 - m02*m13*m21*m30 
                                        - m03*m11*m22*m30 + m01*m13*m22*m30 
                                        + m02*m11*m23*m30 - m01*m12*m23*m30 
                                        - m03*m12*m20*m31 + m02*m13*m20*m31 
                                        + m03*m10*m22*m31 - m00*m13*m22*m31 
                                        - m02*m10*m23*m31 + m00*m12*m23*m31  
                                        + m03*m11*m20*m32 - m01*m13*m20*m32  
                                        - m03*m10*m21*m32 + m00*m13*m21*m32 
                                        + m01*m10*m23*m32 - m00*m11*m23*m32 
                                        - m02*m11*m20*m33 + m01*m12*m20*m33  
                                        + m02*m10*m21*m33 - m00*m12*m21*m33  
                                        - m01*m10*m22*m33 + m00*m11*m22*m33;
                                        }

        Matrix4x4& transpose();
        Matrix4x4 transposed() const;

        Matrix4x4& invert();
        Matrix4x4 inverted() const; 

        void print(std::stringstream& stream);
            
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
};

#endif

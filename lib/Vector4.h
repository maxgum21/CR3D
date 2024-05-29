#ifndef INCLUDE_VECTOR4_H
#define INCLUDE_VECTOR4_H
#include <math.h>

class Vector4 {
    public:
        Vector4(float x, float y, float z, float w);
        Vector4(const Vector4& v);
        ~Vector4();

        Vector4& operator=(const Vector4& v);

        Vector4& operator+=(const Vector4& v);
        Vector4& operator-=(const Vector4& v);
        
        Vector4 operator+(const Vector4& v) const ;
        Vector4 operator-(const Vector4& v) const ;
        float operator*(const Vector4& v) const ;

        Vector4& scale(float s);

        float length() const ;
        Vector4& normalize();
        Vector4 normalized() const;

        float x, y, z, w;
};

#endif

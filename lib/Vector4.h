#ifndef INCLUDE_VECTOR4_H
#define INCLUDE_VECTOR4_H

#include "defs.h"
#include <math.h>
#include <strstream>

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
        Vector4 operator*(float t) const ;
        float operator*(const Vector4& v) const ;

        Vector4& scale(float s);

        float length() const ;
        Vector4& normalize();
        Vector4 normalized() const;

        static float getDistance(const Vector4& a, const Vector4& b);
        static Vector4 lerp(const Vector4& a, const Vector4&b, float t);

        void print(std::stringstream& stream);

        float x, y, z, w;
};

#endif

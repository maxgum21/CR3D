#ifndef INCLUDE_VECTOR4_H
#define INCLUDE_VECTOR4_H

#include "Vector2.h"
#include "Vector3.h"

#include <sstream>

class Vector4 {
    public:
        Vector4(float x, float y, float z, float w);
        Vector4(const Vector2& v);
        Vector4(const Vector3& v);
        Vector4(const Vector4& v);
        ~Vector4();

        Vector4& operator=(const Vector4& v);

        Vector4& operator+=(const Vector4& v);
        Vector4& operator-=(const Vector4& v);
        
        Vector4 operator+(const Vector4& v) const ;
        Vector4 operator-(const Vector4& v) const ;
        Vector4 operator*(float t) const ;
        float operator*(const Vector4& v) const ;

        inline Vector2 getXY() { return Vector2(x, y); }
        inline Vector3 getXYZ() { return Vector3(x, y, z); }

        Vector4& scale(float s);

        float length() const ;
        Vector4& normalize();
        Vector4 normalized() const;

        static float getDistance(const Vector4& a, const Vector4& b);
        static Vector4 lerp(const Vector4& a, const Vector4&b, float t);

        void operator<<(std::stringstream& stream) const;

        float x, y, z, w;
};

#endif

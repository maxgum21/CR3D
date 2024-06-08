#ifndef INCLUDE_VECTOR3_H
#define INCLUDE_VECTOR3_H

#include <ostream>

class Vector3 {
    public:
        Vector3(float x, float y, float z);
        Vector3(const Vector3& v);
        ~Vector3();

        Vector3& operator=(const Vector3& v);

        Vector3& operator+=(const Vector3& v);
        Vector3& operator-=(const Vector3& v);

        Vector3 operator+(const Vector3& v) const;
        Vector3 operator-(const Vector3& v) const;
        Vector3 operator*(float t) const ;
        float operator*(const Vector3& v) const;
        Vector3 operator%(const Vector3& v) const;

        Vector3& scale(float s);
        Vector3& normalize();

        float length() const;
        Vector3 normalized() const;

        static float getDistance(const Vector3& a, const Vector3& b);
        static Vector3 lerp(const Vector3& a, const Vector3&b, float t);

        float x, y, z;
};

std::ostream& operator<<(std::ostream& ios, const Vector3& v);

#endif

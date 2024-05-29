#ifndef INCLUDE_VECTOR3_H
#define INCLUDE_VECTOR3_H
#include <math.h>

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
        float operator*(const Vector3& v) const;
        Vector3 operator%(const Vector3& v) const;

        Vector3& scale(float s);
        Vector3& normalize();

        float length() const;
        Vector3 normalized() const;

        float x, y, z;
};

#endif

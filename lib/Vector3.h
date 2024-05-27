#ifndef INCLUDE_VECTOR3_H
#define INCLUDE_VECTOR3_H
#include <math.h>

class Vector3 {
    public:
        Vector3(float x, float y, float z);
        Vector3(const Vector3& v);
        ~Vector3();

        Vector3& operator=(const Vector3& v);

        Vector3 operator+(const Vector3& v);
        Vector3 operator-(const Vector3& v);
        Vector3& operator+=(const Vector3& v);
        Vector3& operator-=(const Vector3& v);
        
        float operator*(const Vector3& v);
        Vector3 operator%(const Vector3& v);

        Vector3& scale(float s);

        float length();
        Vector3& normalize();

        float x, y, z;
};

#endif

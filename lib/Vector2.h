#ifndef INCLUDE_VECTOR2_H
#define INCLUDE_VECTOR2_H

class Vector2 {
    public:
        Vector2(float x, float y);
        Vector2(const Vector2& v);
        ~Vector2();

        Vector2& operator=(const Vector2& v);

        Vector2 operator+(const Vector2& v);
        Vector2 operator-(const Vector2& v);
        Vector2& operator+=(const Vector2& v);
        Vector2& operator-=(const Vector2& v);
        
        float operator*(const Vector2& v);
        float operator%(const Vector2& v);

        Vector2& scale(float s);

        float length();
        Vector2& normalize();

        float x, y;
};

#endif

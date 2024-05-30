#ifndef INCLUDE_VECTOR2_H
#define INCLUDE_VECTOR2_H

class Vector2 {
    public:
        Vector2(float x, float y);
        Vector2(const Vector2& v);
        ~Vector2();

        Vector2& operator=(const Vector2& v);

        Vector2& operator+=(const Vector2& v);
        Vector2& operator-=(const Vector2& v);

        Vector2 operator+(const Vector2& v) const;
        Vector2 operator-(const Vector2& v) const;
        Vector2 operator*(const float t) const;
        float operator*(const Vector2& v) const;
        float operator%(const Vector2& v) const;
        

        Vector2& scale(float s);

        float length() const;
        Vector2& normalize();
        Vector2 normalized() const;

        static float getDistance(const Vector2& a, const Vector2& b);
        static Vector2 lerp(const Vector2& a, const Vector2& b, float t);

        float x, y;
};

#endif

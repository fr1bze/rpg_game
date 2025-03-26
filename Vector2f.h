#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

class Vector2f {
public:
    float x, y;

    Vector2f() : x(0.0f), y(0.0f) {}
    Vector2f(float x, float y) : x(x), y(y) {}

    Vector2f operator+(const Vector2f& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2f& operator+=(const Vector2f& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2f operator-(const Vector2f& other) const {
        return {x - other.x, y - other.y};
    }

    Vector2f operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }

    float length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2f normalized() const {
        float len = length();
        if (len > 0) {
            return {x / len, y / len};
        }
        return *this;
    }
};

#endif // VECTOR2_H
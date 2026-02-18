#pragma once
#include <string>

class Maths
{
};

template <typename T>
struct Vector2
{
    T x;
    T y;

    Vector2* setX(T newX)
    {
        this->x = newX;
        return this;
    }

    Vector2* setY(T newY)
    {
        this->y = newY;
        return this;
    }

    Vector2* addX(T newX)
    {
        this->x += newX;
        return this;
    }

    Vector2* addY(T newY)
    {
        this->y += newY;
        return this;
    }

    Vector2() : x(0), y(0) {}
    Vector2(T x, T y) : x(x), y(y) {}
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector2<T>& v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

template <typename T>
struct Vector3
{
    T x;
    T y;
    T z;

    Vector3 setX(T newX)
    {
        this->x = newX;
        return this;
    }
    Vector3 setY(T newY)
    {
        this->y = newY;
        return this;
    }
    Vector3 setZ(T newZ)
    {
        this->z = newZ;
        return this;
    }

    Vector3 addX(T newX)
    {
        this->x += newX;
        return this;
    }
    Vector3 addY(T newY)
    {
        this->y += newY;
        return this;
    }
    Vector3 addZ(T newZ)
    {
        this->z += newZ;
        return this;
    }

    Vector3() : x(0), y(0), z(0) {}
    Vector3(T x, T y, T z) : x(x), y(y), z(z) {}
    Vector3(T x, T y) : x(x), y(y), z(0) {}
};

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;
using Vector2u = Vector2<unsigned int>;
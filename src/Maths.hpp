#pragma once

class Maths
{
};

template <typename T>
struct Vector2
{
    T x;
    T y;

    Vector2() : x(0), y(0) {}
    Vector2(T x, T y) : x(x), y(y) {}
};

template <typename T>
struct Vector3
{
    T x;
    T y;
    T z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(T x, T y, T z) : x(x), y(y), z(z) {}
    Vector3(T x, T y) : x(x), y(y), z(0) {}
};

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;
using Vector2u = Vector2<unsigned int>;
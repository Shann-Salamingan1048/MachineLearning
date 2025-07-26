#pragma once
#include "global.h"
#pragma once
#include "global.h"

// Vec1
template<Numeric Number>
struct Vec1 
{
    Number x;

    Vec1() : x(zero_init<Number>()) {}
    explicit Vec1(Number x) : x(x) {}

    Vec1 operator-(Number scalar) const noexcept { return Vec1(x - scalar); }
    Vec1 operator-(Vec1 other) const noexcept { return Vec1(x - other.x); }
    Vec1 operator+(Vec1 other) const noexcept { return Vec1(x + other.x); }
    Vec1 operator+(Number scalar) const noexcept { return Vec1(x + scalar); }
    Vec1 operator*(Vec1 other) const noexcept { return Vec1(x * other.x); }
    Vec1 operator*(Number scalar) const noexcept { return Vec1(x * scalar); }
};

// Vec2 
template<Numeric Number>
struct Vec2 
{
    Number x, y;

    Vec2() : x(zero_init<Number>()), y(zero_init<Number>()) {}
    Vec2(Number x, Number y) : x(x), y(y) {}
    explicit Vec2(Number v) : x(v), y(v) {}

    Vec2 operator-(Number scalar) const noexcept { return Vec2(x - scalar, y - scalar); }
    Vec2 operator-(Vec2 other) const noexcept { return Vec2(x - other.x, y - other.y); }
    Vec2 operator+(Vec2 other) const noexcept { return Vec2(x + other.x, y + other.y); }
    Vec2 operator+(Number scalar) const noexcept { return Vec2(x + scalar, y + scalar); }
    Vec2 operator*(Vec2 other) const noexcept { return Vec2(x * other.x, y * other.y); }
    Vec2 operator*(Number scalar) const noexcept { return Vec2(x * scalar, y * scalar); }
};

// Vec3
template<Numeric Number>
struct Vec3 
{
    Number x, y, z;

    Vec3() : x(zero_init<Number>()), y(zero_init<Number>()), z(zero_init<Number>()) {}
    Vec3(Number x, Number y, Number z) : x(x), y(y), z(z) {}
    explicit Vec3(Number v) : x(v), y(v), z(v) {}
    Vec3(Vec2<Number> xy, Number z) : x(xy.x), y(xy.y), z(z) {}

    Vec3 operator-(Number scalar) const noexcept { return Vec3(x - scalar, y - scalar, z - scalar); }
    Vec3 operator-(Vec3 other) const noexcept { return Vec3(x - other.x, y - other.y, z - other.z); }
    Vec3 operator+(Vec3 other) const noexcept { return Vec3(x + other.x, y + other.y, z + other.z); }
    Vec3 operator+(Number scalar) const noexcept { return Vec3(x + scalar, y + scalar, z + scalar); }
    Vec3 operator*(Vec3 other) const noexcept { return Vec3(x * other.x, y * other.y, z * other.z); }
    Vec3 operator*(Number scalar) const noexcept { return Vec3(x * scalar, y * scalar, z * scalar); }
};

// Vec4
template<Numeric Number>
struct Vec4 
{
    Number x, y, z, w;

    Vec4() : x(zero_init<Number>()), y(zero_init<Number>()),
        z(zero_init<Number>()), w(zero_init<Number>()) {
    }
    Vec4(Number x, Number y, Number z, Number w) : x(x), y(y), z(z), w(w) {}
    explicit Vec4(Number v) : x(v), y(v), z(v), w(v) {}
    Vec4(Vec3<Number> xyz, Number w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}

    Vec4 operator-(Number scalar) const noexcept { return Vec4(x - scalar, y - scalar, z - scalar, w - scalar); }
    Vec4 operator-(Vec4 other) const noexcept { return Vec4(x - other.x, y - other.y, z - other.z, w - other.w); }
    Vec4 operator+(Vec4 other) const noexcept { return Vec4(x + other.x, y + other.y, z + other.z, w + other.w); }
    Vec4 operator+(Number scalar) const noexcept { return Vec4(x + scalar, y + scalar, z + scalar, w + scalar); }
    Vec4 operator*(Vec4 other) const noexcept { return Vec4(x * other.x, y * other.y, z * other.z, w * other.w); }
    Vec4 operator*(Number scalar) const noexcept { return Vec4(x * scalar, y * scalar, z * scalar, w * scalar); }
};


using Vec1i = Vec1<int>;
using Vec1l = Vec1<long>;
using Vec1f = Vec1<float>;
using Vec1d = Vec1<double>;

using Vec2i = Vec2<int>;
using Vec2l = Vec2<long>;
using Vec2f = Vec2<float>;
using Vec2d = Vec2<double>;

using Vec3i = Vec3<int>;
using Vec3l = Vec3<long>;
using Vec3f = Vec3<float>;
using Vec3d = Vec3<double>;

using Vec4i = Vec4<int>;
using Vec4l = Vec4<long>;
using Vec4f = Vec4<float>;
using Vec4d = Vec4<double>;

template<Numeric Number>
void printVec1(const Vec1<Number>& v)
{
    std::println("{}", v.x);
}
template<Numeric Number>
void printVec2(const Vec2<Number>& v)
{
    std::println("{}, {}", v.x, v.y);
}
template<Numeric Number>
void printVec3(const Vec3<Number>& v)
{
    std::println("{}, {}, {}", v.x, v.y, v.z);
}
template<Numeric Number>
void printVec4(const Vec4<Number>& v)
{
    std::println("{}, {}, {}, {}", v.x, v.y, v.z, v.w);
}



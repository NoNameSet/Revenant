/*
	THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2015
*/

#pragma once

#include <windows.h>
#include <cstdint>
#include <Utils.h>
#include <numbers>

using Any = uint64_t;
using Void = uint64_t;
using ScrHandle = int;

using BLIP_INDEX = int;
using CAMERA_INDEX = int;
using ENTITY_INDEX = ScrHandle;
using FIRE_INDEX = int;
using Hash = unsigned int;
using INTERIOR_INSTANCE_INDEX = int;
using OBJECT_INDEX = ScrHandle;
using PED_INDEX = ScrHandle;
using PICKUP_INDEX = int;
using PLAYER_INDEX = unsigned int;
using VEHICLE_INDEX = ScrHandle;

class Vector2
{
public:
    Vector2() {}
    Vector2(float x_, float y_) : x(x_), y(y_) {}
    Vector2(float f_) : x(f_), y(f_) {}

    const Vector2 operator +() const { return *this; }
    const Vector2 operator -() const { return Vector2(-x, -y); }

    const Vector2 operator +(const Vector2& rhs) const { return Vector2(x + rhs.x, y + rhs.y); }
    const Vector2 operator -(const Vector2& rhs) const { return Vector2(x - rhs.x, y - rhs.y); }
    const Vector2 operator *(const Vector2& rhs) const { return Vector2(x * rhs.x, y * rhs.y); }
    const Vector2 operator /(const Vector2& rhs) const { return Vector2(x / rhs.x, y / rhs.y); }

    const Vector2 operator *(float rhs) const { return Vector2(x * rhs, y * rhs); }
    const Vector2 operator /(float rhs) const { return Vector2(x / rhs, y / rhs); }

    Vector2& operator +=(const Vector2& rhs) { (*this) = (*this) + rhs; return (*this); }
    Vector2& operator -=(const Vector2& rhs) { (*this) = (*this) - rhs; return (*this); }
    Vector2& operator *=(const Vector2& rhs) { (*this) = (*this) * rhs; return (*this); }
    Vector2& operator /=(const Vector2& rhs) { (*this) = (*this) / rhs; return (*this); }

    Vector2& operator *=(float rhs) { (*this) = (*this) * rhs; return (*this); }
    Vector2& operator /=(float rhs) { (*this) = (*this) / rhs; return (*this); }

    alignas(8) float x, y;
};

class Vector3
{
public:
    Vector3() {}
    Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    Vector3(float f_) : x(f_), y(f_), z(f_) {}

    const Vector3 operator +() const { return *this; }
    const Vector3 operator -() const { return Vector3(-x, -y, -z); }

    const Vector3 operator +(const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
    const Vector3 operator -(const Vector3& rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
    const Vector3 operator *(const Vector3& rhs) const { return Vector3(x * rhs.x, y * rhs.y, z * rhs.z); }
    const Vector3 operator /(const Vector3& rhs) const { return Vector3(x / rhs.x, y / rhs.y, z / rhs.z); }

    const Vector3 operator *(float rhs) const { return Vector3(x * rhs, y * rhs, z * rhs); }
    const Vector3 operator /(float rhs) const { return Vector3(x / rhs, y / rhs, z / rhs); }

    Vector3& operator +=(const Vector3& rhs) { (*this) = (*this) + rhs; return (*this); }
    Vector3& operator -=(const Vector3& rhs) { (*this) = (*this) - rhs; return (*this); }
    Vector3& operator *=(const Vector3& rhs) { (*this) = (*this) * rhs; return (*this); }
    Vector3& operator /=(const Vector3& rhs) { (*this) = (*this) / rhs; return (*this); }

    Vector3& operator *=(float rhs) { (*this) = (*this) * rhs; return (*this); }
    Vector3& operator /=(float rhs) { (*this) = (*this) / rhs; return (*this); }

    alignas(8) float x, y, z;

    static Vector3 Zero()
    {
        return {0, 0, 0};
    }

    [[nodiscard]] Vector3 Cross(const Vector3 &right) const
    {
        Vector3 result;
        result.x = y * right.z - z * right.y;
        result.y = z * right.x - x * right.z;
        result.z = x * right.y - y * right.x;
        return result;
    }

    [[nodiscard]] float Length() const
    {
        return sqrtf( (x * x) + (y * y) + (z * z) );
    }

    [[nodiscard]] float Magnitude() const
    {
        return Length();
    }

    [[nodiscard]] float Dot(const Vector3& right) const
    {
        return (x * right.x) + (y * right.y) + (z * right.z);
    }

    Vector3 Normalize()
    {
        float length = Length();
        if (length == 0.0f) return *this;

        Vector3 copy = *this;
        float norm = 1.0f / length;
        copy.x *= norm;
        copy.y *= norm;
        copy.z *= norm;

        return copy;
    }

    [[nodiscard]] Vector3 Lerp(const Vector3& to, float t) const
    {
        t = fmaxf(fminf(t, 1.0f), 0.0f);
        return {x + (to.x - x) * t, y + (to.y - y) * t, z + (to.z - z) * t};
    }

    [[nodiscard]] Vector3 Reflect(const Vector3& normal) const
    {
        float d = Dot(normal);
        return {x - 2.0f * d * normal.x, y - 2.0f * d * normal.y, z - 2.0f * d * normal.z};
    }

    [[nodiscard]] Vector3 Slerp(const Vector3& to, float t) const
    {
        t = fmaxf(fminf(t, 1.0f), 0.0f);
        float dot = Dot(to);
        float theta = acosf(dot);
        float sinTheta = sinf(theta);

        // Vectors are parallel
        if (sinTheta == 0.0f) {
            return Lerp(to, t);
        }

        float w1 = sinf((1.0f - t) * theta) / sinTheta;
        float w2 = sinf(t * theta) / sinTheta;

        return {x * w1 + to.x * w2, y * w1 + to.y * w2, z * w1 + to.z * w2};
    }

    [[nodiscard]] float Distance(const Vector3& other) const
    {
        float dx = x - other.x;
        float dy = y - other.y;
        float dz = z - other.z;
        return sqrtf(dx * dx + dy * dy + dz * dz);
    }

    static Vector3 RandomXY()
    {
        Vector3 v = Zero();
        double radian = RandomDouble(0.0, 1.0) * 2 * std::numbers::pi;
        v.x = (float) cos(radian);
        v.y = (float) sin(radian);
        v.Normalize();
        return v;
    }

    [[nodiscard]] Vector3 Around(float distance) const
    {
        return *this + (RandomXY() * distance);
    }
};

class Vector4
{
public:
    Vector4() {}
    Vector4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
    Vector4(float f_) : x(f_), y(f_), z(f_), w(f_) {}

    const Vector4 operator +() const { return *this; }
    const Vector4 operator -() const { return Vector4(-x, -y, -z, -w); }

    const Vector4 operator +(const Vector4& rhs) const { return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w); }
    const Vector4 operator -(const Vector4& rhs) const { return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w); }
    const Vector4 operator *(const Vector4& rhs) const { return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w); }
    const Vector4 operator /(const Vector4& rhs) const { return Vector4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w); }

    const Vector4 operator *(float rhs) const { return Vector4(x * rhs, y * rhs, z * rhs, w * rhs); }
    const Vector4 operator /(float rhs) const { return Vector4(x / rhs, y / rhs, z / rhs, w / rhs); }

    Vector4& operator +=(const Vector4& rhs) { (*this) = (*this) + rhs; return (*this); }
    Vector4& operator -=(const Vector4& rhs) { (*this) = (*this) - rhs; return (*this); }
    Vector4& operator *=(const Vector4& rhs) { (*this) = (*this) * rhs; return (*this); }
    Vector4& operator /=(const Vector4& rhs) { (*this) = (*this) / rhs; return (*this); }

    Vector4& operator *=(float rhs) { (*this) = (*this) * rhs; return (*this); }
    Vector4& operator /=(float rhs) { (*this) = (*this) / rhs; return (*this); }

    alignas(8) float x, y, z, w;
};

class RGBA
{
public:
    RGBA() {}
    RGBA(int r, int g, int b, int a) : R(r), G(g), B(b), A(a) {}

    int R;
    int G;
    int B;
    int A;
};
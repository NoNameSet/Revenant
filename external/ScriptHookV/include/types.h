/*
	THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2015
*/

#pragma once

#include <windows.h>
#include <cstdint>

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
#ifndef REVENANT_VECTOR_H
#define REVENANT_VECTOR_H

namespace rage
{
    template <typename T>
    union vector2
    {
        T data[2];
        struct
        {
            T x, y;
        };

        vector2(T x, T y) : x(x),
                            y(y)
        {
        }

        vector2() : x(),
                    y()
        {
        }
    };

    template <typename T>
    union vector3
    {
        T data[3];
        struct
        {
            T x, y, z;
        };

        vector3(T x, T y, T z) noexcept : x(x),
                                          y(y),
                                          z(z)
        {
        }

        vector3() noexcept : x(),
                             y(),
                             z()
        {
        }

        vector3 operator+(const vector3 &rhs) const
        {
            return vector3(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        vector3 operator-(const vector3 &rhs) const
        {
            return vector3(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        vector3 operator*(const vector3 &rhs) const
        {
            return vector3(x * rhs.x, y * rhs.y, z * rhs.z);
        }

        vector3 operator/(const vector3 &rhs) const
        {
            return vector3(x / rhs.x, y / rhs.y, z / rhs.z);
        }

        vector3 operator+(const float &rhs) const
        {
            return vector3(x + rhs, y + rhs, z + rhs);
        }

        vector3 operator-(const float &rhs) const
        {
            return vector3(x - rhs, y - rhs, z - rhs);
        }

        vector3 operator*(const float &rhs) const
        {
            return vector3(x * rhs, y * rhs, z * rhs);
        }

        vector3 operator/(const float &rhs) const
        {
            return vector3(x / rhs, y / rhs, z / rhs);
        }

        bool operator==(const vector3 &rhs) const
        {
            return x == rhs.x && y == rhs.y && z == rhs.z;
        }

        vector3 &operator+=(const vector3 &rhs)
        {
            return *this = *this + rhs;
        }

        vector3 &operator-=(const vector3 &rhs)
        {
            return *this = *this - rhs;
        }

        vector3 &operator*=(const vector3 &rhs)
        {
            return *this = *this * rhs;
        }

        vector3 &operator/=(const vector3 &rhs)
        {
            return *this = *this / rhs;
        }

        vector3 &operator+=(const float &rhs)
        {
            return *this = *this + rhs;
        }

        vector3 &operator-=(const float &rhs)
        {
            return *this = *this - rhs;
        }

        vector3 &operator*=(const float &rhs)
        {
            return *this = *this * rhs;
        }

        vector3 &operator/=(const float &rhs)
        {
            return *this = *this / rhs;
        }

        T length() const
        {
            return sqrt(x * x + y * y + z * z);
        }

        T magnitude() const
        {
            return length();
        }

        vector3 normalize() const
        {
            T len = length();
            if (len)
            {
                return *this * (1 / len);
            }

            return *this;
        }

        vector3 multiply(const vector3 rhs) const
        {
            return vector3(x * rhs.x, y * rhs.y, z * rhs.z);
        }

        vector3 invert() const
        {
            return *this * -1;
        }

        vector3 cross_product(const vector3 &rhs) const
        {
            return vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
        }

        float dot_product(const vector3 &rhs) const
        {
            return x * rhs.x + y * rhs.y + z * rhs.z;
        }

        float distance(const vector3 &rhs) const
        {
            return (*this - rhs).length();
        }
    };

    template <typename T>
    union vector4
    {
        T data[4];
        struct
        {
            T x, y, z, w;
        };

        vector4(T x, T y, T z, T w) : x(x),
                                      y(y),
                                      z(z),
                                      w(w)
        {
        }

        vector4() : x(),
                    y(),
                    z(),
                    w()
        {
        }
    };

    typedef vector2<float> fvector2;
    typedef vector3<float> fvector3;
    typedef vector4<float> fvector4;
}

#endif //REVENANT_VECTOR_H
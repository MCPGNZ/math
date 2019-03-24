#pragma once
#include <forward_list>

namespace mcpgnz
{
    template <typename T>
    struct vec3
    {
        #pragma warning (disable: 4201)
        union
        {
            T _v[3];
            struct
            {
                T _x;
                T _y;
                T _z;
            };
            struct
            {
                T _r;
                T _g;
                T _b;
            };
            struct
            {
                T _width;
                T _height;
                T _depth;
            };
        };
        #pragma warning (default: 4201)

        #pragma region methods
        vec3() : _x{ 0 }, _y{ 0 }, _z{ 0 } {}
        vec3(T v) : _x{ v }, _y{ v }, _z{ v } {}
        vec3(T x, T y, T z) : _x{ x }, _y{ y }, _z{ z } {}

        vec3(const vec3& other) = default;
        vec3& operator=(const vec3& other) = default;

        vec3(vec3&& other) = default;
        vec3& operator=(vec3&& other) = default;

        ~vec3() = default;
        #pragma endregion

        #pragma region operators
        bool operator== (const vec3& rhs) const;
        bool operator!= (const vec3& rhs) const;

        T operator[] (int i) const;
        T& operator[](int i);

        vec3 operator-() const;
        vec3 operator+() const;

        vec3 operator+ (const vec3& rhs) const;
        vec3 operator- (const vec3& rhs) const;
        vec3 operator* (const vec3& rhs) const;
        vec3 operator/ (const vec3& rhs) const;

        vec3& operator+= (const vec3& rhs);
        vec3& operator-= (const vec3& rhs);
        vec3& operator*= (const vec3& rhs);
        vec3& operator/= (const vec3& rhs);

        vec3 operator+ (T rhs) const;
        vec3 operator- (T rhs) const;
        vec3 operator* (T rhs) const;
        vec3 operator/ (T rhs) const;

        vec3& operator+= (T rhs);
        vec3& operator-= (T rhs);
        vec3& operator*= (T rhs);
        vec3& operator/= (T rhs);
        #pragma endregion

        #pragma region casts
        template <typename U>
        explicit operator vec3<U>() const
        {
            return vec3<U>{static_cast<U>(_x), static_cast<U>(_y), static_cast<U>(_z)};
        }

        template <typename U>
        static vec3<T> cast(const U other)
        {
            return vec3<T>{other.x, other.y, other.z};
        }
        #pragma endregion

        #pragma region statics
        static vec3 _zero;
        static vec3 _one;
        #pragma endregion
    };

    #pragma region operators
    template <typename T> vec3<T> operator+(T scalar, const vec3<T>& rhs);
    template <typename T> vec3<T> operator*(T scalar, const vec3<T>& rhs);
    template <typename T> vec3<T> operator/(T scalar, const vec3<T>& rhs);
    #pragma endregion

    #pragma region aliases
    using vec3d = vec3<double>;
    using vec3f = vec3<float>;
    using vec3i = vec3<std::int32_t>;
    using vec3u = vec3<std::uint32_t>;
    using vec3u8 = vec3<std::uint8_t>;
    #pragma endregion

    #pragma region statics
    template <typename T> vec3<T> vec3<T>::_zero = vec3<T>{ 0 };
    template <typename T> vec3<T> vec3<T>::_one = vec3<T>{ 1 };
    #pragma endregion

    #pragma region template implementation
    template <typename T> bool vec3<T>::operator==(const vec3<T>& rhs) const
    {
        return (_x == rhs._x && _y == rhs._y && _z == rhs._z);
    }
    template <typename T> bool vec3<T>::operator!=(const vec3<T>& rhs) const
    {
        return (_x != rhs._x || _y != rhs._y || _z != rhs._z);
    }

    template <typename T> T vec3<T>::operator[](const int i) const
    {
        return _v[i];
    }
    template <typename T> T& vec3<T>::operator[](const int i)
    {
        return _v[i];
    }

    template <typename T> vec3<T> vec3<T>::operator-() const
    {
        return vec3{ -_x, -_y, -_z };
    }
    template <typename T> vec3<T> vec3<T>::operator+() const
    {
        return *this;
    }

    template <typename T> vec3<T> vec3<T>::operator+ (const vec3<T>& rhs) const
    {
        return vec3{ _x + rhs._x, _y + rhs._y, _z + rhs._z };
    }
    template <typename T> vec3<T> vec3<T>::operator- (const vec3<T>& rhs) const
    {
        return vec3{ _x - rhs._x, _y - rhs._y, _z - rhs._z };
    }
    template <typename T> vec3<T> vec3<T>::operator* (const vec3<T>& rhs) const
    {
        return vec3{ _x * rhs._x, _y * rhs._y, _z * rhs._z };
    }
    template <typename T> vec3<T> vec3<T>::operator/ (const vec3<T>& rhs) const
    {
        return vec3{ _x / rhs._x, _y / rhs._y, _z / rhs._z };
    }

    template <typename T> vec3<T>& vec3<T>::operator+= (const vec3<T>& rhs)
    {
        _x += rhs._x;
        _y += rhs._y;
        _z += rhs._z;
        return *this;
    }
    template <typename T> vec3<T>& vec3<T>::operator-= (const vec3<T>& rhs)
    {
        _x -= rhs._x;
        _y -= rhs._y;
        _z -= rhs._z;
        return *this;
    }
    template <typename T> vec3<T>& vec3<T>::operator*= (const vec3<T>& rhs)
    {
        _x *= rhs._x;
        _y *= rhs._y;
        _z *= rhs._z;
        return *this;
    }
    template <typename T> vec3<T>& vec3<T>::operator/= (const vec3<T>& rhs)
    {
        _x /= rhs._x;
        _y /= rhs._y;
        _z /= rhs._z;
        return *this;
    }

    template <typename T> vec3<T> vec3<T>::operator+ (const T rhs) const
    {
        return vec3{ _x + rhs, _y + rhs, _z + rhs };
    }
    template <typename T> vec3<T> vec3<T>::operator- (const T rhs) const
    {
        return vec3{ _x - rhs, _y - rhs, _z - rhs };
    }
    template <typename T> vec3<T> vec3<T>::operator* (const T rhs) const
    {
        return vec3{ _x * rhs, _y * rhs, _z * rhs };
    }
    template <typename T> vec3<T> vec3<T>::operator/ (const T rhs) const
    {
        const T inv = 1 / rhs;
        return vec3{ _x * inv, _y * inv, _z * inv };
    }

    template <typename T> vec3<T>& vec3<T>::operator+= (const T rhs)
    {
        _x += rhs;
        _y += rhs;
        _z += rhs;
        return *this;
    }
    template <typename T> vec3<T>& vec3<T>::operator-= (const T rhs)
    {
        _x -= rhs;
        _y -= rhs;
        _z -= rhs;
        return *this;
    }
    template <typename T> vec3<T>& vec3<T>::operator*= (const T rhs)
    {
        _x *= rhs;
        _y *= rhs;
        _z *= rhs;
        return *this;
    }
    template <typename T> vec3<T>& vec3<T>::operator/= (const T rhs)
    {
        const T inv = 1 / rhs;
        _x *= inv;
        _y *= inv;
        _z *= inv;
        return *this;
    }

    template <typename T> vec3<T> operator+(const T scalar, const vec3<T>& rhs)
    {
        return rhs + scalar;
    }
    template <typename T> vec3<T> operator*(const T scalar, const vec3<T>& rhs)
    {
        return rhs * scalar;
    }
    template <typename T> vec3<T> operator/(const T scalar, const vec3<T>& rhs)
    {
        return vec3<T>{
            scalar / rhs.x,
                scalar / rhs.y,
                scalar / rhs.z
        };
    }
    #pragma endregion
}
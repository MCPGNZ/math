#pragma once
#include <forward_list>

namespace mcpgnz
{
    template <typename T>
    struct vec4
    {
        #pragma warning (disable: 4201)
        union
        {
            T _v[4];
            struct
            {
                T _x;
                T _y;
                T _z;
                T _w;
            };
            struct
            {
                T _r;
                T _g;
                T _b;
                T _a;
            };
        };
        #pragma warning (default: 4201)

        #pragma region methods
        vec4() : _x{ 0 }, _y{ 0 }, _z{ 0 }, _w{ 0 } {}
        vec4(T v) : _x{ v }, _y{ v }, _z{ v }, _w{ v } {}
        vec4(T x, T y, T z, T w) : _x{ x }, _y{ y }, _z{ z }, _w{ w } {}

        vec4(const vec4& other) = default;
        vec4& operator=(const vec4& other) = default;

        vec4(vec4&& other) = default;
        vec4& operator=(vec4&& other) = default;

        ~vec4() = default;
        #pragma endregion

        #pragma region operators
        bool operator== (const vec4& rhs) const;
        bool operator!= (const vec4& rhs) const;

        T operator[] (int i) const;
        T& operator[](int i);

        vec4 operator-() const;
        vec4 operator+() const;

        vec4 operator+ (const vec4& rhs) const;
        vec4 operator- (const vec4& rhs) const;
        vec4 operator* (const vec4& rhs) const;
        vec4 operator/ (const vec4& rhs) const;

        vec4& operator+= (const vec4& rhs);
        vec4& operator-= (const vec4& rhs);
        vec4& operator*= (const vec4& rhs);
        vec4& operator/= (const vec4& rhs);

        vec4 operator+ (T rhs) const;
        vec4 operator- (T rhs) const;
        vec4 operator* (T rhs) const;
        vec4 operator/ (T rhs) const;

        vec4& operator+= (T rhs);
        vec4& operator-= (T rhs);
        vec4& operator*= (T rhs);
        vec4& operator/= (T rhs);
        #pragma endregion

        #pragma region casts
        template <typename U>
        explicit operator vec4<U>() const
        {
            return vec4<U>{static_cast<U>(_x), static_cast<U>(_y), static_cast<U>(_z), static_cast<U>(_w)};
        }

        template <typename U>
        static vec4<T> cast(const U other)
        {
            return vec4<T>{other.x, other.y, other.z, other.w};
        }
        #pragma endregion

        #pragma region statics
        static vec4 _zero;
        static vec4 _one;
        #pragma endregion
    };

    #pragma region operators
    template <typename T> vec4<T> operator+(T scalar, const vec4<T>& rhs);
    template <typename T> vec4<T> operator*(T scalar, const vec4<T>& rhs);
    template <typename T> vec4<T> operator/(T scalar, const vec4<T>& rhs);
    #pragma endregion

    #pragma region aliases
    using vec4d = vec4<double>;
    using vec4f = vec4<float>;
    using vec4i = vec4<std::int32_t>;
    using vec4u = vec4<std::uint32_t>;
    using vec4u8 = vec4<std::uint8_t>;
    #pragma endregion

    #pragma region statics
    template <typename T> vec4<T> vec4<T>::_zero = vec4<T>{ 0 };
    template <typename T> vec4<T> vec4<T>::_one = vec4<T>{ 1 };
    #pragma endregion

    #pragma region template implementation
    template <typename T> bool vec4<T>::operator==(const vec4<T>& rhs) const
    {
        return (_x == rhs._x && _y == rhs._y && _z == rhs._z && _w == rhs._w);
    }
    template <typename T> bool vec4<T>::operator!=(const vec4<T>& rhs) const
    {
        return (_x != rhs._x || _y != rhs._y || _z != rhs._z || _w != rhs._w);
    }

    template <typename T> T vec4<T>::operator[](const int i) const
    {
        return _v[i];
    }
    template <typename T> T& vec4<T>::operator[](const int i)
    {
        return _v[i];
    }

    template <typename T> vec4<T> vec4<T>::operator-() const
    {
        return vec4{ -_x, -_y, -_z, -_w };
    }
    template <typename T> vec4<T> vec4<T>::operator+() const
    {
        return *this;
    }

    template <typename T> vec4<T> vec4<T>::operator+ (const vec4<T>& rhs) const
    {
        return vec4{ _x + rhs._x, _y + rhs._y, _z + rhs._z, _w + rhs._w };
    }
    template <typename T> vec4<T> vec4<T>::operator- (const vec4<T>& rhs) const
    {
        return vec4{ _x - rhs._x, _y - rhs._y, _z - rhs._z, _w - rhs._w };
    }
    template <typename T> vec4<T> vec4<T>::operator* (const vec4<T>& rhs) const
    {
        return vec4{ _x * rhs._x, _y * rhs._y, _z * rhs._z, _w * rhs._w };
    }
    template <typename T> vec4<T> vec4<T>::operator/ (const vec4<T>& rhs) const
    {
        return vec4{ _x / rhs._x, _y / rhs._y, _z / rhs._z, _w / rhs._w };
    }

    template <typename T> vec4<T>& vec4<T>::operator+= (const vec4<T>& rhs)
    {
        _x += rhs._x;
        _y += rhs._y;
        _z += rhs._z;
        _w += rhs._w;
        return *this;
    }
    template <typename T> vec4<T>& vec4<T>::operator-= (const vec4<T>& rhs)
    {
        _x -= rhs._x;
        _y -= rhs._y;
        _z -= rhs._z;
        _w -= rhs._w;
        return *this;
    }
    template <typename T> vec4<T>& vec4<T>::operator*= (const vec4<T>& rhs)
    {
        _x *= rhs._x;
        _y *= rhs._y;
        _z *= rhs._z;
        _w *= rhs._w;
        return *this;
    }
    template <typename T> vec4<T>& vec4<T>::operator/= (const vec4<T>& rhs)
    {
        _x /= rhs._x;
        _y /= rhs._y;
        _z /= rhs._z;
        _w /= rhs._w;
        return *this;
    }

    template <typename T> vec4<T> vec4<T>::operator+ (const T rhs) const
    {
        return vec4{ _x + rhs, _y + rhs, _z + rhs, _w + rhs };
    }
    template <typename T> vec4<T> vec4<T>::operator- (const T rhs) const
    {
        return vec4{ _x - rhs, _y - rhs, _z - rhs, _w - rhs };
    }
    template <typename T> vec4<T> vec4<T>::operator* (const T rhs) const
    {
        return vec4{ _x * rhs, _y * rhs, _z * rhs, _w * rhs };
    }
    template <typename T> vec4<T> vec4<T>::operator/ (const T rhs) const
    {
        const T inv = 1 / rhs;
        return vec4{ _x * inv, _y * inv, _z * inv, _w * inv };
    }

    template <typename T> vec4<T>& vec4<T>::operator+= (const T rhs)
    {
        _x += rhs;
        _y += rhs;
        _z += rhs;
        _w += rhs;
        return *this;
    }
    template <typename T> vec4<T>& vec4<T>::operator-= (const T rhs)
    {
        _x -= rhs;
        _y -= rhs;
        _z -= rhs;
        _w -= rhs;
        return *this;
    }
    template <typename T> vec4<T>& vec4<T>::operator*= (const T rhs)
    {
        _x *= rhs;
        _y *= rhs;
        _z *= rhs;
        _w *= rhs;
        return *this;
    }
    template <typename T> vec4<T>& vec4<T>::operator/= (const T rhs)
    {
        const T inv = 1 / rhs;
        _x *= inv;
        _y *= inv;
        _z *= inv;
        _w *= inv;
        return *this;
    }

    template <typename T> vec4<T> operator+(const T scalar, const vec4<T>& rhs)
    {
        return rhs + scalar;
    }
    template <typename T> vec4<T> operator*(const T scalar, const vec4<T>& rhs)
    {
        return rhs * scalar;
    }
    template <typename T> vec4<T> operator/(const T scalar, const vec4<T>& rhs)
    {
        return vec4<T>{
            scalar / rhs.x,
                scalar / rhs.y,
                scalar / rhs.z,
                scalar / rhs.w
        };
    }
    #pragma endregion
}
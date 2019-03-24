#pragma once
#include <forward_list>

namespace mcpgnz
{
    template <typename T>
    struct vec2
    {
        #pragma warning (disable: 4201)
        union
        {
            T _v[2];
            struct
            {
                T _x;
                T _y;
            };
            struct
            {
                T _r;
                T _g;
            };
            struct
            {
                T _width;
                T _height;
            };
        };
        #pragma warning (default: 4201)

        #pragma region methods
        vec2() : _x{ 0 }, _y{ 0 } {}
        vec2(T v) : _x{ v }, _y{ v } {}
        vec2(T x, T y) : _x{ x }, _y{ y } {}

        vec2(const vec2& other) = default;
        vec2& operator=(const vec2& other) = default;

        vec2(vec2&& other) = default;
        vec2& operator=(vec2&& other) = default;

        ~vec2() = default;
        #pragma endregion

        #pragma region operators
        bool operator== (const vec2& rhs) const;
        bool operator!= (const vec2& rhs) const;

        T operator[] (int i) const;
        T& operator[](int i);

        vec2 operator-() const;
        vec2 operator+() const;

        vec2 operator+ (const vec2& rhs) const;
        vec2 operator- (const vec2& rhs) const;
        vec2 operator* (const vec2& rhs) const;
        vec2 operator/ (const vec2& rhs) const;

        vec2& operator+= (const vec2& rhs);
        vec2& operator-= (const vec2& rhs);
        vec2& operator*= (const vec2& rhs);
        vec2& operator/= (const vec2& rhs);

        vec2 operator+ (T rhs) const;
        vec2 operator- (T rhs) const;
        vec2 operator* (T rhs) const;
        vec2 operator/ (T rhs) const;

        vec2& operator+= (T rhs);
        vec2& operator-= (T rhs);
        vec2& operator*= (T rhs);
        vec2& operator/= (T rhs);
        #pragma endregion

        #pragma region casts
        template <typename U>
        explicit operator vec2<U>() const
        {
            return vec2<U>{static_cast<U>(_x), static_cast<U>(_y)};
        }

        template <typename U>
        static vec2<T> cast(const U other)
        {
            return vec2<T>{other.x, other.y};
        }
        #pragma endregion

        #pragma region statics
        static vec2 _zero;
        static vec2 _one;
        #pragma endregion
    };

    #pragma region operators
    template <typename T> vec2<T> operator+(T scalar, const vec2<T>& rhs);
    template <typename T> vec2<T> operator*(T scalar, const vec2<T>& rhs);
    template <typename T> vec2<T> operator/(T scalar, const vec2<T>& rhs);
    #pragma endregion

    #pragma region aliases
    using vec2d = vec2<double>;
    using vec2f = vec2<float>;
    using vec2i = vec2<std::int32_t>;
    using vec2u = vec2<std::uint32_t>;
    using vec2u8 = vec2<std::uint8_t>;
    #pragma endregion

    #pragma region statics
    template <typename T> vec2<T> vec2<T>::_zero = vec2<T>{ 0 };
    template <typename T> vec2<T> vec2<T>::_one = vec2<T>{ 1 };
    #pragma endregion

    #pragma region template implementation
    template <typename T> bool vec2<T>::operator==(const vec2<T>& rhs) const
    {
        return (_x == rhs._x && _y == rhs._y);
    }
    template <typename T> bool vec2<T>::operator!=(const vec2<T>& rhs) const
    {
        return (_x != rhs._x || _y != rhs._y);
    }

    template <typename T> T vec2<T>::operator[](const int i) const
    {
        return _v[i];
    }
    template <typename T> T& vec2<T>::operator[](const int i)
    {
        return _v[i];
    }

    template <typename T> vec2<T> vec2<T>::operator-() const
    {
        return vec2{ -_x, -_y };
    }
    template <typename T> vec2<T> vec2<T>::operator+() const
    {
        return *this;
    }

    template <typename T> vec2<T> vec2<T>::operator+ (const vec2<T>& rhs) const
    {
        return vec2{ _x + rhs._x, _y + rhs._y };
    }
    template <typename T> vec2<T> vec2<T>::operator- (const vec2<T>& rhs) const
    {
        return vec2{ _x - rhs._x, _y - rhs._y };
    }
    template <typename T> vec2<T> vec2<T>::operator* (const vec2<T>& rhs) const
    {
        return vec2{ _x * rhs._x, _y * rhs._y };
    }
    template <typename T> vec2<T> vec2<T>::operator/ (const vec2<T>& rhs) const
    {
        return vec2{ _x / rhs._x, _y / rhs._y };
    }

    template <typename T> vec2<T>& vec2<T>::operator+= (const vec2<T>& rhs)
    {
        _x += rhs._x;
        _y += rhs._y;
        return *this;
    }
    template <typename T> vec2<T>& vec2<T>::operator-= (const vec2<T>& rhs)
    {
        _x -= rhs._x;
        _y -= rhs._y;
        return *this;
    }
    template <typename T> vec2<T>& vec2<T>::operator*= (const vec2<T>& rhs)
    {
        _x *= rhs._x;
        _y *= rhs._y;
        return *this;
    }
    template <typename T> vec2<T>& vec2<T>::operator/= (const vec2<T>& rhs)
    {
        _x /= rhs._x;
        _y /= rhs._y;
        return *this;
    }

    template <typename T> vec2<T> vec2<T>::operator+ (const T rhs) const
    {
        return vec2{ _x + rhs, _y + rhs };
    }
    template <typename T> vec2<T> vec2<T>::operator- (const T rhs) const
    {
        return vec2{ _x - rhs, _y - rhs };
    }
    template <typename T> vec2<T> vec2<T>::operator* (const T rhs) const
    {
        return vec2{ _x * rhs, _y * rhs };
    }
    template <typename T> vec2<T> vec2<T>::operator/ (const T rhs) const
    {
        const T inv = 1 / rhs;
        return vec2{ _x * inv, _y * inv };
    }

    template <typename T> vec2<T>& vec2<T>::operator+= (const T rhs)
    {
        _x += rhs;
        _y += rhs;
        return *this;
    }
    template <typename T> vec2<T>& vec2<T>::operator-= (const T rhs)
    {
        _x -= rhs;
        _y -= rhs;
        return *this;
    }
    template <typename T> vec2<T>& vec2<T>::operator*= (const T rhs)
    {
        _x *= rhs;
        _y *= rhs;
        return *this;
    }
    template <typename T> vec2<T>& vec2<T>::operator/= (const T rhs)
    {
        const T inv = 1 / rhs;
        _x *= inv;
        _y *= inv;
        return *this;
    }

    template <typename T> vec2<T> operator+(const T scalar, const vec2<T>& rhs)
    {
        return rhs + scalar;
    }
    template <typename T> vec2<T> operator*(const T scalar, const vec2<T>& rhs)
    {
        return rhs * scalar;
    }
    template <typename T> vec2<T> operator/(const T scalar, const vec2<T>& rhs)
    {
        return vec2<T>{ scalar / rhs.x, scalar / rhs.y };
    }
    #pragma endregion
}
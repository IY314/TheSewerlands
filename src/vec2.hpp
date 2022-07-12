#pragma once

namespace util
{
    template<typename T>
    struct Vec2
    {
        T x, y;

        constexpr Vec2(T x, T y) noexcept : x(x), y(y) {}
        constexpr Vec2(const Vec2<T> &o) noexcept = default;
        ~Vec2() noexcept = default;

        constexpr Vec2 &operator=(const Vec2<T> &o) noexcept = default;

        constexpr Vec2 operator+(const Vec2<T> &o) const noexcept
        {
            return {x + o.x, y + o.y};
        }
    };
}  // namespace util

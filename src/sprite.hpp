#pragma once

#include <string>

#include <SDL.h>

#include "vec2.hpp"

namespace swr
{
    class Spritesheet
    {
        SDL_Surface *m_surf;
        util::Vec2<int> m_size;

    public:
        Spritesheet(const std::string &filename,
                    const util::Vec2<int> &size) noexcept(false);
        Spritesheet(const Spritesheet &o) noexcept = default;
        ~Spritesheet() noexcept;

        void operator()(SDL_Surface *dst,
                        SDL_Rect dstrect,
                        const util::Vec2<int> &pos) const noexcept;
    };
}  // namespace swr

#include "sprite.hpp"

#include <SDL_image.h>

SDL_Surface *loadTexture(const std::string &filename) noexcept(false)
{
    SDL_Surface *texture = IMG_Load(filename.c_str());
    if (!texture)
    {
        texture = IMG_Load("./unknown.png");
        if (!texture)
        {
            throw std::runtime_error("Failed to load unknown.png");
        }
    }
    return texture;
}

namespace swr
{
    Spritesheet::Spritesheet(const std::string &filename,
                             const util::Vec2<int> &size) noexcept(false)
        : m_surf(loadTexture(filename)),
          m_size(size)
    {
    }

    Spritesheet::~Spritesheet() noexcept { SDL_FreeSurface(m_surf); }

    void Spritesheet::operator()(SDL_Surface *dst,
                                 SDL_Rect dstrect,
                                 const util::Vec2<int> &pos) const noexcept
    {
        SDL_Rect clip = {pos.x, pos.y, m_size.x, m_size.y};
        SDL_BlitSurface(m_surf, &clip, dst, &dstrect);
    }
}  // namespace swr

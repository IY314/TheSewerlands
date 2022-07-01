#include "object.hpp"

#include <SDL_image.h>

namespace swr
{
    RoomObject::RoomObject(const std::string &name,
                           const util::Vec2<int> &pos,
                           const util::Vec2<int> &size,
                           SDL_Surface *surf) noexcept
        : m_name(name),
          m_pos(pos),
          m_size(size)
    {
        SDL_BlitSurface(surf, NULL, m_surf, NULL);
    }

    RoomObject::~RoomObject() noexcept { SDL_FreeSurface(m_surf); }

    // NOTE: this function is a no-op and will not be called
    void RoomObject::update() noexcept {}

    void RoomObject::render(SDL_Surface *winsurf) const noexcept
    {
        SDL_Rect clip{m_pos.x, m_pos.y, m_size.x, m_size.y};
        SDL_BlitSurface(m_surf, NULL, winsurf, &clip);
    }

    Chest::Chest(const util::Vec2<int> &pos,
                 const util::Vec2<int>
                     &size /* , const std::vector<Item> & items */) noexcept
        : RoomObject("Chest", pos, size, IMG_Load("chest.png")),
          /* m_items(items), */
          m_open(false)
    {
    }

    Chest::~Chest() noexcept { RoomObject::~RoomObject(); }

    void Chest::update() noexcept
    {
        // TODO: update chest
    }

    void Chest::render(SDL_Surface *winsurf) const noexcept
    {
        // TODO: render chest
    }
}  // namespace swr

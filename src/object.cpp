#include "object.hpp"

#include <SDL_image.h>

namespace swr
{
    RoomObject::RoomObject(SDL_Renderer *rend,
                           const std::string &name,
                           const std::string &path,
                           const util::Vec2<int> &pos,
                           const util::Vec2<int> &size) noexcept
        : m_name(name),
          m_pos(pos),
          m_size(size),
          m_tex(IMG_LoadTexture(rend, path.c_str()))
    {
    }

    RoomObject::~RoomObject() noexcept { SDL_DestroyTexture(m_tex); }

    // NOTE: this function is a no-op and will not be called
    void RoomObject::update() noexcept {}

    void RoomObject::render(SDL_Renderer *rend) const noexcept
    {
        SDL_Rect clip{m_pos.x, m_pos.y, m_size.x, m_size.y};
        SDL_RenderCopy(rend, m_tex, NULL, &clip);
    }

    Chest::Chest(SDL_Renderer *rend,
                 const util::Vec2<int> &pos,
                 const util::Vec2<int>
                     &size /* , const std::vector<Item> & items */) noexcept
        : RoomObject(rend, "Chest", "chest.png", pos, size),
          /* m_items(items), */
          m_open(false)
    {
    }

    Chest::~Chest() noexcept { RoomObject::~RoomObject(); }

    void Chest::update() noexcept
    {
        // TODO: update chest
    }

    void Chest::render(SDL_Renderer *rend) const noexcept
    {
        // TODO: render chest
    }
}  // namespace swr

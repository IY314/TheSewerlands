#include "room.hpp"

#include <SDL_image.h>

namespace swr
{
    Room::Room(SDL_Renderer *rend,
               const std::string &name,
               const std::string &bgpath,
               const util::Vec2<int> &pos,
               const std::vector<Room> &neighbors,
               const util::Vec2<int> &size) noexcept
        : m_name(name),
          m_pos(pos),
          m_size(size),
          m_bgtex(IMG_LoadTexture(rend, bgpath.c_str())),
          m_neighbors(neighbors)
    {
    }

    Room::~Room() noexcept { SDL_DestroyTexture(m_bgtex); }

    void Room::update() noexcept
    {
        // TODO: update room
        for (auto &room : m_neighbors) room.update();
        for (auto &object : m_objects) object.update();
    }

    void Room::render(SDL_Renderer *rend) const noexcept
    {
        SDL_Rect clip{m_pos.x, m_pos.y, m_size.x * 5, m_size.y * 5};
        SDL_RenderCopy(rend, m_bgtex, NULL, &clip);

        for (const auto &room : m_neighbors) room.render(rend);
        for (const auto &object : m_objects) object.render(rend);
    }
}  // namespace swr

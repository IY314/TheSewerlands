#include "room.hpp"

#include <SDL_image.h>

namespace swr
{
    Room::Room(const std::string &name,
               const std::string &bgpath,
               const util::Vec2<int> &pos,
               const std::vector<Room> &neighbors,
               const util::Vec2<int> &size) noexcept
        : m_name(name),
          m_pos(pos),
          m_size(size),
          m_neighbors(neighbors)
    {
        m_bgsurf = IMG_Load(bgpath.c_str());
    }

    Room::~Room() noexcept { SDL_FreeSurface(m_bgsurf); }

    void Room::update() noexcept
    {
        // TODO: update room
        for (auto &room : m_neighbors) room.update();
        for (auto &object : m_objects) object.update();
    }

    void Room::render(SDL_Surface *winsurf) const noexcept
    {
        SDL_Rect clip{m_pos.x, m_pos.y, m_size.x, m_size.y};
        SDL_BlitSurface(m_bgsurf, NULL, winsurf, &clip);

        for (const auto &room : m_neighbors) room.render(winsurf);
        for (const auto &object : m_objects) object.render(winsurf);
    }
}  // namespace swr

#pragma once

#include "object.hpp"

namespace swr
{
    class Room
    {
        std::string m_name;
        util::Vec2<int> m_pos, m_size;

        std::vector<RoomObject> m_objects;
        SDL_Texture *m_bgtex;

        std::vector<Room> m_neighbors;

    public:
        Room(SDL_Renderer *rend,
             const std::string &name,
             const std::string &bgpath,
             const util::Vec2<int> &pos,
             const std::vector<Room> &neighbors = {},
             const util::Vec2<int> &size = {128, 128}) noexcept;
        ~Room() noexcept;

        void update() noexcept;

        void render(SDL_Renderer *rend) const noexcept;
    };
}  // namespace swr

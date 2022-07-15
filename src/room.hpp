#pragma once

#include <unordered_map>

#include "object.hpp"

namespace swr
{
    class Room
    {
    public:
        enum struct Facing
        {
            N,
            S,
            E,
            W
        };

        Room(SDL_Renderer *rend,
             const std::string &name,
             const std::string &bgpath,
             const util::Vec2<int> &pos,
             const util::Vec2<int> &size = {128, 128}) noexcept;
        ~Room() noexcept;

        void update() noexcept;

        void render(SDL_Renderer *rend) const noexcept;

        void add_neighbor(Facing facing, Room &room) noexcept;

    private:
        std::string m_name;
        util::Vec2<int> m_pos, m_size;

        std::vector<RoomObject> m_objects;
        SDL_Texture *m_bgtex;

        std::unordered_map<Facing, Room &> m_neighbors;
    };
}  // namespace swr

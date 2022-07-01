#pragma once

#include <vector>

#include "sprite.hpp"

namespace swr
{
    class RoomObject
    {
        std::string m_name;
        util::Vec2<int> m_pos, m_size;
        SDL_Surface *m_surf;

    public:
        RoomObject(const std::string &name,
                   const util::Vec2<int> &pos,
                   const util::Vec2<int> &size,
                   SDL_Surface *surf) noexcept;
        virtual ~RoomObject() noexcept;

        virtual void update() noexcept;

        virtual void render(SDL_Surface *winsurf) const noexcept;
    };

    class Chest : public RoomObject
    {
        // std::vector<Item> m_items;
        bool m_open;

    public:
        Chest(const util::Vec2<int> &pos,
              const util::Vec2<int>
                  &size /* , const std::vector<Item> & items */) noexcept;
        ~Chest() noexcept override;

        void update() noexcept override;

        void render(SDL_Surface *winsurf) const noexcept override;
    };
}  // namespace swr

#pragma once

#include "object.hpp"

namespace swr
{
    class Room
    {
    public:
        Room(const std::string &name,
             const std::string &bgpath,
             const sf::Vector2i &size = {128, 128}) noexcept;
        ~Room() = default;

        void update() noexcept;

        void render(sf::RenderWindow &window) const noexcept;

    private:
        std::string m_name;
        sf::Vector2i m_size;

        std::vector<RoomObject> m_objects;
        sf::Sprite m_background;
    };
}  // namespace swr

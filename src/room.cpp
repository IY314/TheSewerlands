#include "room.hpp"

namespace swr
{
    Room::Room(const std::string &name, const sf::Vector2i &size) noexcept
        : m_name(name),
          m_size(size)
    {
    }

    void Room::update() noexcept
    {
        // TODO: update room

        for (auto &object : m_objects) object.update();
    }

    void Room::render(sf::RenderWindow &window) const noexcept
    {
        // TODO: render room

        for (const auto &object : m_objects) object.render(window);
    }
}  // namespace swr

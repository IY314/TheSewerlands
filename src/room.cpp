#include "room.hpp"
#include "sprite.hpp"

namespace swr
{
    Room::Room(const std::string &name,
               const std::string &bgpath,
               const std::vector<Room> &neighbors,
               const sf::Vector2i &size) noexcept
        : m_name(name),
          m_size(size),
          m_background(bgpath, {0, 0}, size),
          m_neighbors(neighbors)
    {
        m_background->setScale({5, 5});
    }

    void Room::update() noexcept
    {
        // TODO: update room
        for (auto &room : m_neighbors) room.update();
        for (auto &object : m_objects) object.update();
    }

    void Room::render(sf::RenderWindow &window) const noexcept
    {
        window.draw(*m_background);

        for (const auto &room : m_neighbors) room.render(window);
        for (const auto &object : m_objects) object.render(window);
    }
}  // namespace swr

#include "room.hpp"
#include "sprite.hpp"

namespace swr
{
    Room::Room(const std::string &name,
               const std::string &bgpath,
               const sf::Vector2i &size) noexcept
        : m_name(name),
          m_size(size),
          m_background(getSprite(bgpath))
    {
        m_background.setScale({500, 500});
    }

    void Room::update() noexcept
    {
        // TODO: update room

        for (auto &object : m_objects) object.update();
    }

    void Room::render(sf::RenderWindow &window) const noexcept
    {
        window.draw(m_background);

        for (const auto &object : m_objects) object.render(window);
    }
}  // namespace swr

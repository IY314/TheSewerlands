#include "object.hpp"

namespace swr
{
    RoomObject::RoomObject(const std::string & name,
                           const sf::Vector2i & roomPos,
                           const sf::Sprite & sprite) noexcept
        : m_name(name),
          m_roomPos(roomPos),
          m_sprite(sprite)
    {
    }

    void RoomObject::render(sf::RenderWindow & window) const noexcept
    {
        window.draw(m_sprite);
    }

    Chest::Chest(const sf::Vector2i &
                     roomPos /* , const std::vector<Item> & items */) noexcept
        : RoomObject("Chest", roomPos, getSprite("/chest.png")),
          /* m_items(items), */
          m_open(false)
    {
    }

    void Chest::update() noexcept
    {
        // TODO: update chest
    }

    void Chest::render(sf::RenderWindow & window) const noexcept
    {
        // TODO: render chest
    }
}  // namespace swr

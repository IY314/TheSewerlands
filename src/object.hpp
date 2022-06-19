#pragma once

#include <vector>

#include "sprite.hpp"

namespace swr
{
    class RoomObject
    {
    public:
        RoomObject(const std::string & name,
                   const sf::Vector2i & roomPos,
                   const sf::Sprite & sprite);
        ~RoomObject() = default;

        virtual void update() noexcept = 0;

        virtual void render(sf::RenderWindow & window) const noexcept;

    private:
        std::string m_name;
        sf::Vector2i m_roomPos;
        sf::Sprite m_sprite;
    };

    class Chest : public RoomObject
    {
    public:
        Chest(const sf::Vector2i &
                  roomPos /* , const std::vector<Item> & items */);
        ~Chest() = default;

        void update() noexcept override;

        void render(sf::RenderWindow & window) const noexcept override;

    private:
        // std::vector<Item> m_items;
        bool m_open;
    };
}  // namespace swr

#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace swr
{
    class Spritesheet
    {
    public:
        Spritesheet(const std::string &filename,
                    const sf::Vector2i &size = {16, 16}) noexcept(false);
        ~Spritesheet() = default;

        sf::Sprite operator()(const sf::Vector2i &coords,
                              const sf::Vector2i &size = {1, 1}) const noexcept;

    private:
        sf::Texture m_texture;
        sf::Vector2i m_size;
    };

    class Sprite
    {
    public:
        Sprite(const std::string &filename,
               const sf::Vector2i &coords = {0, 0},
               const sf::Vector2i &size = {16, 16}) noexcept(false);

        const sf::Sprite &operator*() const noexcept;

        sf::Sprite *operator->() noexcept;

    private:
        sf::Vector2i m_coords;
        sf::Vector2i m_size;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
    };
}  // namespace swr

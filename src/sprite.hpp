#pragma once

#include <string>

#include <SFML/Graphics.hpp>

namespace swr
{
    class Spritesheet
    {
    public:
        Spritesheet(const std::string & filename,
                    const sf::Vector2i & size = {16, 16}) noexcept(false);
        ~Spritesheet() = default;

        sf::Sprite operator()(const sf::Vector2i & coords,
                              const sf::Vector2i & size = {1,
                                                           1}) const noexcept;

    private:
        sf::Texture m_texture;
        sf::Vector2i m_size;
    };

    sf::Sprite getSprite(const std::string & filename,
                         const sf::Vector2i & coords = {0, 0},
                         const sf::Vector2i & size = {16, 16}) noexcept(false);
}  // namespace swr

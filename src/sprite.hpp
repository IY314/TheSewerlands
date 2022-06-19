#pragma once

#include <string>

#include <SFML/Graphics.hpp>

namespace swr
{
    class Spritesheet
    {
    public:
        Spritesheet(const std::string & filename,
                    const sf::Vector2i & size = {16, 16});
        ~Spritesheet() = default;

        sf::Sprite operator()(const sf::Vector2i & coords,
                              const sf::Vector2i & size = {1, 1}) const;

    private:
        sf::Texture m_texture;
        sf::Vector2i m_size;
    };

    sf::Sprite getSprite(const std::string & filename,
                         const sf::Vector2i & coords,
                         const sf::Vector2i & size = {16, 16});
}  // namespace swr

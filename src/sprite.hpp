#pragma once

#include <string>

#include <SFML/Graphics.hpp>

namespace swr
{
    class Spritesheet
    {
    public:
        Spritesheet(const std::string & filename, const sf::Vector2i & size);
        sf::Sprite operator()(const sf::Vector2i & coords,
                              const sf::Vector2i & size = {1, 1}) const;

    private:
        sf::Texture m_texture;
        sf::Vector2i m_size;
    };
}  // namespace swr

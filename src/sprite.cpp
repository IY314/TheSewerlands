#include "sprite.hpp"

namespace swr
{
    Spritesheet::Spritesheet(const std::string & filename,
                             const sf::Vector2i & size)
        : m_size(size)
    {
        if (!m_texture.loadFromFile(filename))
        {
            if (!m_texture.loadFromFile("data/unknown.png"))
            {
                throw std::runtime_error("Failed to load unknown.png");
            }
        }
    }

    sf::Sprite Spritesheet::operator()(const sf::Vector2i & coords) const
    {
        sf::Sprite sprite;
        sprite.setTexture(m_texture);
        sprite.setTextureRect(
            {{coords.x * m_size.x, coords.y * m_size.y}, m_size});
        return sprite;
    }
}  // namespace swr

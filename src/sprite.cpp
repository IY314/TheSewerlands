#include "sprite.hpp"

sf::Vector2i operator*(const sf::Vector2i & a, const sf::Vector2i & b)
{
    return {a.x * b.x, a.y * b.y};
}

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

    sf::Sprite Spritesheet::operator()(const sf::Vector2i & coords,
                                       const sf::Vector2i & size) const
    {
        sf::Sprite sprite;
        sprite.setTexture(m_texture);
        sprite.setTextureRect({coords * m_size, m_size * size});
        return sprite;
    }
}  // namespace swr

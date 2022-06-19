#include "sprite.hpp"

sf::Vector2i operator*(const sf::Vector2i & a, const sf::Vector2i & b)
{
    return {a.x * b.x, a.y * b.y};
}

sf::Texture loadTexture(const std::string & filename)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
    {
        if (!texture.loadFromFile("data/unknown.png"))
        {
            throw std::runtime_error("Failed to load unknown.png");
        }
    }
    return texture;
}

namespace swr
{
    Spritesheet::Spritesheet(const std::string & filename,
                             const sf::Vector2i & size)
        : m_size(size),
          m_texture(loadTexture(filename))
    {
    }

    sf::Sprite Spritesheet::operator()(const sf::Vector2i & coords,
                                       const sf::Vector2i & size) const
    {
        sf::Sprite sprite;
        sprite.setTexture(m_texture);
        sprite.setTextureRect({coords * m_size, m_size * size});
        return sprite;
    }

    sf::Sprite getSprite(const std::string & filename,
                         const sf::Vector2i & coords,
                         const sf::Vector2i & size)
    {
        const sf::Texture texture = loadTexture(filename);
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setTextureRect({coords, size});
        return sprite;
    }
}  // namespace swr

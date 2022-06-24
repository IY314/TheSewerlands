#include "sprite.hpp"

#include "SFML/Graphics/Sprite.hpp"
#include "resource-path.hpp"

std::string getPath(const std::string &filename) noexcept
{
    return !filename.empty() && filename[0] == '/'
               ? resourcePath() + filename.substr(1)
               : filename;
}

sf::Vector2i operator*(const sf::Vector2i &a, const sf::Vector2i &b) noexcept
{
    return {a.x * b.x, a.y * b.y};
}

sf::Texture loadTexture(const std::string &filename) noexcept(false)
{
    sf::Texture texture;
    if (!texture.loadFromFile(getPath(filename)))
    {
        if (!texture.loadFromFile(getPath("/unknown.png")))
        {
            throw std::runtime_error("Failed to load unknown.png");
        }
    }
    return texture;
}

namespace swr
{
    Spritesheet::Spritesheet(const std::string &filename,
                             const sf::Vector2i &size) noexcept(false)
        : m_texture(loadTexture(filename)),
          m_size(size)
    {
    }

    sf::Sprite Spritesheet::operator()(const sf::Vector2i &coords,
                                       const sf::Vector2i &size) const noexcept
    {
        sf::Sprite sprite;
        sprite.setTexture(m_texture);
        sprite.setTextureRect({coords * m_size, m_size * size});
        return sprite;
    }

    Sprite::Sprite(const std::string &filename,
                   const sf::Vector2i &coords,
                   const sf::Vector2i &size) noexcept(false)
        : m_coords(coords),
          m_size(size),
          m_texture(loadTexture(filename))
    {
        m_sprite.setTexture(m_texture);
        m_sprite.setTextureRect({coords * m_size, m_size * size});
    }

    const sf::Sprite &Sprite::operator*() const noexcept { return m_sprite; }

    sf::Sprite *Sprite::operator->() noexcept { return &m_sprite; }
}  // namespace swr

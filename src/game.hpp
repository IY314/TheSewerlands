#pragma once

#include "sprite.hpp"

namespace swr
{
    class Game
    {
    public:
        Game() noexcept;
        ~Game() = default;

        void run() noexcept;

    private:
        void handleEvents() noexcept;
        void update() noexcept;
        void render() noexcept;

        sf::RenderWindow m_window;
        Spritesheet m_spritesheet;
    };
}  // namespace swr

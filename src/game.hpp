#pragma once

#include "sprite.hpp"

namespace swr
{
    class Game
    {
    public:
        Game();
        ~Game() = default;

        void run();

    private:
        void handleEvents();
        void update();
        void render();

        sf::RenderWindow m_window;
        Spritesheet m_spritesheet;
    };
}  // namespace swr

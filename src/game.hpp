#pragma once

#include "room.hpp"

namespace swr
{
    class Game
    {
    public:
        Game() noexcept;
        ~Game() noexcept;

        void run() noexcept;

    private:
        void handleEvents() noexcept;
        void update() noexcept;
        void render() noexcept;

        bool m_running;

        SDL_Window *m_win;
        SDL_Surface *m_winsurf;
        SDL_Event m_event;
        Room m_root;
    };
}  // namespace swr

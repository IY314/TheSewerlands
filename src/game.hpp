#pragma once

#include <memory>

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
        SDL_Renderer *m_rend;
        SDL_Rect m_viewport;
        SDL_Event m_event;
        std::unique_ptr<Room> m_root;
    };
}  // namespace swr

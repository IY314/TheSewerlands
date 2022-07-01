#include "game.hpp"

#include <iostream>

void printErrAndQuit(const std::string &prefix) noexcept
{
    std::cerr << prefix << ": " << SDL_GetError() << '\n';
    std::exit(1);
}

namespace swr
{
    Game::Game() noexcept : m_root("Chest Room", "chestroom.png", {0, 0})
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            printErrAndQuit("Unable to start SDL");

        m_win = SDL_CreateWindow("TheSewerlands",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 800,
                                 600,
                                 0);

        if (!m_win) printErrAndQuit("Unable to create window");

        m_winsurf = SDL_GetWindowSurface(m_win);

        if (!m_winsurf) printErrAndQuit("Unable to get surface from window");
    }

    Game::~Game() noexcept
    {
        SDL_FreeSurface(m_winsurf);
        SDL_DestroyWindow(m_win);
        SDL_Quit();
    }

    void Game::run() noexcept
    {
        m_running = true;

        while (m_running)
        {
            handleEvents();
            update();
            render();
        }
    }

    void Game::handleEvents() noexcept
    {
        SDL_Event e;

        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT: m_running = false; break;
            // TODO: handle key input
            // TODO: handle other events
            default: break;
            }
        }
    }

    void Game::update() noexcept { m_root.update(); }

    void Game::render() noexcept
    {
        SDL_FillRect(m_winsurf, NULL, SDL_MapRGB(m_winsurf->format, 0, 0, 0));

        m_root.render(m_winsurf);

        SDL_UpdateWindowSurface(m_win);
    }
}  // namespace swr

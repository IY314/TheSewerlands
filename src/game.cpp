#include "game.hpp"

#include <iostream>

#include <SDL_image.h>

void printErrAndQuit(const std::string &prefix, bool img = false) noexcept
{
    std::cerr << prefix << ": " << (img ? IMG_GetError() : SDL_GetError())
              << '\n';
    std::exit(1);
}

namespace swr
{
    Game::Game() noexcept
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            printErrAndQuit("Unable to start SDL");
        if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
            printErrAndQuit("Unable to start SDL_image", true);

        m_win = SDL_CreateWindow("TheSewerlands",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 800,
                                 600,
                                 0);

        if (!m_win) printErrAndQuit("Unable to create window");

        m_rend = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED);

        if (!m_rend) printErrAndQuit("Unable to create renderer");

        m_root = std::make_unique<Room>(m_rend,
                                        "Chest Room",
                                        "chestroom.png",
                                        util::Vec2{0, 0});

        m_viewport = {0, 0, 800, 600};
    }

    Game::~Game() noexcept
    {
        SDL_DestroyRenderer(m_rend);
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
            // TODO: handle other events
            default: break;
            }

            const Uint8 *state = SDL_GetKeyboardState(nullptr);

            if (state[SDL_SCANCODE_W]) m_viewport.y += 20;
            if (state[SDL_SCANCODE_A]) m_viewport.x += 20;
            if (state[SDL_SCANCODE_S]) m_viewport.y -= 20;
            if (state[SDL_SCANCODE_D]) m_viewport.x -= 20;
        }
    }

    void Game::update() noexcept { m_root->update(); }

    void Game::render() noexcept
    {
        SDL_RenderClear(m_rend);

        m_root->render(m_rend);

        SDL_RenderSetViewport(m_rend, &m_viewport);
        SDL_RenderPresent(m_rend);
    }
}  // namespace swr

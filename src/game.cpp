#include "game.hpp"

#include "resource-path.hpp"

namespace swr
{
    Game::Game()
        : m_window(sf::VideoMode({800, 600}), "TheSewerlands"),
          m_spritesheet(resourcePath() + "spritesheet.png")
    {
    }

    void Game::run()
    {
        while (m_window.isOpen())
        {
            handleEvents();
            update();
            render();
        }
    }

    void Game::handleEvents()
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed: m_window.close(); break;
                // TODO: handle key input
                // TODO: handle other events
                default: break;
            }
        }
    }

    void Game::update()
    {
        // TODO: update the game
    }

    void Game::render()
    {
        m_window.clear(sf::Color::Green);
        // TODO: render the game
        m_window.display();
    }
}  // namespace swr
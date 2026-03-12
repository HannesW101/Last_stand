// ===================================================================
// Includes
// ===================================================================

#include "textures/texture_manager.h"
#include "menus/menu_manager.h"

#include <SFML/Graphics.hpp>

// ===================================================================
// Main
// ===================================================================

// ===================================================================
int main() {
    // Initialize the texture manager which loads all assets
    bool const smooth_textures = false;
    Texture_manager::get_instance().init(smooth_textures);

    // Configure context settings
    sf::ContextSettings ctx_settings{};
    ctx_settings.antiAliasingLevel = 8u;

    // Make render window
    sf::RenderWindow window(
        sf::VideoMode::getFullscreenModes()[0u], // Default to highest resolution
        "Last Stand",
        sf::Style::Default,
        sf::State::Fullscreen,
        ctx_settings
        );

    // Initialize the menu manager which decides which menu
    // to pass draw and event commands to
    Menu_manager::get_instance(window).init();

    // Set max frame rate to monitors refresh rate
    window.setVerticalSyncEnabled(true);

    // Create clock for animations
    sf::Clock anim_clock{};

    // Main game loop
    while (window.isOpen()) {
        // Event loop
        while (std::optional<sf::Event> const event = window.pollEvent()) {

            // Check for events
            Menu_manager::get_instance(window).handle_events(event);
        }

        // Clear window before drawing
        window.clear(sf::Color::Black);

        // Handle any animations
        float const dt = anim_clock.restart().asSeconds();
        Menu_manager::get_instance(window).handle_animations(dt);

        // Draw
        Menu_manager::get_instance(window).draw();

        // Display drawn items
        window.display();
    }

    return 0;
}
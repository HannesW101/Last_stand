// ===================================================================
// Includes
// ===================================================================

#include "menus/main_menu.h"
#include "textures/texture_manager.h"
#include "fonts/font_manager.h"
#include "colors/colors.h"
#include "utils/logger.h"

// ===================================================================
// Class Main_menu
// ===================================================================

// ===================================================================
Main_menu::Main_menu(sf::RenderWindow& window)
    : Menu(window)
    , _background(Texture_manager::get_instance().get_texture(Texture_id::BACKGROUND__MAIN_MENU).texture)
    , _title(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _exit_btn(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _single_player_btn(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _multi_player_btn(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _profile_btn(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _settings_btn(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    {

    // Set the titles properties
    _title.setString("LAST STAND");
    _title.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.20f));
    _title.setFillColor(sf::Color::White);
    _title.setOutlineColor(sf::Color::Black);
    _title.setOutlineThickness(_title.getCharacterSize() * 0.050f);

    // Set the exit button properties
    _exit_btn.setString("X");
    _exit_btn.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _exit_btn.setOutlineColor(sf::Color::Black);
    _exit_btn.setOutlineThickness(_exit_btn.getCharacterSize() * 0.050f);

    // Set the singleplayer button properties
    _single_player_btn.setString("SINGLEPLAYER");
    _single_player_btn.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _single_player_btn.setOutlineColor(sf::Color::Black);
    _single_player_btn.setOutlineThickness(_single_player_btn.getCharacterSize() * 0.050f);

    // Set the multiplayer button properties
    _multi_player_btn.setString("MULTIPLAYER");
    _multi_player_btn.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _multi_player_btn.setOutlineColor(sf::Color::Black);
    _multi_player_btn.setOutlineThickness(_multi_player_btn.getCharacterSize() * 0.050f);

    // Set the profile button properties
    _profile_btn.setString("PROFILE");
    _profile_btn.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _profile_btn.setOutlineColor(sf::Color::Black);
    _profile_btn.setOutlineThickness(_profile_btn.getCharacterSize() * 0.050f);

    // Set the settings button properties
    _settings_btn.setString("SETTINGS");
    _settings_btn.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _settings_btn.setOutlineColor(sf::Color::Black);
    _settings_btn.setOutlineThickness(_settings_btn.getCharacterSize() * 0.050f);
}

// ===================================================================
void Main_menu::draw() {

    // Always draw static background
    _draw_background();

    // Always draw static title
    _draw_title();

    // Always draw the exit button, will check if its hovered
    _draw_exit_btn();

    // Always draw the singleplayer button, will check if its hovered
    _draw_single_player_btn();

    // Always draw the multiplayer button, will check if its hovered
    _draw_multi_player_btn();

    // Always draw the profile button, will check if its hovered
    _draw_profile_btn();

    // Always draw the settings button, will check if its hovered
    _draw_settings_btn();

    // Finally check if something was hovered and
    // we need to update the mouse accordingly
    if (_something_is_hovered) {

        // Set mouse cursor
        _window.setMouseCursor(_cursor_hand);

        // Reset the hovered flag so that it can maybe be populated next frame
        _something_is_hovered = false;
    } else {

        // Nothing was hovered

        // Set mouse cursor
        _window.setMouseCursor(_cursor_arrow);
    }
}

// ===================================================================
void Main_menu::handle_events(std::optional<sf::Event> const& event) {

    // Early exit if there was no event
    if (!event.has_value()) { return; }

    // Check for mouse released events
    if (const auto& mouse = event->getIf<sf::Event::MouseButtonReleased>()){

        // Left click events
        if (mouse->button == sf::Mouse::Button::Left) {

            // Check which object should emit its on click event, if any
                 if (_is_mouse_hovering(_exit_btn.getGlobalBounds()         )) { _on_click__exit_btn();          }
            else if (_is_mouse_hovering(_single_player_btn.getGlobalBounds())) { _on_click__single_player_btn(); }
        }
    }
}

// ===================================================================
void Main_menu::handle_animations(float const dt) {

    // No animations for this menu
    static_cast<void>(dt);
}

// ===================================================================
void Main_menu::_draw_background() {

    // Only scale the background if the window size changed
    if (_window.getSize() != _window_size) {

        // Scale the background to fill the window
        _background.setScale({
            static_cast<float>(_window.getSize().x) / _background.getLocalBounds().size.x,
            static_cast<float>(_window.getSize().y) / _background.getLocalBounds().size.y
            });

        // Set the new window size
        _window_size = _window.getSize();
    }

    // Draw the background to the window
    _window.draw(_background);
}

// ===================================================================
void Main_menu::_draw_title() {

    // Start drawing in center of window
    _title.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move the title to actually be centered
    _title.move({
        - (_title.getGlobalBounds().size.x / 2.0f),
        - (_title.getGlobalBounds().size.y / 2.0f)
        });

    // Move title up towards top of the window
    // Use a scaling factor to look the same on all resolutions
    _title.move({
           0.0f,
        - (_window.getSize().y * 0.35f)
        });

    // Draw the title to the window
    _window.draw(_title);
}

// ===================================================================
void Main_menu::_draw_exit_btn() {

    // Start drawing top right of window
    _exit_btn.setPosition({
        static_cast<float>(_window.getSize().x),
        0.0f
        });

    // Move the exit button to actually be seen top and not drawn off screen
    _exit_btn.move({
        - _exit_btn.getGlobalBounds().size.x,
        - _exit_btn.getGlobalBounds().size.y
        });

    // Move the exit button to correct position
    _exit_btn.move({
        0.0f,
        + (_window.getSize().y * 0.04f)
        });

    // Check if the mouse position is within the buttons bounds
    if (_is_mouse_hovering(_exit_btn.getGlobalBounds())) {

        // Button is hovered

        // Change to hovered color
        _exit_btn.setFillColor(COLOR_GLOOMY_DARK_GREY);

        // Tell the main drawing function that something is hovered
        _something_is_hovered = true;
    } else {

        // Button is not hovered

        // Change to not hovered color
        _exit_btn.setFillColor(sf::Color::White);
    }

    // Draw the exit button to the window
    _window.draw(_exit_btn);
}

// ===================================================================
void Main_menu::_draw_single_player_btn() {

    // Start drawing in center of window
    _single_player_btn.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move the button to actually be centered
    _single_player_btn.move({
        - (_single_player_btn.getGlobalBounds().size.x / 2.0f),
        - (_single_player_btn.getGlobalBounds().size.y / 2.0f)
        });

    // Move the button to correct position
    _single_player_btn.move({
        0.0f,
        - (_window.getSize().y * 0.10f)
        });

    // Check if the mouse position is within the buttons bounds
    if (_is_mouse_hovering(_single_player_btn.getGlobalBounds())) {

        // Button is hovered

        // Change to hovered color
        _single_player_btn.setFillColor(COLOR_GLOOMY_DARK_GREY);

        // Tell the main drawing function that something is hovered
        _something_is_hovered = true;
    } else {

        // Button is not hovered

        // Change to not hovered color
        _single_player_btn.setFillColor(sf::Color::White);
    }

    // Draw the exit button to the window
    _window.draw(_single_player_btn);
}

// ===================================================================
void Main_menu::_draw_multi_player_btn() {

    // Start drawing in center of window
    _multi_player_btn.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move the button to actually be centered
    _multi_player_btn.move({
        - (_multi_player_btn.getGlobalBounds().size.x / 2.0f),
        - (_multi_player_btn.getGlobalBounds().size.y / 2.0f)
        });

    // Move the button to correct position
    _multi_player_btn.move({
        0.0f,
        0.0f
        });

    // Check if the mouse position is within the buttons bounds
    if (_is_mouse_hovering(_multi_player_btn.getGlobalBounds())) {

        // Button is hovered

        // Change to hovered color
        _multi_player_btn.setFillColor(COLOR_GLOOMY_DARK_GREY);

        // Tell the main drawing function that something is hovered
        _something_is_hovered = true;
    } else {

        // Button is not hovered

        // Change to not hovered color
        _multi_player_btn.setFillColor(sf::Color::White);
    }

    // Draw the exit button to the window
    _window.draw(_multi_player_btn);
}

// ===================================================================
void Main_menu::_draw_profile_btn() {

    // Start drawing in center of window
    _profile_btn.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move the button to actually be centered
    _profile_btn.move({
        - (_profile_btn.getGlobalBounds().size.x / 2.0f),
        - (_profile_btn.getGlobalBounds().size.y / 2.0f)
        });

    // Move the button to correct position
    _profile_btn.move({
        0.0f,
        + (_window.getSize().y * 0.10f)
        });

    // Check if the mouse position is within the buttons bounds
    if (_is_mouse_hovering(_profile_btn.getGlobalBounds())) {

        // Button is hovered

        // Change to hovered color
        _profile_btn.setFillColor(COLOR_GLOOMY_DARK_GREY);

        // Tell the main drawing function that something is hovered
        _something_is_hovered = true;
    } else {

        // Button is not hovered

        // Change to not hovered color
        _profile_btn.setFillColor(sf::Color::White);
    }

    // Draw the exit button to the window
    _window.draw(_profile_btn);
}

// ===================================================================
void Main_menu::_draw_settings_btn() {

    // Start drawing in center of window
    _settings_btn.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move the button to actually be centered
    _settings_btn.move({
        - (_settings_btn.getGlobalBounds().size.x / 2.0f),
        - (_settings_btn.getGlobalBounds().size.y / 2.0f)
        });

    // Move the button to correct position
    _settings_btn.move({
        0.0f,
        + 2 * (_window.getSize().y * 0.10f)
        });

    // Check if the mouse position is within the buttons bounds
    if (_is_mouse_hovering(_settings_btn.getGlobalBounds())) {

        // Button is hovered

        // Change to hovered color
        _settings_btn.setFillColor(COLOR_GLOOMY_DARK_GREY);

        // Tell the main drawing function that something is hovered
        _something_is_hovered = true;
    } else {

        // Button is not hovered

        // Change to not hovered color
        _settings_btn.setFillColor(sf::Color::White);
    }

    // Draw the exit button to the window
    _window.draw(_settings_btn);
}

// ===================================================================
void Main_menu::_on_click__exit_btn() {

    // Log event
    LOG(TRACE) << "Exit button clicked";

    // Close the window
    _window.close();
}

// ===================================================================
void Main_menu::_on_click__single_player_btn() {

    // Log event
    LOG(TRACE) << "Singleplayer button clicked";

    // Pend a menu change
    _pending_menu_change = Menu_id::CHARACTER_SELECTION;
}

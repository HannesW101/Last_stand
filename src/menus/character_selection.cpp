// ===================================================================
// Includes
// ===================================================================

#include "menus/character_selection_menu.h"
#include "textures/texture_manager.h"
#include "fonts/font_manager.h"
#include "colors/colors.h"
#include "utils/logger.h"

// ===================================================================
// Class Character_selection_menu
// ===================================================================

// ===================================================================
Character_selection_menu::Character_selection_menu(sf::RenderWindow& window)
    : Menu(window)
    , _background(Texture_manager::get_instance().get_texture(Texture_id::BACKGROUND__MAIN_MENU).texture)
    , _char_preview_frame{}
    , _backstory_frame{}
    , _game_settings_frame{}
    , _exit_btn(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _back_btn(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _start_game_btn(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _char_name(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _char_backstory(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
    , _curr_char(Character_id::SIR_BLACKWOOD)
    {

    // Set the exit button properties
    _exit_btn.setString("X");
    _exit_btn.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _exit_btn.setOutlineColor(sf::Color::Black);
    _exit_btn.setOutlineThickness(_exit_btn.getCharacterSize() * 0.050f);

    // Set the back button properties
    _back_btn.setString("<");
    _back_btn.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _back_btn.setOutlineColor(sf::Color::Black);
    _back_btn.setOutlineThickness(_back_btn.getCharacterSize() * 0.050f);

    // Set the _char_preview_frame properties
    _char_preview_frame.setSize({
        static_cast<float>(_window.getSize().x * 0.50f),
        static_cast<float>(_window.getSize().y * 0.50f)
        });
    _char_preview_frame.setOutlineColor(sf::Color::Black);
    _char_preview_frame.setOutlineThickness(_window.getSize().x * 0.004f);
    _char_preview_frame.setFillColor(COLOR_GLOOMY_MIDNIGHT);

    // Set the _backstory_frame properties
    _backstory_frame.setSize({
        static_cast<float>(_window.getSize().x * 0.20f),
        static_cast<float>(_window.getSize().y * 0.70f)
        });
    _backstory_frame.setOutlineColor(sf::Color::Black);
    _backstory_frame.setOutlineThickness(_window.getSize().x * 0.004f);
    _backstory_frame.setFillColor(COLOR_GLOOMY_MIDNIGHT);

    // Set the _game_settings_frame properties
    _game_settings_frame.setSize({
        static_cast<float>(_window.getSize().x * 0.20f),
        static_cast<float>(_window.getSize().y * 0.70f)
        });
    _game_settings_frame.setOutlineColor(sf::Color::Black);
    _game_settings_frame.setOutlineThickness(_window.getSize().x * 0.004f);
    _game_settings_frame.setFillColor(COLOR_GLOOMY_MIDNIGHT);

    // Set character name properties
    _char_name.setString(""); // Empty initially, will be set correctly when drawing
    _char_name.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _char_name.setOutlineColor(sf::Color::Black);
    _char_name.setOutlineThickness(_char_name.getCharacterSize() * 0.050f);

    // Set _char_backstory properties
    _char_backstory.setString(""); // Empty initially, will be set correctly when drawing
    _char_backstory.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.03f));
    _char_backstory.setOutlineColor(sf::Color::Black);
    _char_backstory.setOutlineThickness(_char_backstory.getCharacterSize() * 0.050f);

    // Set _start_game_btn properties
    _start_game_btn.setString("START GAME");
    _start_game_btn.setCharacterSize(static_cast<unsigned int>(_window.getSize().y * 0.10f));
    _start_game_btn.setOutlineColor(sf::Color::Black);
    _start_game_btn.setOutlineThickness(_start_game_btn.getCharacterSize() * 0.050f);
}

// ===================================================================
void Character_selection_menu::draw() {

    // Draw everything, they will check what needs to be check. If they
    // should be drawn and how they should be drawn
    _draw_background();
    _draw_exit_btn();
    _draw_back_btn();
    _draw_char_preview_frame();
    _draw_char_name();
    _draw_start_game_btn();
    _draw_backstory_frame();
    _draw_game_settings_frame();
    _draw_char_backstory();

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
void Character_selection_menu::handle_events(std::optional<sf::Event> const& event) {

    // Early exit if there was no event
    if (!event.has_value()) { return; }

    // Check for mouse released events
    if (const auto& mouse = event->getIf<sf::Event::MouseButtonReleased>()){

        // Left click events
        if (mouse->button == sf::Mouse::Button::Left) {

            // Check which object should emit its on click event, if any
                 if (_is_mouse_hovering(_exit_btn.getGlobalBounds())) { _on_click__exit_btn(); }
            else if (_is_mouse_hovering(_back_btn.getGlobalBounds())) { _on_click__back_btn(); }
        }
    }
}

// ===================================================================
void Character_selection_menu::handle_animations(float const dt) {

    // No animations for this menu
    static_cast<void>(dt);
}

// ===================================================================
void Character_selection_menu::_draw_background() {

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
void Character_selection_menu::_draw_exit_btn() {

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
void Character_selection_menu::_draw_back_btn() {

    // Start drawing top left of window
    _back_btn.setPosition({
        0.0f,
        0.0f
        });

    // Move the exit button to correct position
    _back_btn.move({
        + (_window.getSize().x * 0.006f),
        - (_window.getSize().x * 0.027f)
        });

    // Check if the mouse position is within the buttons bounds
    if (_is_mouse_hovering(_back_btn.getGlobalBounds())) {

        // Button is hovered

        // Change to hovered color
        _back_btn.setFillColor(COLOR_GLOOMY_DARK_GREY);

        // Tell the main drawing function that something is hovered
        _something_is_hovered = true;
    } else {

        // Button is not hovered

        // Change to not hovered color
        _back_btn.setFillColor(sf::Color::White);
    }

    // Draw the button to the window
    _window.draw(_back_btn);
}

// ===================================================================
void Character_selection_menu::_draw_start_game_btn() {

    // Start drawing in center of window
    _start_game_btn.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move to actually be centered
    _start_game_btn.move({
        - (_start_game_btn.getGlobalBounds().size.x / 2.0f),
        - (_start_game_btn.getGlobalBounds().size.y / 2.0f)
        });

    // Move to correct position
    _start_game_btn.move({
        0.0f,
        + (_window.getSize().y * 0.35f)
        });

    // Check if the mouse position is within the buttons bounds
    if (_is_mouse_hovering(_start_game_btn.getGlobalBounds())) {

        // Button is hovered

        // Change to hovered color
        _start_game_btn.setFillColor(COLOR_GLOOMY_DARK_GREY);

        // Tell the main drawing function that something is hovered
        _something_is_hovered = true;
    } else {

        // Button is not hovered

        // Change to not hovered color
        _start_game_btn.setFillColor(sf::Color::White);
    }

    // Draw the button to the window
    _window.draw(_start_game_btn);
}

// ===================================================================
void Character_selection_menu::_draw_char_preview_frame() {

    // Only change size if the window size changed
    if (_window.getSize() != _window_size) {

        // change size
        _char_preview_frame.setSize({
            static_cast<float>(_window.getSize().x * 0.40f),
            static_cast<float>(_window.getSize().y * 0.40f)
        });

        // Set the new window size
        _window_size = _window.getSize();
    }

    // Start drawing in center of window
    _char_preview_frame.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move to actually be centered
    _char_preview_frame.move({
        - (_char_preview_frame.getGlobalBounds().size.x / 2.0f),
        - (_char_preview_frame.getGlobalBounds().size.y / 2.0f)
        });

    // Draw to the window
    _window.draw(_char_preview_frame);
}

// ===================================================================
void Character_selection_menu::_draw_backstory_frame() {

    // Only change size if the window size changed
    if (_window.getSize() != _window_size) {

        // change size
        _backstory_frame.setSize({
            static_cast<float>(_window.getSize().x * 0.40f),
            static_cast<float>(_window.getSize().y * 0.40f)
        });

        // Set the new window size
        _window_size = _window.getSize();
    }

    // Start drawing in center of window
    _backstory_frame.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move to actually be centered
    _backstory_frame.move({
        - (_backstory_frame.getGlobalBounds().size.x / 2.0f),
        - (_backstory_frame.getGlobalBounds().size.y / 2.0f)
        });

    // Move to be left side of the _char_preview_frame
    _backstory_frame.move({
        - (_window.getSize().x * 0.38f),
        0.0f
        });

    // Draw to the window
    _window.draw(_backstory_frame);
}

// ===================================================================
void Character_selection_menu::_draw_game_settings_frame() {

    // Only change size if the window size changed
    if (_window.getSize() != _window_size) {

        // change size
        _game_settings_frame.setSize({
            static_cast<float>(_window.getSize().x * 0.40f),
            static_cast<float>(_window.getSize().y * 0.40f)
        });

        // Set the new window size
        _window_size = _window.getSize();
    }

    // Start drawing in center of window
    _game_settings_frame.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move to actually be centered
    _game_settings_frame.move({
        - (_game_settings_frame.getGlobalBounds().size.x / 2.0f),
        - (_game_settings_frame.getGlobalBounds().size.y / 2.0f)
        });

    // Move to be right side of the _char_preview_frame
    _game_settings_frame.move({
        + (_window.getSize().x * 0.38f),
        0.0f
        });

    // Draw to the window
    _window.draw(_game_settings_frame);
}

// ===================================================================
void Character_selection_menu::_draw_char_name() {

    // Set the text corresponding to the current character
    _char_name.setString(to_string(_curr_char));

    // Start drawing in center of window
    _char_name.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move to actually be centered
    _char_name.move({
        - (_char_name.getGlobalBounds().size.x / 2.0f),
        - (_char_name.getGlobalBounds().size.y / 2.0f)
        });

    // Move to correct position
    _char_name.move({
        0.0f,
        - (_window.getSize().y * 0.40f)
        });

    // Draw to the window
    _window.draw(_char_name);
}

// ===================================================================
void Character_selection_menu::_draw_char_backstory() {

    // Set the text corresponding to the current character
    _char_backstory.setString(_get_char_backstory(_curr_char));

    // Start drawing in center of window
    _char_backstory.setPosition({
        static_cast<float>(_window.getSize().x) / 2.0f,
        static_cast<float>(_window.getSize().y) / 2.0f
        });

    // Move to be inside _backstory_frame
    _char_backstory.move({
        - (_window.getSize().x * 0.48f),
        - (_window.getSize().y * 0.36f)
        });

    // Draw to the window
    _window.draw(_char_backstory);
}

// ===================================================================
void Character_selection_menu::_on_click__exit_btn() {

    // Log event
    LOG(TRACE) << "Exit button clicked";

    // Close the window
    _window.close();
}

// ===================================================================
void Character_selection_menu::_on_click__back_btn() {

    // Log event
    LOG(TRACE) << "Back button clicked";

    // Pend a menu change
    _pending_menu_change = Menu_id::MAIN;
}

// ===================================================================
std::string Character_selection_menu::_get_char_backstory(Character_id const char_id) const {

    switch (char_id) {

        case Character_id::SIR_BLACKWOOD: return BACKSTORY__SIR_BLACKWOOD;

        default                         : return "UNKNOWN BACKSTORY";
    }
}

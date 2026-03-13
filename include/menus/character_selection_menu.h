#ifndef MENUS_CHARACTER_SELECTION_MENU_H
#define MENUS_CHARACTER_SELECTION_MENU_H

// ===================================================================
// Includes
// ===================================================================

#include "defs.h"
#include "menu.h"
#include "characters/defs.h"

#include <SFML/Graphics.hpp>

// ===================================================================
// Class Character_selection_menu
// ===================================================================

class Character_selection_menu final : public Menu {

public:

    // Constructor that just needs to know which window to menu to
    Character_selection_menu(sf::RenderWindow& window);

    // Default destructor
    ~Character_selection_menu() = default;

    // Draw the assets that need to be drawn to the
    // window and position them accordingly
    void draw() override;

    // Handle any events that are needed
    void handle_events(std::optional<sf::Event> const& event) override;

    // Handle any animations that are needed
    void handle_animations(float const dt) override;
private:
    // Draws the static background to the window
    void _draw_background();

    // Draw the exit button, changes color depending on whether user
    // is hovering over it or not
    void _draw_exit_btn();

    // Draw the back button, changes color depending on whether user
    // is hovering over it or not
    void _draw_back_btn();

    // Draw the back button, changes color depending on whether user
    // is hovering over it or not
    void _draw_start_game_btn();

    // Draws the static char_preview_frame to the window
    void _draw_char_preview_frame();

    // Draws the static backstory_frame to the window
    void _draw_backstory_frame();

    // Draws the static game_settings to the window
    void _draw_game_settings_frame();

    // Draws the name of the current character in the character frame to the window
    void _draw_char_name();

    // Draws the backstory of the current character in the character frame to the window
    void _draw_char_backstory();

    // The event for when the exit button it clicked
    void _on_click__exit_btn();

    // The event for when the back button it clicked
    void _on_click__back_btn();

    std::string _get_char_backstory(Character_id const char_id) const;

    sf::Sprite _background;

    sf::RectangleShape _char_preview_frame;
    sf::RectangleShape _backstory_frame;
    sf::RectangleShape _game_settings_frame;

    sf::Text _exit_btn;
    sf::Text _back_btn;
    sf::Text _start_game_btn;

    sf::Text _char_name;
    sf::Text _char_backstory;

    Character_id _curr_char;
};

#endif // MENUS_CHARACTER_SELECTION_MENU_H

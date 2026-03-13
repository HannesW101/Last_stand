#ifndef MENUS_MAIN_MENU_H
#define MENUS_MAIN_MENU_H

// ===================================================================
// Includes
// ===================================================================

#include "defs.h"
#include "menu.h"

#include <SFML/Graphics.hpp>

// ===================================================================
// Class Main_menu
// ===================================================================

class Main_menu final : public Menu {

public:

    // Constructor that just needs to know which window to draw the main menu to
    Main_menu(sf::RenderWindow& window);

    // Default destructor
    ~Main_menu() = default;

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

    // Draw the static title to the window
    void _draw_title();

    // Draw the exit button, changes color depending on whether user
    // is hovering over it or not
    void _draw_exit_btn();

    // Draw the singleplayer button, changes color depending on whether user
    // is hovering over it or not
    void _draw_single_player_btn();

    // Draw the multiplayer button, changes color depending on whether user
    // is hovering over it or not
    void _draw_multi_player_btn();

    // Draw the profile button, changes color depending on whether user
    // is hovering over it or not
    void _draw_profile_btn();

    // Draw the settings button, changes color depending on whether user
    // is hovering over it or not
    void _draw_settings_btn();

    // The event for when the exit button it clicked
    void _on_click__exit_btn();

    // The event for when the singleplayer button it clicked
    void _on_click__single_player_btn();

    sf::Sprite _background;
    sf::Text   _title;
    sf::Text   _exit_btn;
    sf::Text   _single_player_btn;
    sf::Text   _multi_player_btn;
    sf::Text   _profile_btn;
    sf::Text   _settings_btn;
};

#endif // MENUS_MAIN_MENU_H

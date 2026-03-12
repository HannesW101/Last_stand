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
    void handle_events(std::optional<sf::Event> const event) override;

    // Handle any animations that are needed
    void handle_animations(float const dt) override;
private:
    sf::Sprite _background;
    sf::Text   _title;
};

#endif // MENUS_MAIN_MENU_H

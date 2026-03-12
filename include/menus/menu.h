#ifndef MENUS_MENU_H
#define MENUS_MENU_H

// ===================================================================
// Includes
// ===================================================================

#include "defs.h"

#include <SFML/Graphics.hpp>
#include <optional>

// ===================================================================
// Class Menu
// ===================================================================

class Menu {

public:

    // Constructor that just needs to know which window to draw the menu to
    Menu(sf::RenderWindow& window)
        : _window(window)
        , _pending_menu_change(std::nullopt)
    {}

    // Default destructor
    virtual ~Menu() = default;

    // Draw the assets that need to be drawn to the
    // window and position them accordingly
    virtual void draw() = 0;

    // Handle any events that are needed
    virtual void handle_events(std::optional<sf::Event> const event) = 0;

    // Handle any animations that are needed
    virtual void handle_animations(float const dt) = 0;

    // Check if this menu has a pending menu change
    // return value is null if there is no pending change,
    // and if there is a pending change, the return value is
    // the menu that needs to be changed to
    std::optional<Menu_id> is_pending_menu_change() const { return _pending_menu_change; }

    // Clear the pending menu change, must only be called after actually changing the menu
    // when there is a pending menu change
    void clear_pending_menu_change() { _pending_menu_change.reset(); }
protected:

    sf::RenderWindow&      _window;
    std::optional<Menu_id> _pending_menu_change;
};

#endif // MENUS_MENU_H

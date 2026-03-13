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
        , _something_is_hovered(false)
        , _window_size({0u, 0u})
        , _cursor_arrow(sf::Cursor::Type::Arrow)
        , _cursor_hand(sf::Cursor::Type::Hand)
    {}

    // Default destructor
    virtual ~Menu() = default;

    // Draw the assets that need to be drawn to the
    // window and position them accordingly
    virtual void draw() = 0;

    // Handle any events that are needed
    virtual void handle_events(std::optional<sf::Event> const& event) = 0;

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

    // Check whether the mouse is currently within an objects globl bounds (hovering)
    bool _is_mouse_hovering(sf::FloatRect const& global_bounds) {

        // Get the mouse position on the current window
        sf::Vector2i const mouse_pos_pixels = sf::Mouse::getPosition(_window);

        // Map mouse pixel co-ordinates to world co-ordinates
        sf::Vector2f const mouse_pos = _window.mapPixelToCoords(mouse_pos_pixels);

        // Check whether the mouse is within our objects bounds
        return global_bounds.contains(mouse_pos);
    }

    sf::RenderWindow&      _window;
    std::optional<Menu_id> _pending_menu_change;
    bool                   _something_is_hovered;
    sf::Vector2u           _window_size;
    sf::Cursor             _cursor_arrow;
    sf::Cursor             _cursor_hand;
};

#endif // MENUS_MENU_H

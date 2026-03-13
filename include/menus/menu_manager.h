#ifndef MENUS_MANAGER_H
#define MENUS_MANAGER_H

// ===================================================================
// Includes
// ===================================================================

#include "defs.h"
#include "menu.h"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <memory>

// ===================================================================
// Class Menu_manager
// ===================================================================

class Menu_manager final {

public:

    // Get the singleton instance
    static Menu_manager& get_instance(sf::RenderWindow& window);

    // Delete copy and move
    Menu_manager           (Menu_manager const&) = delete;
    Menu_manager& operator=(Menu_manager const&) = delete;
    Menu_manager           (Menu_manager&&     ) = delete;
    Menu_manager& operator=(Menu_manager&&     ) = delete;

    // Initialize the Menu_manager by adding all needed
    // menus to the _menu_map and updating _curr_menu to
    // be the default starting menu
    void init();

    // VERY IMPORTANTLY!
    // it first asks the menu if there is a pending menu change,
    // and if there is, what menu to change to? Then it will first
    // switch to the new pending menu if needed and alert the old
    // one there is no longer a pending menu change. Then it tells the current
    // menu to draw its items to the screen and does not care how or what is drawn.
    void draw();

    // Tells the current menu to handle events
    // and does not care how it handles them or what is handled
    void handle_events(std::optional<sf::Event> const& event);

    // Tells the current menu to handle animations by passing the delta time
    // for this main game loop iterations. And does not care how it handles
    // them or what is handled
    void handle_animations(float const dt);
private:

    // Private singleton constructor that needs to know which window to pass to menus
    Menu_manager(sf::RenderWindow& window);
    // Default destructor
    ~Menu_manager() = default;

    std::unordered_map<Menu_id, std::unique_ptr<Menu>> _menu_map;
    Menu_id                                            _curr_menu;
    sf::RenderWindow&                                  _window;
};

#endif // MENUS_MANAGER_H

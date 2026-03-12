// ===================================================================
// Includes
// ===================================================================

#include "menus/menu_manager.h"
#include "utils/logger.h"

// ===================================================================
// Global overloaded operators
// ===================================================================

// ===================================================================
std::ostream& operator<<(std::ostream& os, Menu_id id) {

    switch (id) {

        case Menu_id::MAIN     : return os << "MAIN";
        case Menu_id::SETTINGS : return os << "SETTINGS";
        case Menu_id::PROFILE  : return os << "PROFILE";
        case Menu_id::PLAY     : return os << "PLAY";
        case Menu_id::COMBAT   : return os << "COMBAT";

        default                : return os << "UNKNOWN_MENU_ID";
    }
}

// ===================================================================
// Class Menu_manager
// ===================================================================

// ===================================================================
Menu_manager& Menu_manager::get_instance(sf::RenderWindow& window) {

    static Menu_manager instance(window);
    return instance;
}

// ===================================================================
void Menu_manager::init() {

    // Add all menus to the _menu_map
    //_menu_map.emplace(Menu_id::MAIN,     std::make_unique<Menu>(_window));
    //_menu_map.emplace(Menu_id::PROFILE,  std::make_unique<Menu>(_window));
    //_menu_map.emplace(Menu_id::SETTINGS, std::make_unique<Menu>(_window));
    //_menu_map.emplace(Menu_id::PLAY,     std::make_unique<Menu>(_window));
    //_menu_map.emplace(Menu_id::COMBAT,   std::make_unique<Menu>(_window));

    // Set the default starting menu
    _curr_menu = Menu_id::MAIN;
}

// ===================================================================
void Menu_manager::draw() {

    // Search the _menu_map for the current menu
    auto it = _menu_map.find(_curr_menu);

    if (it == _menu_map.cend()) {

        // Not found
        LOG(WARNING) <<
            "No menu with menu ID [" <<
            it->first <<
            "] was found. Not switching menus";

        // Early exit
        return;
    }

    // Check if current menu has a pending menu change
    auto&      curr_menu           = it->second;
    auto const pending_menu_change = curr_menu->is_pending_menu_change();

    if (!pending_menu_change) {

        // No pending menu change, so draw this menu
        curr_menu->draw();
    } else {

        // Pending menu change, so track the new menu to draw
        Menu_id const new_menu_id = pending_menu_change.value();

        // Search the _menu_map for the new menu
        it = _menu_map.find(new_menu_id);

        if (it == _menu_map.cend()) {

            // Not found
            LOG(WARNING) <<
                "No menu with menu ID [" <<
                it->first <<
                "] was found. Not switching menus";

            // Early exit
            return;
        } else {

            // New menu was found, so clear its pending change
            auto& new_menu = it->second;
            new_menu->clear_pending_menu_change();

            // Draw the new menu
            new_menu->draw();

            // Update our current menu ID variable
            _curr_menu = new_menu_id;
        }
    }
}

// ===================================================================
void Menu_manager::handle_events(std::optional<sf::Event> const event) {

    // Search the _menu_map for the current menu
    auto it = _menu_map.find(_curr_menu);

    if (it == _menu_map.cend()) {

        // Not found
        LOG(WARNING) <<
            "No menu with menu ID [" <<
            it->first <<
            "] was found. Not handling events";
    } else {

        // Simply pass the handling of events to the current menu
        auto& curr_menu = it->second;
        curr_menu->handle_events(event);
    }
}

// ===================================================================
void Menu_manager::handle_animations(float const dt) {

    // Search the _menu_map for the current menu
    auto it = _menu_map.find(_curr_menu);

    if (it == _menu_map.cend()) {

        // Not found
        LOG(WARNING) <<
            "No menu with menu ID [" <<
            it->first <<
            "] was found. Not handling animations";
    } else {

        // Simply pass the handling of animations to the current menu
        auto& curr_menu = it->second;
        curr_menu->handle_animations(dt);
    }
}

// ===================================================================
Menu_manager::Menu_manager(sf::RenderWindow& window)
    : _menu_map{}
    , _curr_menu(Menu_id::MAIN)
    , _window(window)
{}
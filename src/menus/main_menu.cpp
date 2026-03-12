// ===================================================================
// Includes
// ===================================================================

#include "menus/main_menu.h"
#include "textures/texture_manager.h"
#include "fonts/font_manager.h"

// ===================================================================
// Class Main_menu
// ===================================================================

// ===================================================================
Main_menu::Main_menu(sf::RenderWindow& window)
    : Menu(window)
    , _background(Texture_manager::get_instance().get_texture(Texture_id::BACKGROUND__MAIN_MENU).texture)
    , _title(Font_manager::get_instance().get_font(Font_id::BOLD_PIXELS))
{}

// ===================================================================
void Main_menu::draw() {

    // Scale the sprite to fill the window
    _background.setScale({
        static_cast<float>(_window.getSize().x) / _background.getLocalBounds().size.x,
        static_cast<float>(_window.getSize().y) / _background.getLocalBounds().size.y
    });

    _window.draw(_background);
}

// ===================================================================
void Main_menu::handle_events(std::optional<sf::Event> const event) {

    (void)event;
}

// ===================================================================
void Main_menu::handle_animations(float const dt) {

    (void)dt;
}

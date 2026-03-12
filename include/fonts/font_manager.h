#ifndef FONTS_MANAGER_H
#define FONTS_MANAGER_H

// ===================================================================
// Includes
// ===================================================================

#include "defs.h"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <string_view>

// ===================================================================
// Class Font_manager
// ===================================================================

class Font_manager final {

public:
    // Get the singleton instance
    static Font_manager& get_instance();

    // Delete copy and move
    Font_manager           (Font_manager const&) = delete;
    Font_manager& operator=(Font_manager const&) = delete;
    Font_manager           (Font_manager&&     ) = delete;
    Font_manager& operator=(Font_manager&&     ) = delete;

    // Initialize the Font_manager and load all assets
    // Should be called only once at startup
    void init();

    // Get reference to font for a matching font ID
    // Note this returns a reference to a font as copying fonts are expensive
    // Will give error if font ID is not found in map
    sf::Font const& get_font(Font_id const font_id) const;
private:
    // Private singleton constructor
    Font_manager();

    // Default destructor
    ~Font_manager() = default;

    // Loads a font from a file path and adds it to the font map
    void _load(Font_id const font_id, std::string_view const font_path);

    bool                                  _is_initialized;
    std::unordered_map<Font_id, sf::Font> _font_map;
};

#endif // FONTS_MANAGER_H

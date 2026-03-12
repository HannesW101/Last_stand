// ===================================================================
// Includes
// ===================================================================

#include "fonts/font_manager.h"
#include "fonts/defs.h"
#include "utils/logger.h"

// ===================================================================
// Global overloaded operators
// ===================================================================

// ===================================================================
std::ostream& operator<<(std::ostream& os, Font_id id) {

    switch (id) {

        case Font_id::DEFAULT     : return os << "DEFAULT";

        case Font_id::BOLD_PIXELS : return os << "BOLD_PIXELS";

        default                   : return os << "UNKNOWN_FONT_ID";
    }
}

// ===================================================================
// Class Font_manager
// ===================================================================

// ===================================================================
Font_manager& Font_manager::get_instance() {

    static Font_manager instance;
    return instance;
}

// ===================================================================
void Font_manager::init() {

    // Check if already initialized
    if (_is_initialized) {

        LOG(WARNING) << "Attempting to re-initialize Font_manager";
    } else {

        // Add default empty font to the map
        _font_map.emplace(Font_id::DEFAULT, sf::Font{});

        // Load fonts
        _load(Font_id::BOLD_PIXELS, FONT_PATH__BOLD_PIXELS);

        // Now initialized
        _is_initialized = true;

        // Log success
        LOG(INFO) << "Initialized Font_manager and loaded all assets successfully";
    }
}

// ===================================================================
sf::Font const& Font_manager::get_font(Font_id const font_id) const {

    // Search the map for this font ID
    auto const& it = _font_map.find(font_id);

    // Check if found
    if (it == _font_map.cend()) {

        // Not found
        LOG(WARNING) <<
            "No font with font ID [" <<
            font_id <<
            "] was found";

        // Return default empty font
        return _font_map.at(Font_id::DEFAULT);
    } else {

        // Found, so return corresponding font
        return it->second;
    }
}

// ===================================================================
Font_manager::Font_manager()
    : _is_initialized(false)
    , _font_map{}
{}

// ===================================================================
void Font_manager::_load(Font_id const font_id, std::string_view const font_path) {

    // Create font that could potentially be added to the map if
    // it can load its ttf successfully
    sf::Font f;

    if (!f.openFromFile(font_path)) {

        // Failed to load
        LOG(ERROR) << "Failed to load font [" << font_id << ']';
    } else {
        // Loaded successfully

        // Move the newly constructed font to the map
        _font_map.emplace(font_id, std::move(f));
    }
}

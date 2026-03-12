#ifndef FONTS_DEFS_H
#define FONTS_DEFS_H

// ===================================================================
// Includes
// ===================================================================

#include <string_view>

// ===================================================================
// Enums
// ===================================================================

enum class Font_id {

    DEFAULT,

    BOLD_PIXELS
}; std::ostream& operator<<(std::ostream& os, Font_id id);

// ===================================================================
// Font paths
// ===================================================================

std::string_view const FONT_PATH__BOLD_PIXELS = "assets/fonts/BoldPixels.ttf"; // Note sizes must be in multiples of 16px

#endif // FONTS_DEFS_H

// ===================================================================
// Includes
// ===================================================================

#include "textures/texture_manager.h"

#include <SFML/Graphics.hpp>

// ===================================================================
// Main
// ===================================================================

// ===================================================================
int main() {
    // Initialize the texture manager which loads all assets
    bool const smooth_textures = false;
    Texture_manager::get_instance().init(smooth_textures);

    return 0;
}
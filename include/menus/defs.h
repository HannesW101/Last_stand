#ifndef MENUS_DEFS_H
#define MENUS_DEFS_H

// ===================================================================
// Includes
// ===================================================================

#include <ostream>

// ===================================================================
// Enums
// ===================================================================

enum class Menu_id {

    MAIN,
    SETTINGS,
    PROFILE,
    SINGLE_PLAYER,
    MULTI_PLAYER,
    CHARACTER_SELECTION
}; std::ostream& operator<<(std::ostream& os, Menu_id id);

#endif // MENUS_DEFS_H

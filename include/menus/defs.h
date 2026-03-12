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
    PLAY,
    COMBAT
}; std::ostream& operator<<(std::ostream& os, Menu_id id);

#endif // MENUS_DEFS_H

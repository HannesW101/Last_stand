#ifndef TEXTURES_DEFS_H
#define TEXTURES_DEFS_H

// ===================================================================
// Includes
// ===================================================================

#include <SFML/Graphics.hpp>

#include <string_view>

// ===================================================================
// Enums
// ===================================================================

enum class Texture_id {

    // Defaults
    DEFAULT,

    // Backgrounds
    BACKGROUND__GRAVEYARD,
    BACKGROUND__DRAGON_CASTLE,
    BACKGROUND__FOREST,
    BACKGROUND__DRY_GRAVEYARD,

    // Characters
    CHARACTER__SIR_BLACKWOOD__ATTACK_1,
    CHARACTER__SIR_BLACKWOOD__ATTACK_2,
    CHARACTER__SIR_BLACKWOOD__ATTACK_3,
    CHARACTER__SIR_BLACKWOOD__DEAD,
    CHARACTER__SIR_BLACKWOOD__DEFEND,
    CHARACTER__SIR_BLACKWOOD__HURT,
    CHARACTER__SIR_BLACKWOOD__IDLE,
    CHARACTER__SIR_BLACKWOOD__JUMP,
    CHARACTER__SIR_BLACKWOOD__PROTECT,
    CHARACTER__SIR_BLACKWOOD__RUN_ATTACK,
    CHARACTER__SIR_BLACKWOOD__RUN,
    CHARACTER__SIR_BLACKWOOD__WALK
};

// ===================================================================
// Structs
// ===================================================================

struct Texture {

    sf::Texture texture;
}; std::ostream& operator<<(std::ostream& os, Texture_id id);

// ===================================================================
// Default Texture paths
// ===================================================================

std::string_view const TEXTURE_PATH__DEFAULT = "assets/defaults/Default_texture.png";

// ===================================================================
// Background Texture paths
// ===================================================================

std::string_view const TEXTURE_PATH__BACKGROUND__GRAVEYARD     = "assets/backgrounds/Battleground1/Battleground1.png";
std::string_view const TEXTURE_PATH__BACKGROUND__DRAGON_CASTLE = "assets/backgrounds/Battleground2/Battleground2.png";
std::string_view const TEXTURE_PATH__BACKGROUND__FOREST        = "assets/backgrounds/Battleground3/Battleground3.png";
std::string_view const TEXTURE_PATH__BACKGROUND__DRY_GRAVEYARD = "assets/backgrounds/Battleground4/Battleground4.png";

// ===================================================================
// Character Texture paths
// ===================================================================

std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__ATTACK_1   = "assets/characters/sir_blackwood/Attack_1.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__ATTACK_2   = "assets/characters/sir_blackwood/Attack_1.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__ATTACK_3   = "assets/characters/sir_blackwood/Attack_1.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__DEAD       = "assets/characters/sir_blackwood/Dead.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__DEFEND     = "assets/characters/sir_blackwood/Defend.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__HURT       = "assets/characters/sir_blackwood/Hurt.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__IDLE       = "assets/characters/sir_blackwood/Idle.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__JUMP       = "assets/characters/sir_blackwood/Jump.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__PROTECT    = "assets/characters/sir_blackwood/Protect.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__RUN_ATTACK = "assets/characters/sir_blackwood/Run_Attack.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__RUN        = "assets/characters/sir_blackwood/Run.png";
std::string_view const TEXTURE_PATH__CHARACTERS__SIR_BLACKWOOD__WALK       = "assets/characters/sir_blackwood/Walk.png";

#endif // TEXTURES_DEFS_H

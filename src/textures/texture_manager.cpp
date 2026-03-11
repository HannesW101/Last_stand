// ===================================================================
// Includes
// ===================================================================

#include "textures/texture_manager.h"
#include "textures/defs.h"
#include "utils/logger.h"

// ===================================================================
// Global overloaded operators
// ===================================================================

// ===================================================================
std::ostream& operator<<(std::ostream& os, Texture_id id) {

    switch (id) {

        case Texture_id::DEFAULT                              : return os << "DEFAULT";

        case Texture_id::BACKGROUND__GRAVEYARD                : return os << "BACKGROUND__GRAVEYARD";
        case Texture_id::BACKGROUND__DRAGON_CASTLE            : return os << "BACKGROUND__DRAGON_CASTLE";
        case Texture_id::BACKGROUND__FOREST                   : return os << "BACKGROUND__FOREST";
        case Texture_id::BACKGROUND__DRY_GRAVEYARD            : return os << "BACKGROUND__DRY_GRAVEYARD";

        case Texture_id::CHARACTER__SIR_BLACKWOOD__ATTACK_1   : return os << "CHARACTER__SIR_BLACKWOOD__ATTACK_1";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__ATTACK_2   : return os << "CHARACTER__SIR_BLACKWOOD__ATTACK_2";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__ATTACK_3   : return os << "CHARACTER__SIR_BLACKWOOD__ATTACK_3";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__DEAD       : return os << "CHARACTER__SIR_BLACKWOOD__DEAD";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__DEFEND     : return os << "CHARACTER__SIR_BLACKWOOD__DEFEND";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__HURT       : return os << "CHARACTER__SIR_BLACKWOOD__HURT";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__IDLE       : return os << "CHARACTER__SIR_BLACKWOOD__IDLE";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__JUMP       : return os << "CHARACTER__SIR_BLACKWOOD__JUMP";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__PROTECT    : return os << "CHARACTER__SIR_BLACKWOOD__PROTECT";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__RUN_ATTACK : return os << "CHARACTER__SIR_BLACKWOOD__RUN_ATTACK";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__RUN        : return os << "CHARACTER__SIR_BLACKWOOD__RUN";
        case Texture_id::CHARACTER__SIR_BLACKWOOD__WALK       : return os << "CHARACTER__SIR_BLACKWOOD__WALK";

        default                                               : return os << "UNKNOWN_TEXTURE_ID";
    }
}

// ===================================================================
// Class Texture_manager
// ===================================================================

// ===================================================================
Texture_manager& Texture_manager::get_instance() {

    static Texture_manager instance;
    return instance;
}

// ===================================================================
void Texture_manager::init(bool const smooth_textures) {

    // Check if they want smooth textures
    _is_smooth = smooth_textures;

    // Check if already initialized
    if (_is_initialized) {

        LOG(WARNING) << "Attempting to re-initialize Texture_manager";
    } else {

        // Load default texture
        _load(Texture_id::DEFAULT, TEXTURE_PATH__DEFAULT);

        // Load backgrounds
        _load(Texture_id::BACKGROUND__GRAVEYARD,     TEXTURE_PATH__BACKGROUND__GRAVEYARD);
        _load(Texture_id::BACKGROUND__DRAGON_CASTLE, TEXTURE_PATH__BACKGROUND__DRAGON_CASTLE);
        _load(Texture_id::BACKGROUND__FOREST,        TEXTURE_PATH__BACKGROUND__FOREST);
        _load(Texture_id::BACKGROUND__DRY_GRAVEYARD, TEXTURE_PATH__BACKGROUND__DRY_GRAVEYARD);

        // Now initialized
        _is_initialized = true;

        // Log success
        LOG(INFO) << "Initialized Texture_manager and loaded all assets successfully";
    }
}

// ===================================================================
Texture const& Texture_manager::get_texture(Texture_id const texture_id) const {

    // Search the map for this texture ID
    auto const& it = _texture_map.find(texture_id);

    // Check if found
    if (it == _texture_map.cend()) {

        // Not found
        LOG(WARNING) <<
            "No texture with texture ID [" <<
            texture_id <<
            "] was found. Returning default texture instead";

        // Return the Texture for default ID
        return _texture_map.at(Texture_id::DEFAULT);
    } else {

        // Found, so return corresponding Texture
        return it->second;
    }
}

// ===================================================================
Texture_manager::Texture_manager()
    : _is_initialized(false)
    , _is_smooth(false)
    , _texture_map{}
{}

// ===================================================================
void Texture_manager::_load(Texture_id const texture_id, std::string_view const texture_path) {

    // Create texture struct that could potentially be added to the map if
    // it can load its sf::Texture successfully
    Texture t;

    if (!t.texture.loadFromFile(texture_path)) {

        // Failed to load
        LOG(ERROR) << "Failed to load texture [" << texture_path << ']';
    } else {
        // Loaded successfully

        // Check if texture should be smooth
        t.texture.setSmooth(_is_smooth);

        // Move the newly constructed texture to the map
        _texture_map.emplace(texture_id, std::move(t));
    }
}

#ifndef TEXTURES_MANAGER_H
#define TEXTURES_MANAGER_H

// ===================================================================
// Includes
// ===================================================================

#include "defs.h"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <string_view>

// ===================================================================
// Class Texture_manager
// ===================================================================

class Texture_manager final {

public:
    // Get the singleton instance
    static Texture_manager& get_instance();

    // Delete copy and move
    Texture_manager           (Texture_manager const&) = delete;
    Texture_manager& operator=(Texture_manager const&) = delete;
    Texture_manager           (Texture_manager&&     ) = delete;
    Texture_manager& operator=(Texture_manager&&     ) = delete;

    // Initialize the Texture_manager and load all assets
    // Should be called only once at startup
    // Can also decide whether or not to smooth all textures
    void init(bool const smooth_textures);

    // Get reference to texture struct for a matching texture ID
    // Note SFML does not allow copying sf::Textures
    // Will give error and return the default texture if texture ID
    // is not found in map
    Texture const& get_texture(Texture_id const texture_id) const;
private:
    // Private singleton constructor
    Texture_manager();

    // Default destructor
    ~Texture_manager() = default;

    // Loads a texture from a file path and adds it to the texture map
    void _load(Texture_id const texture_id, std::string_view const texture_path);

    bool                                    _is_initialized;
    bool                                    _is_smooth;
    std::unordered_map<Texture_id, Texture> _texture_map;
};

#endif // TEXTURES_MANAGER_H

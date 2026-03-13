#ifndef CHARACTERS_DEFS_H
#define CHARACTERS_DEFS_H

// ===================================================================
// Includes
// ===================================================================

#include <string>
#include <string_view>

// ===================================================================
// Enums
// ===================================================================

enum class Character_id {

    SIR_BLACKWOOD
};

inline std::string to_string(Character_id const char_id) {

    switch (char_id) {

        case Character_id::SIR_BLACKWOOD: return "SIR BLACKWOOD";

        default                         : return "UNKNOWN CHARACTER";
    }
}

// ===================================================================
// Character backstories
// ===================================================================

std::string const BACKSTORY__SIR_BLACKWOOD = "Edmund Blackwood has never\nknown when to quit. Thirty years\nof war and not a single smart\nexit. Every time the sane thing\nwas to walk away, he stayed.\nEvery time staying meant\nbleeding, he bled. He built his\nwhole identity around being the\nlast man standing and never\nstopped to ask if that was\nsomething to be proud of. Now\nit's the only thing he knows how\nto be. He's too far gone for a\nnormal life. Too much blood on his\nhands for peace to sit right. The\nworld he fought to protect\nmoved on without him and he\ndoesn't fit in it anymore. So he\nfights. Because stopping is the\none thing Edmund Blackwood has\nnever figured out how to do.";

#endif // CHARACTERS_DEFS_H

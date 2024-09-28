#include "gdscript_transpiler.h"

#include "core/error/error_macros.h"
#include "core/string/char_utils.h"

#ifdef DEBUG_ENABLED
#include "servers/text_server.h"
#endif

#ifdef TOOLS_ENABLED
#include "editor/editor_settings.h"
#endif
#include <sstream>
#include <iostream>

void GDScriptTranspiler::initialize_translation_map() {
    hindi_to_english_map["जब"] = "if";
    hindi_to_english_map["और"] = "and";
    hindi_to_english_map["या"] = "or";
    // Add more Hindi keywords and their corresponding English translations here
}

GDScriptTranspiler::GDScriptTranspiler() {
    initialize_translation_map();
}

std::string GDScriptTranspiler::translate_to_english(const std::string &source_code) {
    std::istringstream input_stream(source_code);
    std::ostringstream output_stream;
    std::string word;

    // Read the input source code word by word
    while (input_stream >> word) {
        if (hindi_to_english_map.find(word) != hindi_to_english_map.end()) {
            // Replace with corresponding English keyword
            output_stream << hindi_to_english_map[word] << " ";
        } else {
            output_stream << word << " ";
        }
    }

    return output_stream.str();
}

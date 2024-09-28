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
    hindi_to_english_map["अगर"] = "if";
    hindi_to_english_map["अन्य"] = "else";
    hindi_to_english_map["लूप"] = "for";
    hindi_to_english_map["जबतक"] = "while";
    hindi_to_english_map["फंक्शन"] = "func";
    hindi_to_english_map["वापस"] = "return";
    hindi_to_english_map["कक्षा"] = "class";
    hindi_to_english_map["नया"] = "new";
    hindi_to_english_map["मुद्रित"] = "print";
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
            // If not a Hindi keyword, keep it as is
            output_stream << word << " ";
        }
    }

    return output_stream.str();
}


#ifndef GDSCRIPT_TRANSPILER_H
#define GDSCRIPT_TRANSPILER_H

#include "core/templates/hash_map.h"
#include "core/templates/hash_set.h"
#include "core/templates/list.h"
#include "core/templates/vector.h"
#include "core/variant/variant.h"

class GDScriptTranspiler {
    public:
        HashMap<StringName,StringName> translator;
}
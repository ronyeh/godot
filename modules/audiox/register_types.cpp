/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "audiox.h"

#include <stdio.h>

void initialize_audiox_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	printf("initialize_audiox_module with printf!\n");
	print_line("initialize_audiox_module with print_line");

	ClassDB::register_class<AudioX>();
}

void uninitialize_audiox_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	// Nothing to do here in this example.
}
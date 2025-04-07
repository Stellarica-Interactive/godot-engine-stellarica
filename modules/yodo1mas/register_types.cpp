#include <version_generated.gen.h>

#include "register_types.h"
#include "core/config/engine.h"
#include "ios/src/GodotYodo1Mas.h"

void initialize_yodo1mas_module(ModuleInitializationLevel p_level) {
	GDREGISTER_CLASS(GodotYodo1Mas);
	static GodotYodo1Mas *singleton = memnew(GodotYodo1Mas);
	Engine::get_singleton()->add_singleton(Engine::Singleton("GodotYodo1Mas", singleton));
}

void uninitialize_yodo1mas_module(ModuleInitializationLevel p_level) {
}

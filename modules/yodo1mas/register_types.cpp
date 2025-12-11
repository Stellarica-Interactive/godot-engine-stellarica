#include <version_generated.gen.h>

#include "register_types.h"
#include "core/config/engine.h"

#ifdef IOS_ENABLED
#include "ios/src/GodotYodo1Mas.h"
#endif

#ifdef ANDROID_ENABLED
#include "android/src/GodotYodo1Mas.h"
#endif

void initialize_yodo1mas_module(ModuleInitializationLevel p_level) {
#if defined(IOS_ENABLED) || defined(ANDROID_ENABLED)
	GDREGISTER_CLASS(GodotYodo1Mas);
	static GodotYodo1Mas *singleton = memnew(GodotYodo1Mas);
	Engine::get_singleton()->add_singleton(Engine::Singleton("GodotYodo1Mas", singleton));
#endif
}

void uninitialize_yodo1mas_module(ModuleInitializationLevel p_level) {
}

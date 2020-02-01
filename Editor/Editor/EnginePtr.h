#pragma once
#include <IEngine.h>
#include "EngineWindowInterface.h"
#include <stdint.h>

namespace Editor
{
	using Entity = uint32_t;
	struct EnginePtr {
		std::shared_ptr<Engine::IEngine> engine;
		std::shared_ptr<EngineWindowInterface> window;
	};
}
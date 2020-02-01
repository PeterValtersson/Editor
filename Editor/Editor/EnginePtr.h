#pragma once
#include <IEngine.h>
#include "EngineWindowInterface.h"

namespace Editor
{
	struct EnginePtr {
		std::shared_ptr<Engine::IEngine> engine;
		std::shared_ptr<EngineWindowInterface> window;
	};
}
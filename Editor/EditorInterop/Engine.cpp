#include "pch.h"
#include "Engine.h"

void EditorInterop::Engine::init(IntPtr hwnd, Drawing::Size resolution)
{
	try
	{
		ECSEngine::Init_Info ii;
		ii.mode = ResourceHandler::AccessMode::read_write;
		*window = std::make_shared<EngineWindow>(hwnd.ToPointer(), ECSEngine::Resolution{ uint32_t(resolution.Width), uint32_t(resolution.Height) });
		ii.sub_systems.hmi = *window;
		*engine = ECSEngine::Engine::create(ii);

		(*engine)->start(true);
	}
	catch(Utilities::Exception& e)
	{
		throw gcnew Exception(gcnew String(e.what()));
	}
}

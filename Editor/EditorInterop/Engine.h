#pragma once
#include <Engine.h>
#include "EngineWindow.h"
#include "Scene.h"
#using <System.Drawing.dll>
#include "ComponentReflection.h"

using namespace System;
using namespace System::Collections::Generic;
namespace EditorInterop
{
	public ref class Engine
	{
	public:
		Engine()
		{
			engine = new std::unique_ptr<ECSEngine::Engine>();
			window = new std::shared_ptr<EngineWindow>();
			
		}
		~Engine()
		{
			if (engine)
				delete engine;
			if (window)
				delete window;
		}
		void init(IntPtr hwnd, Drawing::Size resolution);
		Scene^ scene()
		{
			return gcnew Scene((*engine)->get_entity_components().scene_component);
		}
		EntityFactory^ entity_factory()
		{
			return gcnew EntityFactory((*engine)->get_entity_components().entity_factory);
		}
		List<ComponentReflection^>^ get_component_reflections();
	private:
		std::unique_ptr<ECSEngine::Engine>* engine;
		std::shared_ptr<EngineWindow>* window;
	};

}
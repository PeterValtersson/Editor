#pragma once
#include <Engine.h>
#include "EngineWindow.h"

using namespace System;
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
	private:
		std::unique_ptr<ECSEngine::Engine>* engine;
		std::shared_ptr<EngineWindow>* window;
	};

}
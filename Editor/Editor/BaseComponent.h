#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#include "EnginePtr.h"

namespace Editor
{

/// <summary>
/// Summary for BaseComponent
/// </summary>
	public interface class BaseComponent  {
	public:
		void Create();
	};
}
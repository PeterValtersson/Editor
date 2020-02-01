#include "ComponentControl.h"

System::Void Editor::ComponentControl::clicked( System::Object^ sender, System::EventArgs^ e )
{
	selected_callback( component );
}

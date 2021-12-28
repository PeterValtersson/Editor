#include "AddComponentDialog.h"

void Editor::AddComponentDialog::OnClick(System::Object^ sender, System::EventArgs^ e)
{
	auto btn = (Btn^)sender;
	component_list->Visible = false;
}

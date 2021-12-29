#include "AddComponentDialog.h"

void Editor::AddComponentDialog::on_tab_button_click(System::Object^ sender, System::EventArgs^ e)
{
	auto btn = (Btn^)sender;
	component_list->Visible = false;
}

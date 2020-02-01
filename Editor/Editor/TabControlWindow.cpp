#include "TabControlWindow.h"

void Editor::TabControlWindow::hide_tabs( bool hide )
{
	if ( hide )
	{
		tabs->ItemSize = Drawing::Size( 0, 1 );
		tabs->SizeMode = TabSizeMode::Fixed;
		//tabs->Controls[0]->Text = "";
	}
	else
	{
		tabs->ItemSize = Drawing::Size( 0, 18 );
		tabs->SizeMode = TabSizeMode::Normal;
	}
}

System::Void Editor::TabControlWindow::tabControl1_TabIndexChanged( System::Object^ sender, System::EventArgs^ e )
{
	tabText->Text = tabControl1->SelectedTab->Text;
}

System::Void Editor::TabControlWindow::tabControl1_ControlAdded( System::Object^ sender, System::Windows::Forms::ControlEventArgs^ e )
{
	tabText->Text = tabControl1->SelectedTab->Text;
}

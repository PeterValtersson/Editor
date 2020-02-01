#include "AddNewComponent.h"

System::Void Editor::AddNewComponent::AddBtn_Click( System::Object^ sender, System::EventArgs^ e )
{
	if ( cmbComponents->SelectedItem )
	{
		add_callback( (Control^)cmbComponents->SelectedItem );
		cmbComponents->Items->Remove( cmbComponents->SelectedItem );
	}
}

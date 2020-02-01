#include "ComponentView.h"
#include "TransformComponent.h"
#include "AddNewComponent.h"
#include "ComponentControl.h"

void Editor::ComponentView::EntityChanged()
{
	componentPanel->Controls->Clear();
	splitContainer1->Panel1->Controls->Clear();

	if ( _selectedEntity == ~0 )
		return;

	auto managers = engine->engine->get_managers();

	auto adder = gcnew AddNewComponent( gcnew AddComponentCallback( this, &ComponentView::AddComponent ) );
	if ( managers.transform_manager->is_registered( _selectedEntity ) )
	{
		auto tc = gcnew TransformComponent( engine, _selectedEntity );
		auto tcb = gcnew ComponentControl( gcnew ComponenetSelected( this, &ComponentView::ComponentSelected ), tc );
		componentPanel->Controls->Add( tcb );
	}
	else
		adder->Components->Add( gcnew TransformComponent( engine, _selectedEntity ) );
	//...



	componentPanel->Controls->Add( adder );
}

void Editor::ComponentView::ComponentSelected( Control^ component )
{
	splitContainer1->Panel1->Controls->Add( component );
}

void Editor::ComponentView::AddComponent( Control^ component )
{
	( ( BaseComponent^ )component )->Create();
	auto tcb = gcnew ComponentControl( gcnew ComponenetSelected( this, &ComponentView::ComponentSelected ), component );
	componentPanel->Controls->Add( tcb );
	componentPanel->Controls->SetChildIndex( tcb, componentPanel->Controls->Count - 2 );
}

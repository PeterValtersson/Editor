#include "WindowSplit.h"
void Editor::WindowSplit::add_view( Location location, Control^ control )
{
	views[location]->Add( control );
	setup_spliters();
}

void Editor::WindowSplit::setup_spliters()
{
	if ( views[Location::Left]->Count == 0 )
		split1->Panel1Collapsed = true;
	else
		split1->Panel1Collapsed = false;

	if ( views[Location::Right]->Count == 0 )
		split2->Panel2Collapsed = true;
	else
		split2->Panel2Collapsed = false;

	if ( views[Location::Top]->Count == 0 )
		split3->Panel1Collapsed = true;
	else
		split3->Panel1Collapsed = false;

	if ( views[Location::Bottom]->Count == 0 )
		split3->Panel2Collapsed = true;
	else
		split3->Panel2Collapsed = false;




	left_views->tabs->Controls->Clear();
	for each ( Control ^ c in views[Location::Left] )
	{
		auto tab = gcnew TabPage( c->Name );
		tab->Controls->Add( c );
		left_views->tabs->Controls->Add( tab );
	}

	right_views->tabs->Controls->Clear();
	for each ( Control ^ c in views[Location::Right] )
	{
		auto tab = gcnew TabPage( c->Name );
		tab->Controls->Add( c );
		right_views->tabs->Controls->Add( tab );
	}

	top_views->tabs->Controls->Clear();
	for each ( Control ^ c in views[Location::Top] )
	{
		auto tab = gcnew TabPage( c->Name );
		tab->Controls->Add( c );
		top_views->tabs->Controls->Add( tab );
	}

	bottom_views->tabs->Controls->Clear();
	for each ( Control ^ c in views[Location::Bottom] )
	{
		auto tab = gcnew TabPage( c->Name );
		tab->Controls->Add( c );
		bottom_views->tabs->Controls->Add( tab );
	}


	left_views->hide_tabs( views[Location::Left]->Count == 1 );
	right_views->hide_tabs( views[Location::Right]->Count == 1 );
	top_views->hide_tabs( true );
	bottom_views->hide_tabs( views[Location::Bottom]->Count == 1 );

}

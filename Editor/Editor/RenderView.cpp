#include "RenderView.h"
#include "StringHelpers.h"

System::Void Editor::RenderView::RenderView_Resize( System::Object^ sender, System::EventArgs^ e )
{
	resize_delay->Enabled = true;
	resize_delay->Stop();
	resize_delay->Start();
}

System::Void Editor::RenderView::resize_delay_Tick( System::Object^ sender, System::EventArgs^ e )
{
	resize_delay->Enabled = false;
	if ( engine->window )
	{
		engine->window->SetHWND( this->Handle.ToPointer() );
		auto r = engine->engine->get_sub_systems().renderer;
		Renderer::RendererInitializationInfo ii;
		ii.resolution = *( Renderer::Resolution* ) & engine->window->GetResolution();
		ii.windowHandle = engine->window->GetWindowHandle();
		try
		{
			r->UpdateSettings( ii );

		}
		catch ( Utilities::Exception & e )
		{
			MessageBox::Show( managedString( e.what() ), managedString( e.title ), MessageBoxButtons::OK );
		}
	}
	
}

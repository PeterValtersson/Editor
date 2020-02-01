#include "MainWindow.h"
#include "EngineWindowInterface.h"
#include "StringHelpers.h"
#include <Resource.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main( array <String^>^ args )
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault( false );
	try
	{
		Editor::MainWindow form;
		Application::Run( % form );
	}
	catch ( Utilities::Exception & e )
	{
		MessageBox::Show( managedString( e.what() ), managedString( e.title ), MessageBoxButtons::OK );
	}
	return 0;
}

Editor::MainWindow::MainWindow( void ) : engine( nullptr )
{

	InitializeComponent();
	spliter = gcnew WindowSplit;
	spliter->Dock = DockStyle::Fill;
	toolStripContainer1->ContentPanel->Controls->Add( spliter );

	engine = new EnginePtr;
	render_view = gcnew RenderView( engine );
	render_view->Dock = DockStyle::Fill;
	render_view->Name = "Render Scene";


	engine->window = std::make_shared<EngineWindowInterface>( render_view->Handle.ToPointer() );
	Engine::Init_Info ii;
	ii.mode = ResourceHandler::AccessMode::read_write;
	ii.sub_systems.window = engine->window;

	engine->engine = Engine::IEngine::create( ii );
	engine->engine->start( true );

	spliter->add_view( WindowSplit::Location::Top, render_view );


	component_view = gcnew ComponentView( engine );
	component_view->Dock = DockStyle::Fill;
	component_view->Name = "Components";
	spliter->add_view( WindowSplit::Location::Right, component_view );

	scene_view = gcnew SceneView( engine, component_view );
	spliter->add_view( WindowSplit::Location::Left, scene_view );


}

Editor::MainWindow::~MainWindow()
{
	if ( components )
	{
		delete components;
	}
	if ( engine )
	{
		delete engine;
		engine = nullptr;
	}

}

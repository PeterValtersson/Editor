#include "SceneView.h"
#include "Events.h"

System::Void Editor::SceneView::newSceneCMBTN_Click( System::Object^ sender, System::EventArgs^ e )
{
	auto manager = engine->engine->get_entity_components();
	Entity entity = manager.entity_factory->create();
	manager.scene_component->create( entity, "New Scene" );
	auto tree_node = gcnew TreeNode( "New Scene" );
	tree_node->Tag = entity;
	tree_node->ContextMenuStrip = sceneTreeNodeCM;

	if ( cmSelectedNode )
	{
		manager.scene_component->add_entity_to_scene( ( Entity )cmSelectedNode->Tag, entity );
		cmSelectedNode->Nodes->Add( tree_node );
		cmSelectedNode->Expand();
	}
	else
		scene_tree->Nodes->Add( tree_node );
}

System::Void Editor::SceneView::sceneTreeNodeCM_Opening( System::Object^ sender, System::ComponentModel::CancelEventArgs^ e )
{
	auto point = scene_tree->PointToClient( System::Windows::Forms::Cursor::Position );
	cmSelectedNode = scene_tree->GetNodeAt( point );
}

System::Void Editor::SceneView::scene_tree_AfterSelect( System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e )
{
	EditorEvents::on_selected_entity_changed((Entity)e->Node->Tag);
}

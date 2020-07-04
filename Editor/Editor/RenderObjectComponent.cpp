#include "RenderObjectComponent.h"

void Editor::RenderObjectComponent::Create()
{
	engine->engine->get_managers().transform_manager->Create( entity );
}
#include "ComponentViewNew.h"

void Editor::ComponentViewNew::set_entity(Entity entity)
{
	add_component_dialog->clear_components();

	component_list = gcnew ComponentList();
	component_list_panel->Controls->Clear();
	component_list_panel->Controls->Add(component_list);
	auto lbl = gcnew Label();
	lbl->Text = gcnew String("Test");
	component_list->add_component(lbl);

	auto reflected_components = engine->engine->get_component_reflections();
	for (auto compt : reflected_components)
		if (auto component = compt.lock())
		{
			if (component->is_registered_re(entity))
				component_list->add_component(gcnew Button());
			else
				add_component_dialog->add_component(component);
		}

	
}

System::Void Editor::ComponentViewNew::add_component_Click(System::Object^ sender, System::EventArgs^ e)
{
	add_component_dialog->Width = add_component->Width;
	add_component_poper->show(add_component);
}

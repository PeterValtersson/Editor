#pragma once
#include <ECS/Components/ComponentReflection.h>
#include <memory>
using namespace System;
namespace EditorInterop
{
	typedef uint32_t Entity;
	public ref class ComponentReflection
	{
	public:
		ComponentReflection(std::weak_ptr<ECS::ComponentReflection> component)
		{
			this->component = new std::weak_ptr<ECS::ComponentReflection>(component);

		}
		~ComponentReflection()
		{
			if (component)
				delete component;
		}
		 
		bool is_registered_re(Entity entity);
		String^ get_name();
		String^ get_reflection_meta_data();
		String^ get_reflection_data(const Entity entity);
		void set_data_from_json(const Entity entity, String^ data);
	private:
		std::weak_ptr<ECS::ComponentReflection>* component;
	};
}

#pragma once
#include "EntityFactory.h"
#include <ECS/Components/SceneComponent.h>
#include <msclr\marshal_cppstd.h>

using namespace System;
namespace EditorInterop
{
	public ref class Scene
	{
	public:
		Scene(std::shared_ptr<ECS::SceneComponent> scene)
		{
			this->scene = new std::shared_ptr<ECS::SceneComponent>();
			*this->scene = scene;
		}
		~Scene()
		{
			if (scene)
				delete scene;
		}
		void create(Entity entity, String^ name)
		{
			(*scene)->create(entity, msclr::interop::marshal_as<std::string>(name));
		}
	private:
		std::shared_ptr<ECS::SceneComponent>* scene;
	};
}
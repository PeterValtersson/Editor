#pragma once
#include <ECS/EntityFactory.h>
namespace EditorInterop
{
	typedef uint32_t Entity;
	public ref class EntityFactory
	{
	public:
		EntityFactory(std::shared_ptr<ECS::EntityFactory> ef)
		{
			this->ef = new std::shared_ptr<ECS::EntityFactory>();
			*this->ef = ef;
		}
		~EntityFactory()
		{
			if (ef)
				delete ef;
		}
		Entity create()
		{
			return (*ef)->create();
		}
		std::shared_ptr<ECS::EntityFactory>* ef;
	};

}
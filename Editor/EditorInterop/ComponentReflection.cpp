#include "pch.h"
#include "ComponentReflection.h"

bool EditorInterop::ComponentReflection::is_registered_re(Entity entity)
{
	return false;
}

String^ EditorInterop::ComponentReflection::get_name()
{
	if (auto c = (*component).lock())
	{
		return gcnew String(c->get_name().c_str());
	}
	throw gcnew Exception("Component reflection pointer could not be locked");
}

String^ EditorInterop::ComponentReflection::get_reflection_meta_data()
{
	if (auto c = (*component).lock())
	{
		auto json = c->get_reflection_meta_data();
		auto serialized = json.dump();
		return gcnew String(serialized.c_str());
	}
	throw gcnew Exception("Component reflection pointer could not be locked");
}

String^ EditorInterop::ComponentReflection::get_reflection_data(const Entity entity)
{
	if (auto c = (*component).lock())
	{
		try
		{
			auto json = c->get_reflection_data(entity); 
			auto serialized = json.dump();
			return gcnew String(serialized.c_str());
		}
		catch (const std::exception& e)
		{
			throw gcnew Exception(gcnew String(e.what()));
		}
		
	}
	return "";
}

#include "pch.h"
#include "ComponentReflection.h"

bool EditorInterop::ComponentReflection::is_registered_re(Entity entity)
{
	if (auto c = (*component).lock())
		return c->is_registered_re(entity);
	throw gcnew Exception("Component reflection pointer could not be locked");
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
	throw gcnew Exception("Component reflection pointer could not be locked");
}

std::string managedStrToNative(System::String^ sysstr)
{
	using System::IntPtr;
	using System::Runtime::InteropServices::Marshal;

	IntPtr ip = Marshal::StringToHGlobalAnsi(sysstr);
	std::string outString = static_cast<const char*>(ip.ToPointer());
	Marshal::FreeHGlobal(ip);
	return outString;
}
#include <Utilities/Console/Console.h>
void EditorInterop::ComponentReflection::set_data_from_json(const Entity entity, String^ data)
{
	if (auto c = (*component).lock())
	{
		try
		{
			auto json_string = managedStrToNative(data);
			Utilities::console_print(json_string);
			auto json = json::parse(json_string);
			c->set_data_from_json(entity, json);
			return;
		}
		catch (const std::exception& e)
		{
			throw gcnew Exception(gcnew String(e.what()));
		}

	}
	throw gcnew Exception("Component reflection pointer could not be locked");
}

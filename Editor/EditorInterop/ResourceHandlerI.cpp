#include "pch.h"
#include "ResourceHandlerI.h"
#include <IResourceHandler.h>

List<ResourceMetaInfo^>^ ResourceHandlerI::GetAllResources()
{
	auto ra = ResourceHandler::IResourceHandler::get()->get_archive();
	auto resources = ra->get_resources();
	auto list = gcnew List<ResourceMetaInfo^>();
	for (auto& info : resources)
	{
		auto listr = gcnew ResourceMetaInfo();
		listr->name = gcnew String(info.name.c_str());
		listr->ID = info.ID;
		listr->type = info.type;
		list->Add(listr);
	}
	return list;
}

void ResourceHandlerI::Save()
{

	ResourceHandler::IResourceHandler::get()->save_all();

}

UtilitiesGUID ResourceHandlerI::MakeGUID(String^ str)
{
	return Utilities::GUID(msclr::interop::marshal_as<std::string>(str)).id;
}

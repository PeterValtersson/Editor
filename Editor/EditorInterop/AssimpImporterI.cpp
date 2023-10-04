#include "pch.h"
#include "AssimpImporterI.h"
#include <AssimpInterface.h>


void AssimpImporterI::Import(String^ file)
{

	auto file_string = msclr::interop::marshal_as<std::string>(file);
	Assimp::AssimpImporter::import(file_string);
}



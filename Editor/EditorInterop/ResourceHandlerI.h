#pragma once
#include <stdint.h>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Collections::Generic;

typedef uint32_t UtilitiesGUID;
public ref struct ResourceMetaInfo
{
	String^ name;
	UtilitiesGUID ID;
	UtilitiesGUID type;
};
public ref class ResourceHandlerI
{
public:
	static List<ResourceMetaInfo^>^ GetAllResources();
	static void Save();
	static UtilitiesGUID MakeGUID(String^ str);
};


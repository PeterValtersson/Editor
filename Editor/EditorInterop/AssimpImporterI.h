#pragma once
#include <msclr\marshal_cppstd.h>

using namespace System;

public ref class AssimpImporterI
{
public:
	static void Import(String^ file);
};


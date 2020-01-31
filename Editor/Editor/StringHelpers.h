#include <string>
#ifndef _MMSST_H_
#define _MMSST_H_

using namespace System;
inline std::string marshalString( String^ s )
{
	using namespace Runtime::InteropServices;
	const char* chars = ( const char* )( Marshal::StringToHGlobalAnsi( s ) ).ToPointer();
	std::string res( chars );
	Marshal::FreeHGlobal( IntPtr( ( void* )chars ) );
	return res;
}
inline String^ managedString( const std::string& str )
{
	return gcnew String( str.c_str() );
}
#endif
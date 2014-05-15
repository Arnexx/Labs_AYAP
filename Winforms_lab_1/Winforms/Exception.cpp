#include "Exception.hpp"

mException::mException()
{
	mString = "";
}

mException::mException(const char* str)
{
	mString = "";
	mString += str; 
}
System::String^ mException::ShowStr() const
{

	System::String^ s = gcnew System::String(mString.c_str()); 
	return s;
}
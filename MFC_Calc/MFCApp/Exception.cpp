#include "stdafx.h"
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
const char* mException::ShowStr() const
{	
	const char* str = mString.c_str();
	return str;
}
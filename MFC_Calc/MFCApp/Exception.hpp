#pragma once

#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
class mException
{
public:
	mException();
	mException(const char* str);

const char*    ShowStr() const;

private:
	string mString;
};
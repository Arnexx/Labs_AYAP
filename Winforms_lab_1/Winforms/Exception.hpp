#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace System;
using namespace System::Windows::Forms;
using namespace std;
class mException
{
public:
	mException();
	mException(const char* str);

System::String^    ShowStr() const;

private:
	string mString;
};
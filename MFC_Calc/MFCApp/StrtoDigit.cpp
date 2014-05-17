#include "stdafx.h"
#include "StrtoDigit.hpp"


double  StrtoDigit(CString str, int length)
{
	if(!length) return 0;
	if (length >= 16) throw(mException("Error.Too long number"));
	bool Dot = false;
	double increaser = 10;
	double decreaser = 10;
	double res = 0;
	for(int itr = 0; itr < length; itr++)
	{
		if( isdigit(str[itr]) && !Dot ) 
		{
			res *= increaser;
			res += (str[itr]-'0');
		}
		if( (str[itr] == '.') || (str[itr] == ','))
		{
			if(Dot) 
				{
					 
					throw(mException("Error. Double dot"));
					
			    }
			else Dot = true;
		}
		else
		{
			if (!isdigit(str[itr])) 
				{
					
					throw(mException("Error. Not a number"));
					
			    }
		}
		if( isdigit(str[itr]) && Dot )
		{
			res += ( (str[itr] - '0') / decreaser );
			decreaser *= increaser;
		}

	}
	return res;
}
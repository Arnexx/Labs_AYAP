#include <iostream>
#include "string.h"
using namespace std;


class Number
{
private:
	float num;
	char* strNum;

public:
	Number() : num(0)
	{
		strNum = new char[25];
	}
	~Number()
	{
		delete[] strNum;
	}
	void setNum(const char*);
	void printNumParts();
	int intactPartSize();
	int fractedPartSize();
	float getNum();

};
/////////////////////////////////////////////////////////
void Number :: setNum(const char* temp)
{	
	int intact = 1;
	float number = 0, fract = 10;
	memcpy(strNum, temp, (strlen(temp)+1)*sizeof(char));
	for(int i = intactPartSize()-1; i >= 0; i--)
	{
		number += (strNum[i] - '0')*intact;
		intact *= 10;
	}
	for(int i = intactPartSize()+1; i < strlen(strNum); i++)
	{
		number += (strNum[i]- '0')/fract;
		fract *= 10;
	}
	num = number;

}
void Number :: printNumParts()
{
	cout<<"intact part = "<<intactPartSize()<<endl;
	cout<<"fracted part = "<<fractedPartSize()<<endl;
	cout<< "devision = "<<(float)intactPartSize()/(float)fractedPartSize();
	cout<<endl<<"----------------------------------------------------------------------";
}

int Number :: intactPartSize()
{
	int pos = 0;
	for(int i = 0; i < strlen(strNum); i++)
	{
		if(strNum[i] == '.')
			pos = i;
	}
	if(pos)
		return pos;
	else return strlen(strNum);
}

int Number :: fractedPartSize()
{
	int pos = 0,temp = 0;
	for(int i = 0; i < strlen(strNum); i++)
	{
		if(strNum[i] == '.')
			pos = i;
	}
	if(!pos)
		return pos;
	temp = strlen(strNum) - pos -1;
	if((temp == 1) && (strNum[pos+1] == '0'))
		temp = 0;
	return temp;

}
float Number :: getNum()
{
	return num;
}
////////////////////////////////////////////////////////
int main()
{
	int n;
	cout<<"n = ";
	cin>>n;
	Number* mas = new Number[n];
	char* str = new char[25];
	float sum=0;
	for (int i = 0; i < n; i++)
	{
		cout<<endl<<"number = ";
		cin >> str;
		mas[i].setNum(str);
		mas[i].printNumParts();
		sum += mas[i].getNum();
	}

	cout<<endl<<"sum = "<<sum;
	system("pause");
	delete[] mas;
	return 0;
}
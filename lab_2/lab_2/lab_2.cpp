#pragma once
#include "Massiv.hpp"

int main()
{
	Massiv obj1;
	int mas[23];

	obj1.push(13);
	obj1.push(154);
	obj1.push(4);
	obj1.push(-434);

	obj1[2]+=400;
	for(int i=0; i<23;i++)
		mas[i] = i;

	Massiv obj2(mas, 23);
	Massiv obj3 = obj1 + obj2;
	cout<<"mas1 = ";
	obj1.printmas();

	cout<<"mas2 = ";
	obj2.printmas();

	cout<<"mas3 = ";
	obj3.printmas();

	system("pause");
	return 0;
}


#pragma once
#include "Massiv.hpp"

Massiv::Massiv(): mas(nullptr), num(0)
{
}
Massiv::Massiv(int* temp_mas,unsigned int tnum) 
{
	mas = new int[tnum];
	num = tnum;
	for(int itr = 0; itr < tnum; itr++)
	{
		mas[itr] = temp_mas[itr];
	}
}
Massiv::Massiv(const Massiv& a)
{
	this->num = a.num;
	this->mas = new int[a.num];

	for (int itr=0;itr<a.num;itr++)
	{
		this->mas[itr]=a.mas[itr];
	}
}
Massiv::~Massiv()
{
	delete[] mas;
}
void Massiv::printmas() const
{
	for( int itr = 0; itr < num; itr++)
		cout<<mas[itr]<<"  ";
	cout<<endl;
}
int& Massiv::operator[] (unsigned int numb)
{
	int null = 0;
	if (num >= numb)
		return mas[numb];
	else return null;
}

unsigned int Massiv::getSize() const
{
	return num;
}

void Massiv::push(int temp_value)
{  
	mas = (int*) realloc(mas, sizeof(int)*(num+1));
	mas[num] = temp_value;
	num++;
}


Massiv Massiv::operator+ (Massiv& obj) const
{
	unsigned int leng;
	int* temp = new int[max(getSize(), obj.getSize())];
	leng = min(getSize(), obj.getSize());
	for (int itr = 0; itr < leng; itr++)
	{
		temp[itr] = mas[itr] + obj[itr];
	}
	for(int itr = leng; itr < max(getSize(), obj.getSize()); itr++ )
	{
		if (getSize() < obj.getSize())
			temp[itr] = obj[itr];
		else temp[itr] = mas[itr];
	}
	leng = max(getSize(), obj.getSize());			
	Massiv mas_temp(temp, leng);
	delete[] temp;
	return mas_temp;
}


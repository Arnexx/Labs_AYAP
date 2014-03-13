#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Massiv
{
private:
	int*           mas;
	unsigned int   num;
public:
	                 Massiv();
					 Massiv(int*, unsigned int);
					 Massiv(const Massiv&);
					 ~Massiv();
	void	         printmas() const;
	unsigned int     getSize() const;
	void             push(int);
	int&             operator[] (unsigned int);
	Massiv           operator+ (Massiv&) const;
};
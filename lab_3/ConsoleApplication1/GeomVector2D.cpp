#pragma once
#include "GeomVector2D.hpp"

  G_Vector_2D::G_Vector_2D()
{
	x = 0;
	y = 0;
}

float G_Vector_2D::solveVector() const
{
	float temp;
	temp = sqrt(x*x + y*y);
	return temp;
}


void G_Vector_2D::printVector() const
{
	cout<<"X = "<< x<<endl;
	cout<<"Y = "<< y<<endl;
	cout<<"Length = " << solveVector() <<endl<<endl;
}

void G_Vector_2D::setPosition(float mX, float mY)
{
	x = mX;
	y = mY;
}


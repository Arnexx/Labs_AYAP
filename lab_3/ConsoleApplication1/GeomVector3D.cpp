#pragma once
#include "GeomVector3D.hpp"

G_Vector_3D::G_Vector_3D() : G_Vector_2D()
{
	z = 0;
}

float G_Vector_3D::solveVector() const
{
	float temp;
	temp = sqrt(x*x + y*y + z*z);
	return temp;
}


void G_Vector_3D::printVector() const
{
	cout<<"X = "<< x<<endl;
	cout<<"Y = "<< y<<endl;
	cout<<"Z = "<< z<<endl;
	cout<<"Length = " << solveVector() <<endl<<endl;
}

void G_Vector_3D::setPosition(float mX, float mY, float mZ)
{
	G_Vector_2D::setPosition(mX,mY);
	z = mZ;
}


#pragma once
#include <iostream>
using namespace std;

class G_Vector_2D
{
public:
	                G_Vector_2D();
	virtual void    printVector() const;
	virtual float   solveVector() const;
	virtual void    setPosition(float, float);
protected:
	float x;
	float y;
};

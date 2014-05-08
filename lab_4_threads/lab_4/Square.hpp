#pragma  once
#include "Shape.hpp"

class Square : public Shape
{
public:
	        Square();
	        Square(G_Point Origin, int Length, float Angle, float RotationVelocity,
		             bool Vertical, int Velocity, int red, int green, int blue);
	void    DrawShape(WindowParams* param);
	void    Wipe(WindowParams* param);
};
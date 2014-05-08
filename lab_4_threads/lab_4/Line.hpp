#pragma once
#include "Shape.hpp"

class Line : public Shape
{
public:
	       Line();
	       Line(G_Point Origin, int Length, float Angle, float RotationVelocity,
		     bool Vertical, int Velocity, int red, int green, int blue);
    void   DrawShape(WindowParams* params);
	void   Wipe(WindowParams* params);
};
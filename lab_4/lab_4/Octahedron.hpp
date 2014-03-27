#pragma once
#include "Shape.hpp"
#include <math.h>

class Octahedron : public Shape
{
public:
	        Octahedron();
        	Octahedron(G_Point Origin, int Length, float Angle, float RotationVelocity,
		              bool Vertical, int Velocity, int red, int green, int blue);
	void    DrawShape(WindowParams* param);
	void    Wipe(WindowParams* param);
};
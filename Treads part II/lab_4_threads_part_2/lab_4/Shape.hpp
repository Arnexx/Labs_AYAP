#pragma  once
#include "WinParams.hpp"


class Shape
{
protected:
	G_Point   Origin;
	int       Length;
	float     Angle;
	float       RotationVelocity;
	bool      Vertical;
	int       Velocity;
	COLORREF  Color;
public:
	Shape();
	Shape(G_Point Origin, int Length, float Angle, float RotationVelocity,
		bool Vertical, int Velocity, int red, int green, int blue);

	    void           setPosition(WindowParams* param);
		virtual void   DrawShape(WindowParams*) = 0;
		virtual void   Wipe(WindowParams*) = 0;
};
#pragma  once
#include "Square.hpp"
#include <math.h>

Square::Square() : Shape()
{
}

Square::Square(G_Point Origin, int Length, float Angle, float RotationVelocity,
			   bool Vertical, int Velocity, int red, int green, int blue)
			     : Shape(Origin,Length, Angle, RotationVelocity,
			             Vertical, Velocity, red, green, blue)
{
}

void Square::DrawShape(WindowParams* param)
{
	HDC hDC = param->compatibleDc;
	HPEN pen = CreatePen( 0, 5, Color);
	HGDIOBJ oldPen = SelectObject( hDC, pen );


	MoveToEx(hDC, Origin.x, Origin.y, NULL);
	LineTo(hDC, Origin.x + Length * cos(Angle), Origin.y - Length * sin(Angle));
	LineTo(hDC, Origin.x + Length * sqrt(2.0) * cos(Angle - M_PI/4.0), Origin.y - Length * sqrt(2.0) * sin(Angle - M_PI/4.0) );
	LineTo(hDC, Origin.x  + Length * cos(Angle - M_PI/2.0), Origin.y - Length * sin(Angle - M_PI/2.0));
	LineTo(hDC, Origin.x, Origin.y);

	SelectObject( hDC, oldPen );
	DeleteObject( pen );
}

void Square::Wipe(WindowParams* param)
{
	HDC hDC = param->compatibleDc;
	HPEN pen = CreatePen( 0,5, RGB(255, 255, 255));
	HGDIOBJ oldPen = SelectObject( hDC, pen );


	MoveToEx(hDC, Origin.x, Origin.y, NULL);
	LineTo(hDC, Origin.x + Length * cos(Angle), Origin.y - Length * sin(Angle));
	LineTo(hDC, Origin.x + Length * sqrt(2.0) * cos(Angle - M_PI/4.0), Origin.y - Length * sqrt(2.0) * sin(Angle - M_PI/4.0) );
	LineTo(hDC, Origin.x  + Length * cos(Angle - M_PI/2.0), Origin.y - Length * sin(Angle - M_PI/2.0));
	LineTo(hDC, Origin.x, Origin.y);

	SelectObject( hDC, oldPen );
	DeleteObject( pen );
}


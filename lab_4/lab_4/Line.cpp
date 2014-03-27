#include "Line.hpp"

Line::Line() : Shape()
{
}

Line::Line(G_Point Origin, int Length, float Angle, float RotationVelocity,
		   bool Vertical, int Velocity, int red, int green, int blue)
		        : Shape(Origin,Length, Angle, RotationVelocity,
		                Vertical, Velocity, red, green, blue)
{
}

void Line::DrawShape(WindowParams* params)
{
	HDC hDC = params->compatibleDc;
	HPEN pen = CreatePen( 0, 5, Color);
	HGDIOBJ oldPen = SelectObject( hDC, pen );

	MoveToEx(hDC, Origin.x, Origin.y, NULL);
	LineTo(hDC, Origin.x + Length * cos(Angle), Origin.y - Length * sin(Angle));

	SelectObject( hDC, oldPen );
	DeleteObject( pen );
}

void Line::Wipe(WindowParams* params)
{
	HDC hDC = params->compatibleDc;
	HPEN pen = CreatePen( 0, 5, RGB(255, 255, 255));
	HGDIOBJ oldPen = SelectObject( hDC, pen );

	MoveToEx(hDC, Origin.x, Origin.y, NULL);
	LineTo(hDC, Origin.x + Length * cos(Angle), Origin.y - Length * sin(Angle));

	SelectObject( hDC, oldPen );
	DeleteObject( pen );
}
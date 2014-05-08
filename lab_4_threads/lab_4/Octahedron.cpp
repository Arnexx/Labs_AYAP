#include "Octahedron.hpp"

Octahedron::Octahedron() : Shape()
{
}

Octahedron::Octahedron(G_Point Origin, int Length, float Angle, float RotationVelocity,
					   bool Vertical, int Velocity, int red, int green, int blue)
					        : Shape(Origin,Length, Angle, RotationVelocity,
					               Vertical, Velocity, red, green, blue)
{
}


void Octahedron::DrawShape(WindowParams* param)
{
	HDC hDC = param->compatibleDc;
	HPEN pen = CreatePen( 0, 5, Color);
	HGDIOBJ oldPen = SelectObject( hDC, pen );
	int DLeng = sqrt(Length*Length/4 + Length*Length*sin(M_PI/4.0)*sin(M_PI/4.0)); 
	float tempANGLE = Angle;

	MoveToEx(hDC, Origin.x + DLeng*cos(Angle), Origin.y -DLeng*sin(Angle), NULL);
	tempANGLE -= M_PI/4.0;
	for(int itr = 0; itr < 8; ++itr)
	{
		LineTo(hDC, Origin.x + DLeng*cos(tempANGLE), Origin.y - DLeng*sin(tempANGLE) );
		tempANGLE -= M_PI/4.0;
	}


	SelectObject( hDC, oldPen );
	DeleteObject( pen );
}

void Octahedron::Wipe(WindowParams* param)
{
	HDC hDC = param->compatibleDc;
	HPEN pen = CreatePen( 0, 5, RGB(255,255,255));
	HGDIOBJ oldPen = SelectObject( hDC, pen );
	int DLeng = sqrt(Length*Length/4 + Length*Length*sin(M_PI/4.0)*sin(M_PI/4.0)); 
	float tempANGLE = Angle;

	MoveToEx(hDC, Origin.x + DLeng*cos(Angle), Origin.y - DLeng*sin(Angle), NULL);
	tempANGLE -= M_PI/4.0;
	for(int itr = 0; itr < 8; ++itr)
	{
		LineTo(hDC, Origin.x + DLeng*cos(tempANGLE), Origin.y - DLeng*sin(tempANGLE) );
		tempANGLE -= M_PI/4.0;
	}


	SelectObject( hDC, oldPen );
	DeleteObject( pen );
}

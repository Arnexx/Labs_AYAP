#include "Shape.hpp"

Shape::Shape()
{
	G_Point temp;
	temp.x = 0;
	temp.y = 0;
	Origin = temp;
	Length = 0;
	Angle  = 0;
	RotationVelocity = 0;
	Velocity = 0;
	Vertical = true;
	Color = RGB(255,255,255);
}

Shape::Shape(G_Point point, int mLength, float mAngle, float RotationV,
	  bool mVertical, int mVelocity, int red, int green, int blue)
{
	Origin = point;
	Length = mLength;
	Angle  = mAngle;
	RotationVelocity = RotationV;
	Velocity = mVelocity;
	Vertical = mVertical;
    Color = RGB(red%256, green%256, blue%256);
}

void Shape::setPosition(WindowParams* param)
{
	Angle += RotationVelocity;
	Origin.x += (!Vertical) * Velocity;
	Origin.y += Vertical * Velocity;
	RECT rect;
	GetClientRect(param->hWnd, &rect);
	
	if( ((Origin.x + Length)  > rect.right)*(!Vertical))
		Velocity = abs(Velocity)*(-1);
	if( ((Origin.x - Length)  < rect.left)*(!Vertical))
		Velocity = abs(Velocity);

	if( ((Origin.y + Length)  > rect.bottom)*Vertical)
		Velocity = abs(Velocity)*(-1);
	if( ((Origin.y - Length)  < rect.top)*Vertical)
		Velocity = abs(Velocity);
}
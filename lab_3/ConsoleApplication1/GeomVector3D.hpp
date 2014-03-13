#pragma  once
#include "GeomVector2D.hpp"

class G_Vector_3D : public G_Vector_2D
{
public:
	        G_Vector_3D();
	void    printVector() const;
	float   solveVector() const;
	void    setPosition(float, float, float);
private:
	float z;
};
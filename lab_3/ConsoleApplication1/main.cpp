#pragma once
#include <time.h>
#include "GeomVector3D.hpp"

int main()
{
	G_Vector_2D *arrayVec[15];
	G_Vector_2D *ptr;

	srand(time((NULL)));

	for(int itr = 0; itr<15; itr++)
	{
		if(itr % 2)
			ptr = new G_Vector_2D;
			
		else 
			ptr = new G_Vector_3D;	

		arrayVec[itr] = ptr;
	}

	for(int itr = 0; itr < 15; itr++)
	{
		arrayVec[itr]->setPosition(rand()%100, rand()%100);
		arrayVec[itr]->printVector();
		delete arrayVec[itr];
	}
	
	cin.get();
	return 0;
}
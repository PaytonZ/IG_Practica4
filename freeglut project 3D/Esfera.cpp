#include "Esfera.h"


void Esfera :: dibuja()
{
	glColor3f(1,1,1); 
	gluSphere(esfera,radio,slice,stak);
}

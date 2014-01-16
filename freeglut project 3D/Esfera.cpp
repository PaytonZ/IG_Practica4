#include "Esfera.h"


void Esfera :: dibuja()
{
	glColor3f(r,g,b); 
	gluSphere(esfera,radio,slice,stak);
}

#include "Cilindro.h"


void Cilindro :: dibuja()
{
	gluCylinder(cilindro,radio1,radio2,alto,slice,stacks);
}

#include "Cilindro.h"


void Cilindro :: dibuja()
{
	gluCylinder(cilindro,radio,radio,alto,slice,stacks);
}

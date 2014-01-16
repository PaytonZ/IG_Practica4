#include "Disco.h"


void Disco :: dibuja()
{
	glColor3f(r,g,b); 
	gluDisk(disco,radioI,radioE,slice,vueltas);
}

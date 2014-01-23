/********************************************************************************
*																				*
*		Practica 4 IG - Muñeco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "Cilindro.h"


void Cilindro :: dibuja()
{
	glColor3f(r,g,b); 
	gluCylinder(cilindro,radio1,radio2,alto,slice,stacks);
}

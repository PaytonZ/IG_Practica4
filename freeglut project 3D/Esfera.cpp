/********************************************************************************
*																				*
*		Practica 4 IG - Muñeco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "Esfera.h"


void Esfera :: dibuja()
{
	glColor3f(r,g,b); 
	gluSphere(esfera,radio,slice,stak);
}

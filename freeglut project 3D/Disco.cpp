/********************************************************************************
*																				*
*		Practica 4 IG - Mu�eco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "Disco.h"


void Disco :: dibuja()
{
	glColor3f(r,g,b); 
	gluDisk(disco,radioI,radioE,slice,vueltas);
}

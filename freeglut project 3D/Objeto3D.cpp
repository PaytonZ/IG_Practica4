/********************************************************************************
*																				*
*		Practica 4 IG - Mu�eco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "Objeto3D.h"

void Objeto3D :: setTransAfin (TAfin matriz)
{
	for (int i=0; i<16; i++)
		m.matriz[i]=matriz.matriz[i];
}

void Objeto3D :: setColor(float rojo, float verde, float azul)
{
	r=rojo; g=verde; b=azul;
}

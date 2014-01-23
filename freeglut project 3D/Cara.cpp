/********************************************************************************
*																				*
*		Practica 4 IG - Mu�eco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/



#include "Cara.h"






void Cara:: setnumVertices(int nv)
{
	if (arrayVN)
		delete(arrayVN);
	arrayVN = new VerticeNormal*[numVetices];
}

void Cara:: setValor(int i, int v, int n)
{
	if (i<numVetices)
	{
		arrayVN[i]= new VerticeNormal(v,n);
	}
}

int Cara:: getNumeroVertices()
{
	return numVetices;
}

int Cara:: getIndiceNormalK(int i)
{
	return arrayVN[i]->indiceN;
}

int Cara:: getIndiceVerticeK(int i)
{
	return arrayVN[i]->indiceV;
}


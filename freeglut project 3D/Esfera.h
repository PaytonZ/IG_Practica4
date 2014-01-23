/********************************************************************************
*																				*
*		Practica 3 IG - Muñeco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/
#pragma once
#include <Windows.h>
#include <gl/GLU.h>
#include "Objeto3D.h"

class Esfera:
	public Objeto3D
{
public:
	Esfera(float ra, float sl, float st)
	{
		radio=ra; slice=sl;stak=st;
		esfera=gluNewQuadric();
		gluQuadricDrawStyle(esfera, GLU_FILL);
	}
	~Esfera(void)
	{
		//gluDeleteQuadric(esfera);
	}

	virtual void dibuja();
private:
	GLUquadricObj* esfera;
	float radio, slice, stak;
};


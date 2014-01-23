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

class Disco:
	public Objeto3D
{
public:
	Disco(float ri,float re,float sl,float vue)
	{
		radioI=ri;radioE=re;slice=sl;vueltas=vue;
		disco=gluNewQuadric();
		gluQuadricDrawStyle(disco, GLU_FILL);
	}
	~Disco(void)
	{
		//gluDeleteQuadric(disco);
	}

	virtual void dibuja();

private:
	GLUquadricObj* disco;
	float radioI;
	float radioE;
	float slice;
	float vueltas;
};


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
		gluQuadricDrawStyle(disco, GLU_LINE);
	}
	~Disco(void)
	{

	}

	virtual void dibuja();

private:
	GLUquadricObj* disco;
	float radioI;
	float radioE;
	float slice;
	float vueltas;
};


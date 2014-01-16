#pragma once

#include <Windows.h>
#include <gl/GLU.h>
#include "Objeto3D.h"

class Cilindro:
	public Objeto3D
{
public:
	Cilindro(float r, float a, float sli, float sta)
	{
		radio=r; alto=a; slice=sli; stacks=sta;
		cilindro=gluNewQuadric();
		gluQuadricDrawStyle(cilindro, GLU_FILL);
	}
	~Cilindro(void)
	{

	}

	virtual void dibuja();

private:
	GLUquadricObj* cilindro;
	float radio;
	float alto;
	float slice;
	float stacks;


};


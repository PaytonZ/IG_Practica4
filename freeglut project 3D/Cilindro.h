#pragma once

#include <Windows.h>
#include <gl/GLU.h>
#include "Objeto3D.h"

class Cilindro:
	public Objeto3D
{
public:
	Cilindro(){}
	Cilindro(float r1,float r2, float a, float sli, float sta)
	{
		radio1=r1;radio2=r2; alto=a; slice=sli; stacks=sta;
		cilindro=gluNewQuadric();
		gluQuadricDrawStyle(cilindro, GLU_FILL);
	}
	~Cilindro(void)
	{

	}

	virtual void dibuja();

private:
	GLUquadricObj* cilindro;
	float radio1;
	float radio2;
	float alto;
	float slice;
	float stacks;


};


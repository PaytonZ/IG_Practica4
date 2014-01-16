#pragma once

#include "TAfin.h"

class Objeto3D
{
public:
	Objeto3D(){}
	virtual void dibuja()=0;
	void setTransAfin(TAfin matriz);
	void setColor(float rojo, float verde, float azul);
	TAfin m;
	float r,g,b;



};


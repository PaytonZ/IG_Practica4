#pragma once

#include "TAfin.h"

class Objeto3D
{
public:
	Objeto3D(){}
	virtual void dibuja()=0;
	void setTransAfin(TAfin matriz);
	TAfin m;



};


#pragma once
#include "Cilindro.h"

class Ojos:
	public Objeto3D
{
public:
	Ojos(){}
	Ojos(bool esDerecho)
	{
		esD=esDerecho;
		if(esDerecho)
		{
			ciOjo = new Cilindro(0.5,0.5,1.2,20,2);
			TAfin matrizODD= TAfin();
			matrizODD=matrizODD.rotateY(90);
			matrizODD=matrizODD.translated(1.5,7.5,1.4);
			//ciOjo->setTransAfin(matrizODD);
			setTransAfin(matrizODD);
			ciOjo->setColor(1,0,0.4);
		}
		else
		{
			ciOjo = new Cilindro(0.5,0.5,1.2,20,2);
			TAfin matrizODD= TAfin();
			matrizODD=matrizODD.rotateY(90);
			matrizODD=matrizODD.translated(-1.5,7.5,1.4);
			setTransAfin(matrizODD);
			ciOjo->setColor(1,0,0.4);
		}
	}
	~Ojos(void){}

	virtual void dibuja();

private:
	Cilindro *ciOjo;
	bool esD;
};


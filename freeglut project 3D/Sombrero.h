#pragma once
#include "ObjetoCompuesto.h"
#include "Disco.h"
#include "Cilindro.h"


class Sombrero
{
public:
	Sombrero()
	{
		gorro = ObjetoCompuesto(3);

		Objeto3D* baseGorro = new Disco(1,2,20,2);
		TAfin matrizBase= TAfin();
		matrizBase= matrizBase.rotateX(90);
		matrizBase= matrizBase.translated(0,0,-9);
		baseGorro->setTransAfin(matrizBase);
		gorro.anadeObjetoLista(baseGorro);

		Objeto3D* copaGorro = new Cilindro(1,1,2,20,2);
		TAfin matrizCopa= TAfin();
		matrizCopa= matrizCopa.rotateX(90);
		matrizCopa= matrizCopa.translated(0,0,-11);
		copaGorro->setTransAfin(matrizCopa);
		gorro.anadeObjetoLista(copaGorro);

		Objeto3D* tapaGorro = new Disco(0,1,20,2);
		tapaGorro->setTransAfin(matrizCopa);
		gorro.anadeObjetoLista(tapaGorro);


	}
	~Sombrero(void)
	{

	}

	void dibuja();

private:
	ObjetoCompuesto gorro;
};

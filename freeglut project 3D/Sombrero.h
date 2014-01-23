/********************************************************************************
*																				*
*		Practica 3 IG - Muñeco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/


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
		baseGorro->setColor(0.5,0.5,0.5);

		Objeto3D* copaGorro = new Cilindro(1,1,2,20,2);
		TAfin matrizCopa= TAfin();
		matrizCopa= matrizCopa.rotateX(90);
		matrizCopa= matrizCopa.translated(0,0,-11);
		copaGorro->setTransAfin(matrizCopa);
		gorro.anadeObjetoLista(copaGorro);
		copaGorro->setColor(0.5,0.5,0.5);

		Objeto3D* tapaGorro = new Disco(0,1,20,2);
		tapaGorro->setTransAfin(matrizCopa);
		gorro.anadeObjetoLista(tapaGorro);
		tapaGorro->setColor(0.5,0.5,0.5);


	}
	~Sombrero(void)
	{

	}

	void dibuja();

private:
	ObjetoCompuesto gorro;
};


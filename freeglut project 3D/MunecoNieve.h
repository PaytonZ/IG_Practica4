#pragma once
#include "ObjetoCompuesto.h"
#include "Sombrero.h"
#include "Esfera.h"

class MunecoNieve
{
public:
	MunecoNieve(void)
	{
		somb= Sombrero();

		muneco= ObjetoCompuesto(8);

		Objeto3D* ojoDer= new Disco(0,0.5,20,2);
		TAfin matrizOD= TAfin();
		matrizOD=matrizOD.rotateY(90);
		matrizOD=matrizOD.translated(1.5,7.5,2.6);
		ojoDer->setTransAfin(matrizOD);
		muneco.anadeObjetoLista(ojoDer);

		Objeto3D* ojoIzq= new Disco(0,0.5,20,2);
		TAfin matrizIZ= TAfin();
		matrizIZ=matrizIZ.rotateY(90);
		matrizIZ=matrizIZ.translated(-1.5,7.5,2.6);
		ojoIzq->setTransAfin(matrizIZ);
		muneco.anadeObjetoLista(ojoIzq);

		Objeto3D* nariz= new Cilindro(0.5,0,2.5,20,2);
		TAfin matrizN= TAfin();
		matrizN=matrizN.rotateY(90);
		matrizN=matrizN.translated(0,6.5,3);
		nariz->setTransAfin(matrizN);
		muneco.anadeObjetoLista(nariz);

		Objeto3D* botonSuperior= new Disco(0,0.3,20,2);
		TAfin matrizBoS= TAfin();
		matrizBoS=matrizBoS.rotateY(90);
		matrizBoS=matrizBoS.translated(0,4.5,3.4);
		botonSuperior->setTransAfin(matrizBoS);
		muneco.anadeObjetoLista(botonSuperior);

		Objeto3D* botonCentro= new Disco(0,0.3,20,2);
		TAfin matrizBoC= TAfin();
		matrizBoC=matrizBoC.rotateY(90);
		matrizBoC=matrizBoC.translated(0,3,4);
		botonCentro->setTransAfin(matrizBoC);
		muneco.anadeObjetoLista(botonCentro);

		Objeto3D* botonBajo= new Disco(0,0.3,20,2);
		TAfin matrizBoB= TAfin();
		matrizBoB=matrizBoB.rotateY(90);
		matrizBoB=matrizBoB.translated(0,1.5,4);
		botonBajo->setTransAfin(matrizBoB);
		muneco.anadeObjetoLista(botonBajo);

		Objeto3D* bolaBaja = new Esfera(4,20,20);
		TAfin matrizBB = TAfin();
		matrizBB= matrizBB.translated(0,2,0);
		bolaBaja->setTransAfin(matrizBB);
		muneco.anadeObjetoLista(bolaBaja);

		Objeto3D* bolaSuperior = new Esfera (3,20,20);
		TAfin matrizBS= TAfin();
		matrizBS= matrizBS.translated(0,6,0);
		bolaSuperior->setTransAfin(matrizBS);
		muneco.anadeObjetoLista(bolaSuperior);

		

	}
	~MunecoNieve(void)
	{
	}

	void dibuja();

private:
	Sombrero somb;
	ObjetoCompuesto muneco;
};


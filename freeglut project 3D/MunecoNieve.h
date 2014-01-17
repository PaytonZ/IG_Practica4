#pragma once
#include "ObjetoCompuesto.h"
#include "Sombrero.h"
#include "Esfera.h"
#include "Malla.h"

class MunecoNieve
{
public:
	MunecoNieve(void)
	{
		somb= Sombrero();

		muneco= ObjetoCompuesto(11);

		Objeto3D* ojoDer= new Disco(0,0.5,20,2);
		TAfin matrizOD= TAfin();
		matrizOD=matrizOD.rotateY(90);
		matrizOD=matrizOD.translated(1.5,7.5,2.6);
		ojoDer->setTransAfin(matrizOD);
		muneco.anadeObjetoLista(ojoDer);
		ojoDer->setColor(1,0,0.4);

		Objeto3D* ojoDerecho= new Cilindro(0.5,0.5,1.2,20,2);
		TAfin matrizODD= TAfin();
		matrizODD=matrizODD.rotateY(90);
		matrizODD=matrizODD.translated(1.5,7.5,1.4);
		ojoDerecho->setTransAfin(matrizODD);
		muneco.anadeObjetoLista(ojoDerecho);
		ojoDerecho->setColor(1,0,0.4);


		Objeto3D* ojoIzq= new Disco(0,0.5,20,2);
		TAfin matrizIZ= TAfin();
		matrizIZ=matrizIZ.rotateY(90);
		matrizIZ=matrizIZ.translated(-1.5,7.5,2.6);
		ojoIzq->setTransAfin(matrizIZ);
		muneco.anadeObjetoLista(ojoIzq);
		ojoIzq->setColor(1,0,0.4);

		Objeto3D* ojoIzquierdo= new Cilindro(0.5,0.5,1.2,20,2);
		TAfin matrizOII= TAfin();
		matrizOII=matrizOII.rotateY(90);
		matrizOII=matrizOII.translated(-1.5,7.5,1.4);
		ojoIzquierdo->setTransAfin(matrizOII);
		muneco.anadeObjetoLista(ojoIzquierdo);
		ojoIzquierdo->setColor(1,0,0.4);

		Objeto3D* nariz= new Cilindro(0.5,0,3.5,20,2);
		TAfin matrizN= TAfin();
		matrizN=matrizN.rotateY(90);
		matrizN=matrizN.translated(0,6.5,2);
		nariz->setTransAfin(matrizN);
		muneco.anadeObjetoLista(nariz);
		nariz->setColor(0.7,0.35,0);

		Objeto3D* botonSuperior= new Disco(0,0.3,20,2);
		TAfin matrizBoS= TAfin();
		matrizBoS=matrizBoS.rotateY(90);
		matrizBoS=matrizBoS.translated(0,4.5,3.4);
		botonSuperior->setTransAfin(matrizBoS);
		muneco.anadeObjetoLista(botonSuperior);
		botonSuperior->setColor(0,0,0);

		Objeto3D* botonCentro= new Disco(0,0.3,20,2);
		TAfin matrizBoC= TAfin();
		matrizBoC=matrizBoC.rotateY(90);
		matrizBoC=matrizBoC.translated(0,3,4);
		botonCentro->setTransAfin(matrizBoC);
		muneco.anadeObjetoLista(botonCentro);
		botonCentro->setColor(0,0,0);

		Objeto3D* botonBajo= new Disco(0,0.3,20,2);
		TAfin matrizBoB= TAfin();
		matrizBoB=matrizBoB.rotateY(90);
		matrizBoB=matrizBoB.translated(0,1.5,4);
		botonBajo->setTransAfin(matrizBoB);
		muneco.anadeObjetoLista(botonBajo);
		botonBajo->setColor(0,0,0);

		Objeto3D* bolaBaja = new Esfera(4,20,20);
		TAfin matrizBB = TAfin();
		matrizBB= matrizBB.translated(0,2,0);
		bolaBaja->setTransAfin(matrizBB);
		muneco.anadeObjetoLista(bolaBaja);
		bolaBaja->setColor(1,1,1);

		Objeto3D* bolaSuperior = new Esfera (3,20,20);
		TAfin matrizBS= TAfin();
		matrizBS= matrizBS.translated(0,6,0);
		bolaSuperior->setTransAfin(matrizBS);
		muneco.anadeObjetoLista(bolaSuperior);
		bolaSuperior->setColor(1,1,1);

		

		suelo = Malla(8,6,6);
		PV3D* p0 = new PV3D(1,0,0,false);
		PV3D* p1 = new PV3D(0,0,-1,false);
		PV3D* p2 = new PV3D(-1,0,0,false);
		PV3D* p3 = new PV3D(0,0,1,false);
		PV3D* p4 = new PV3D(1,-1,0,false);
		PV3D* p5 = new PV3D(0,-1,-1,false);
		PV3D* p6 = new PV3D(-1,-1,0,false);
		PV3D* p7 = new PV3D(0,-1,1,false);

		suelo.anadirVertice(p0);
		suelo.anadirVertice(p1);
		suelo.anadirVertice(p2);
		suelo.anadirVertice(p3);
		suelo.anadirVertice(p4);
		suelo.anadirVertice(p5);
		suelo.anadirVertice(p6);
		suelo.anadirVertice(p7);

		Cara* c1 = new Cara(4);
		Cara* c2 = new Cara(4);
		Cara* c3 = new Cara(4);
		Cara* c4 = new Cara(4);
		Cara* c5 = new Cara(4);
		Cara* c6 = new Cara(4);

		c1->setValor(0,0,0);
		c1->setValor(1,1,0);
		c1->setValor(2,2,0);
		c1->setValor(3,3,0);
		suelo.anadirNormal(suelo.calculoVectorNormalPorNewell(*c1));
		suelo.anadirCara(c1);

		c2->setValor(0,7,1);
		c2->setValor(1,4,1);
		c2->setValor(2,0,1);
		c2->setValor(3,3,1);
		suelo.anadirNormal(suelo.calculoVectorNormalPorNewell(*c2));
		suelo.anadirCara(c2);

		c3->setValor(0,4,2);
		c3->setValor(1,5,2);
		c3->setValor(2,1,2);
		c3->setValor(3,0,2);
		suelo.anadirNormal(suelo.calculoVectorNormalPorNewell(*c3));
		suelo.anadirCara(c3);

		c4->setValor(0,5,3);
		c4->setValor(1,6,3);
		c4->setValor(2,2,3);
		c4->setValor(3,1,3);
		suelo.anadirNormal(suelo.calculoVectorNormalPorNewell(*c4));
		suelo.anadirCara(c4);

		c5->setValor(0,6,4);
		c5->setValor(1,7,4);
		c5->setValor(2,3,4);
		c5->setValor(3,2,4);
		suelo.anadirNormal(suelo.calculoVectorNormalPorNewell(*c5));
		suelo.anadirCara(c5);

		c6->setValor(0,7,5);
		c6->setValor(1,6,5);
		c6->setValor(2,5,5);
		c6->setValor(3,4,5);
		suelo.anadirNormal(suelo.calculoVectorNormalPorNewell(*c6));
		suelo.anadirCara(c6);

		suelo.setColor(0.5,0.35,0.05);
		TAfin matrizAfinTablero= TAfin();
		matrizAfinTablero= matrizAfinTablero.scaled(8,2,8);
		suelo.setTransAfin(matrizAfinTablero);



	}
	~MunecoNieve(void)
	{
	}

	void dibuja();

private:
	Sombrero somb;
	ObjetoCompuesto muneco;
	Malla suelo;
};


#pragma once
#include "Objeto3D.h"
#include "Lista.h"

class ObjetoCompuesto:
	public Objeto3D
{
public:
	ObjetoCompuesto(){};
	ObjetoCompuesto(int numH)
	{
		numHijos= numH ;
	}
	~ObjetoCompuesto(void)
	{

	}


	virtual void dibuja();
	void anadeObjetoLista(Objeto3D* a);

private:
	int numHijos;
	Lista<Objeto3D*> listaHijos;
};


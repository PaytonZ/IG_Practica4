#include "ObjetoCompuesto.h"
#include <Windows.h>
#include <gl/GL.h>




void ObjetoCompuesto :: dibuja()
{

	//for (int i=0; i < numHijos; i++)
	//{
		Lista<Objeto3D*>::Iterador it = listaHijos.principio();
		while (it!=listaHijos.final())
		{
			Objeto3D* objeto = it.elem();

			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
				glMultMatrixf(objeto->m.matriz);
				objeto->dibuja();
			glPopMatrix();
			it.avanza();
		}
	//}
}

void ObjetoCompuesto :: anadeObjetoLista(Objeto3D* a)
{
	listaHijos.ponDr(a);
}
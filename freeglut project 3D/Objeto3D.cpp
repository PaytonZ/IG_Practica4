#include "Objeto3D.h"

void Objeto3D :: setTransAfin (TAfin matriz)
{
	for (int i=0; i<16; i++)
		m.matriz[i]=matriz.matriz[i];
}

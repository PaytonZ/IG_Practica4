#include "MunecoNieve.h"



void MunecoNieve :: dibuja()
{
	muneco.dibuja();

	somb.dibuja();

	suelo.dibuja();
}

void MunecoNieve :: enciendeOjos()
{
	d.enciendeOjos();
	i.enciendeOjos();
}

void MunecoNieve :: apagaOjos()
{
	d.apagaOjos();
	i.apagaOjos();
}

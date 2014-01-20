#include "Ojos.h"



void Ojos :: dibuja()
{
	glColor3f(r,g,b); 
	ciOjo->dibuja();

	GLfloat d[] = {1.0,1.0,1.0,1.0};
	GLfloat a[] = {0.3,0.3,0.3,1.0};
	GLfloat direcion[] = {20.0, 7.8, 0.0};
	GLfloat angle = 90;
	GLfloat p[4];
	p[0] = 2.5;
	p[1] = 7.5;
	p[3] = 1.0;
	if(esD)
	{
		p[2] = 1.5;
		glLightfv(GL_LIGHT2, GL_AMBIENT, a);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, d);
		glLightfv(GL_LIGHT2, GL_POSITION, p);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION,direcion);
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF,angle);
		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 20.0);
	}
	else
	{
		p[2] = -1.5;
		glLightfv(GL_LIGHT3, GL_AMBIENT, a);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, d);
		glLightfv(GL_LIGHT3, GL_POSITION, p);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION,direcion);
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF,angle);
		glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 20.0);
	}
}

void Ojos :: enciendeOjos()
{
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
}

void Ojos :: apagaOjos()
{
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
}
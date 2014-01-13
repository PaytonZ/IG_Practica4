#pragma once
#include <GL/freeglut.h>
#include "PV3D.h"

class Camara
{
public:
	Camara(){}

	Camara(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble lookX, GLdouble lookY, GLdouble lookZ, 
		GLdouble upX, GLdouble upY, GLdouble upZ, GLdouble N, GLdouble F, GLdouble xRigth, GLdouble xLeft,
		GLdouble yTop, GLdouble yBot)
	{
		eye = new PV3D(eyeX,eyeY,eyeZ,false);
		look = new PV3D(lookX,lookY,lookZ,false);
		up = new PV3D(upX,upY,upZ,true);
		//n = new PV3D(eyeX,eyeY,eyeZ,false);
		
		n = new PV3D((*eye) - (*look).normalizarVector()); 
		u= new PV3D((*up)*(*n).normalizarVector());
		v = new PV3D((*n)*(*u));
		
		near1 = N;
		far1 = F;
		left = xLeft;
		right = xRigth;
		top = yTop;
		bottom = yBot;

		//gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);
		//setModelViewMatrix();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);


	}

	~Camara(void)
	{
		delete eye,look,up,n,u,v;
	}
	 void pitch(GLfloat angulo);
	 void yaw (GLfloat angulo);
	 void roll (GLfloat angulo);
	void inicializaOrto();

private:
	PV3D *eye;  // Punto donde esta la camara
	PV3D *look; // Punto al que mira la camara
	PV3D *up; // Vector que indica cómo está orientada la cámara.
	PV3D *n;
	PV3D *u;
	PV3D *v;
	GLdouble left , right, top , bottom , near1 , far1 , fovy , aspect;
	void setModelViewMatrix();
};


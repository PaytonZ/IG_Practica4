#pragma once
#include <GL/freeglut.h>
#include "PV3D.h"

class Camara
{
public:
	Camara(){}

	Camara(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble lookX, GLdouble lookY, GLdouble lookZ, GLdouble upX, GLdouble upY, GLdouble upZ)
	{
		eye = new PV3D(eyeX,eyeY,eyeZ,false);
		look = new PV3D(lookX,lookY,lookZ,false);
		up = new PV3D(upX,upY,upZ,true);
		n = new PV3D(eyeX,eyeY,eyeZ,false);
		//a = new PV3D();
			
		

	

		//gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);
	}

	~Camara(void)
	{

	}
	 void pitch(GLfloat angulo);
	 void yaw (GLfloat angulo);
	 void roll (GLfloat angulo);

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


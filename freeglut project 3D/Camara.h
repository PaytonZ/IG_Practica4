#pragma once
#include <GL/freeglut.h>
#include "PV3D.h"

class Camara
{
public:
	Camara(){}

	Camara(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, GLdouble lookX, GLdouble lookY, GLdouble lookZ, GLdouble upX, GLdouble upY, GLdouble upZ)
	{
		eye = PV3D(eyeX,eyeY,eyeZ,false);
		look = PV3D(lookX,lookY,lookZ,false);
		up = PV3D(upX,upY,upZ,true);
		n = eye -look;
		n= n.normalizarVector();
		u = up*n;
		u = u.normalizarVector();
		v = n*u;
		setModelViewMatrix();

		//gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);
	}

	~Camara(void)
	{

	}
	 void pitch(GLfloat angulo);
	 void yaw (GLfloat angulo);
	 void roll (GLfloat angulo);

private:
	PV3D eye;  // Punto donde esta la camara
	PV3D look; // Punto al que mira la camara
	PV3D up; // Vector que indica cómo está orientada la cámara.
	PV3D n;
	PV3D u;
	PV3D v;
	void setModelViewMatrix();
};


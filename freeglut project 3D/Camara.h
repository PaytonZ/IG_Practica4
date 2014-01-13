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
		
		PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);
		
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
		anguloX=45;
		anguloY=45;
		anguloZ=45;


	}

	~Camara(void)
	{
		//delete eye,look,up,n,u,v;
	}
	 void pitch(GLfloat angulo);
	 void yaw (GLfloat angulo);
	 void roll (GLfloat angulo);
	 void inicializaOrto();
	 void frontal();
	 void lateral();
	 void cenital();
	 void esquina();
	 void recorridoEje( GLdouble x, GLdouble y, GLdouble z);
	 void giraX(GLdouble angulo);
	 void giraY(GLdouble angulo);
	 void giraZ(GLdouble angulo);

private:
	PV3D *eye;  // Punto donde esta la camara
	PV3D *look; // Punto al que mira la camara
	PV3D *up; // Vector que indica cómo está orientada la cámara.
	PV3D *n;
	PV3D *u;
	PV3D *v;
	GLdouble left , right, top , bottom , near1 , far1 , fovy , aspect, anguloX,anguloY, anguloZ;
	void setModelViewMatrix();
};


/********************************************************************************
*																				*
*		Practica 4 IG - Muñeco Nieve											*
*		Autores:	David Garcia Alvarez										*
*					Juan Luis Perez Valbuena									*
*																				*
*********************************************************************************/

#include "Camara.h"
#include <math.h>



void Camara :: setModelViewMatrix()
{ 
    float m[16]; 
	m[0] =  u->x; m[4] =  u->y; m[8]  =  u->z;  m[12] = -eye->productoEscalar(*u);
	m[1] =  v->x; m[5] =  v->y; m[9]  =  v->z;  m[13] = -eye->productoEscalar(*v);
	m[2] =  n->x; m[6] =  n->y; m[10] =  n->z;  m[14] = -eye->productoEscalar(*n);
    m[3] =  0;   m[7] =  0;   m[11] =  0;    m[15] = 1.0;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(m); 
}


void Camara :: pitch(GLfloat angulo)
{
	float coseno = cos( angulo / 180 * 3.14159265 );
	float seno = sin( angulo / 180 * 3.14159265 );
	PV3D* auxV = v;
	PV3D* auxN = n;

	PV3D newV = (*auxN)*(-seno)+(*auxV)*coseno;
	v = new PV3D(newV.x,newV.y,newV.z,true);

	PV3D newN = (*auxN)*coseno + (*auxV)*seno;
	n = new PV3D(newN.x,newN.y,newN.z,true);

	setModelViewMatrix();
	delete  auxN;
	delete  auxV;
}

void Camara :: roll(float angle)
{ 
	float coseno = cos( angle / 180 * 3.14159265 );
	float seno = sin( angle / 180 * 3.14159265 ); 
	PV3D* auxU = u;
	PV3D* auxV = v;

	PV3D newV = (*v)*coseno - (*u)*seno;
	v = new PV3D(newV.x,newV.y,newV.z,true);

	PV3D newU = (*u)*coseno +(*v)*seno;
	u = new PV3D(newU.x,newU.y,newU.z,true);

	setModelViewMatrix();

	delete  auxU;
	delete  auxV;
}

void Camara :: yaw(float angle)
{ 
	float coseno = cos( angle / 180 * 3.14159265 );
	float seno = sin( angle / 180 * 3.14159265 );
	PV3D* auxN = n; 
	PV3D* auxU = u;

	PV3D newN = (*auxU)*-seno+(*auxN)*coseno;
	n = new PV3D(newN.x,newN.y,newN.z,true);

	PV3D newU = (*auxU)*coseno + (*auxN)*seno;
	u = new PV3D(newU.x,newU.y,newU.z,true);

	setModelViewMatrix();
	delete  auxU;
	delete  auxN;
}


void Camara :: inicializaOrto()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, near1, far1);
}

void Camara :: frontal()
{
		delete eye,look,up,n,u,v;
		eye = new PV3D(100,100,100,false);

		look = new PV3D(0,0,0,false);

		up = new PV3D(0,1,0,true);
		//n = new PV3D(eyeX,eyeY,eyeZ,false);
		
		PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);
		
}

void Camara :: cenital()
{
		delete eye,look,up,n,u,v;
		eye = new PV3D(0,100,0,false);

		look = new PV3D(0,0,0,false);

		up = new PV3D(1,0,0,true);
		
		PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);
}

void Camara :: lateral()
{
		delete eye,look,up,n,u,v;

		eye = new PV3D(100,0,0,false);

		look = new PV3D(0,0,0,false);

		up = new PV3D(0,1,0,true);
		
		PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);
}

void Camara :: esquina()
{
		delete eye,look,up,n,u,v;

		eye = new PV3D(0,0,100,false);

		look = new PV3D(0,0,0,false);

		up = new PV3D(0,1,0,true);
		
		PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);
}

void Camara :: recorridoEje(GLdouble x, GLdouble y, GLdouble z)
{
	delete n,u,v;
	eye->x=eye->x+x;

	if (eye->x>980)
		eye->x=980;
	else if (eye->x<-980)
		eye->x=-980;

	eye->y=eye->y+y;

	if (eye->y>980)
		eye->y=980;
	else if (eye->y<-980)
		eye->y=-980;

	eye->z=eye->z+z;

	if (eye->z>980)
		eye->z=980;
	else if (eye->z<-980)
		eye->z=-980;

	PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);


}

void Camara :: giraX(GLdouble angulo)
{
	delete n,u,v;
	anguloX+=angulo;
	eye->y=eye->x*cos(anguloX / 180 * 3.14159265);


	eye->z=eye->x*sin(anguloX / 180 * 3.14159265);


	PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);

}

void Camara :: giraY(GLdouble angulo)
{
	delete n,u,v;
	anguloY+=angulo;
	eye->x=eye->y*cos(anguloY / 180 * 3.14159265);


	eye->z=eye->y*sin(anguloY / 180 * 3.14159265);


	PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);

}


void Camara :: giraZ(GLdouble angulo)
{
	delete n,u,v;
	anguloZ+=angulo;
	eye->y=eye->z*cos(anguloZ / 180 * 3.14159265);


	eye->x=eye->z*sin(anguloZ / 180 * 3.14159265);


	PV3D auxN =((*eye) - (*look)).normalizarVector();
		n = new PV3D(auxN.x,auxN.y,auxN.z,true); 

		PV3D auxU = ((*up)*(*n)).normalizarVector();
		u= new PV3D(auxU.x,auxU.y,auxU.z,true);

		PV3D auxV = (*n)*(*u);
		v = new PV3D(auxV.x,auxV.y,auxV.z,true);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);

}

void Camara :: iniciaPerspectiva()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(4,1,near1,far1);

}
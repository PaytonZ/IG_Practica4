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
    glLoadMatrixf(m);  // load OpenGL's modelview matrix
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
	/*delete [] auxN;
	delete [] auxV;*/
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

	/*delete [] auxU;
	delete [] auxV;*/
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
	/*delete [] auxU;
	delete [] auxN;*/
}


void Camara :: inicializaOrto()
{
	 glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(left, right, bottom, top, near1, far1);
}


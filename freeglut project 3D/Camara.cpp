#include "Camara.h"
#include <math.h>



void Camara :: setModelViewMatrix()
{ 
    float m[16];
    PV3D eVec(eye.x, eye.y, eye.z, true); 
	m[0] =  u.x; m[4] =  u.y; m[8]  =  u.z;  m[12] = -eVec.productoEscalar(u);
	m[1] =  v.x; m[5] =  v.y; m[9]  =  v.z;  m[13] = -eVec.productoEscalar(v);
	m[2] =  n.x; m[6] =  n.y; m[10] =  n.z;  m[14] = -eVec.productoEscalar(n);
    m[3] =  0;   m[7] =  0;   m[11] =  0;    m[15] = 1.0;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(m);  // load OpenGL's modelview matrix
}


void Camara :: pitch(GLfloat angulo)
{
	float coseno = cos( angulo / 180 * 3.14159265 );
	float seno = sin( angulo / 180 * 3.14159265 );
	PV3D auxV = PV3D (v.x,v.y,v.z,true);
	v = n*-seno+v*coseno;
	v.normalizarVector();
	n = n*coseno + auxV*seno;
	n.normalizarVector();
	setModelViewMatrix();
}

void Camara :: roll(float angle)
{ 
	float coseno = cos( angle / 180 * 3.14159265 );
	float seno = sin( angle / 180 * 3.14159265 ); 
	PV3D auxV = PV3D (v.x,v.y,v.z,true);
	v = u*seno+v*coseno;
	v.normalizarVector();
	u = u*coseno - auxV*seno;
	n.normalizarVector();	
	setModelViewMatrix();
}

void Camara :: yaw(float angle)
{ 
	float coseno = cos( angle / 180 * 3.14159265 );
	float seno = sin( angle / 180 * 3.14159265 );
	PV3D auxN = PV3D (n.x,n.y,n.z,true); 
	n = u*-seno+n*coseno;
	u = u*coseno + auxN*seno;
	setModelViewMatrix();
}


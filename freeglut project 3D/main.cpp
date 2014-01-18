


#include <Windows.h>
#include "PV3D.h"
#include <GL/freeglut.h>
//#include <GL/glut.h>

#include "Camara.h"
#include "TAfin.h"

#include <iostream>

#include "Esfera.h"
#include "MunecoNieve.h"

using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

Camara camara;

Esfera esfe = Esfera(2,2,20);

//Objetos de practica
MunecoNieve munequito;

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);    

    // Light0
    glEnable(GL_LIGHT0);
    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[]={25.0, 25.0, 0.0, 1.0};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);
	glDisable(GL_LIGHT0);

	glEnable(GL_LIGHT1);
	GLfloat p1[]={1.0, 1.0, 0.0, 0};	
	glLightfv(GL_LIGHT1, GL_POSITION, p1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, d);
	glLightfv(GL_LIGHT1, GL_AMBIENT, a);

		
	/** LUZ 2 **/
	
	GLfloat p2[]={2.5, 7.5, 1.5, 1};
	
	glLightf(GL_LIGHT2,GL_SPOT_CUTOFF, 45.0);
	glLightf(GL_LIGHT2,GL_SPOT_EXPONENT,4.0);
	GLfloat dir[]={1,0, 0.0, 0.0};
	glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION, dir);
	glLightfv(GL_LIGHT2, GL_POSITION, p2);
	
	glEnable(GL_LIGHT2);

	/*
	glLightfv(GL_LIGHT2, GL_DIFFUSE, d);
	glLightfv(GL_LIGHT2, GL_AMBIENT, a);
	*/
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// buildSceneObjects();
	camara = Camara(eyeX,eyeY,eyeZ,lookX,lookY,lookZ,upX,upY,upZ,N,F,xRight,xLeft,yTop,yBot);
	
	esfe.setColor(1,1,1);

	munequito = MunecoNieve();

	// Camera set up
	/*glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);*/

	// Frustum set up
	camara.inicializaOrto();

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);        
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	// Drawing axes
	glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);	     
	glEnd();

	//Pintamos los objetos random

	

	

	munequito.dibuja();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glTranslated(5.5,7.5,1.5);
	esfe.dibuja();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;
		case 'p':
			camara.pitch(1); break;
		case 'o':
			camara.pitch(-1); break;
		case 'r':
			camara.roll(1); break;
		case 't':
			camara.roll(-1); break;
		case 'y':
			camara.yaw(1); break;
		case 'u':
			camara.yaw(-1); break;
		case 'f':
			camara.frontal(); break;
		case 'c':
			camara.cenital(); break;
		case 'l':
			camara.lateral();break;
		case 'e':
			camara.esquina();break;
		case '1':
			camara.recorridoEje(10,0,0); break;
		case '2':
			camara.recorridoEje(-10,0,0); break;
		case '3':
			camara.recorridoEje(0,10,0); break;
		case '4':
			camara.recorridoEje(0,-10,0); break;
		case '5':
			camara.recorridoEje(0,0,10); break;
		case '6':
			camara.recorridoEje(0,0,-10); break;
		case 'x':
			camara.giraX(5); break;
		case 'X':
			camara.giraX(-5); break;
		case 'i':
			camara.giraY(5); break;
		case 'I':
			camara.giraY(-5); break;
		case 'z':
			camara.giraZ(5); break;
		case 'Z':
			camara.giraZ(-5); break;
		case 'q':
			glEnable(GL_LIGHT1); break;
		case 'w':
			glDisable(GL_LIGHT1); break;
		/*case 'd':
			glEnable(GL_LIGHT2); break;
		case 'D':
			glDisable(GL_LIGHT2); break;*/
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}

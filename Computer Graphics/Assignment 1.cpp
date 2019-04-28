/*
// ASSIGNMENT 1
//
// PROBLEM STATEMENT
// Write a program to design a graphic image (house)
//
// AUTHOR - Kartik Pingale
*/

#include <iostream>
#include <GL/glut.h>

#define w 640
#define h 480

using namespace std;

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_QUADS);
			glVertex2i(100,100);
      			glVertex2i(200,100);
      			glVertex2i(200,200);
      			glVertex2i(100,200);
		glEnd();
    		glBegin(GL_LINE_LOOP);
			glVertex2i(100,200);
      			glVertex2i(150,250);
      			glVertex2i(200,200);
		glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Display Point");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}

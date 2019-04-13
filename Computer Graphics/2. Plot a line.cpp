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
		glBegin(GL_LINES);
			glVertex2i(100,100);
    		 	glVertex2i(300,300);
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

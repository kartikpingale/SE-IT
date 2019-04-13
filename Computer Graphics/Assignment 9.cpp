#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define w 640
#define h 480

using namespace std;

void koch(float, float, int);

float oldX=0.0, oldY=0.0;

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int n;
	cout << "Enter no. of iterations: ";
	cin >> n;

	glBegin(GL_LINES);

		koch(0.0, 0.05, n);
		koch(-120.0, 0.05, n);
		koch(120.0, 0.05, n);

		glEnd();
	glFlush();
}

void koch(float dir, float len, int n)
{
	double dirRad=(3.14/180)*dir;
	float newX=oldX+len*cos(dirRad);
	float newY=oldY+len*sin(dirRad);
	if(n==0)
	{
		glVertex2f(oldX, oldY);
		glVertex2f(newX, newY);
		oldX=newX;
		oldY=newY;
	}
	else
	{
		n--;
		koch(dir, len, n);
		dir+=60;
		koch(dir, len, n);
		dir-=120;
		koch(dir, len, n);
		dir+=60;
		koch(dir, len, n);
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Koch Curve");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}

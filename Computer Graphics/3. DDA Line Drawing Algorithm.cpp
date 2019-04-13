#include <iostream>
#include <GL/glut.h>

#define w 640
#define h 480

using namespace std;

void DDAline(float x0, float y0, float x1, float y1);
void plot(float x, float y);
int abs(float n);

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

void myDisplay()
{
	float x0, y0, x1, y1;
	cout << "Enter first point: ";
	cin >> x0 >> y0;
	cout << "Enter second point: ";
	cin >> x1 >> y1;

	glClear(GL_COLOR_BUFFER_BIT);
		DDAline(x0, y0, x1, y1);
	glFlush();
}

void DDAline(float x0, float y0, float x1, float y1)
{
	float dx, dy, incx, incy, x, y;
	int steps, i;

	x=x0;
	y=y0;

	dx=x1-x0;
	dy=y1-y0;

	if(abs(dx) > abs(dy))
	{
		steps=dx;
	}
	else
	{
		steps=dy;
	}

	incx=dx/steps;
	incy=dy/steps;

	for(i=0; i<steps; i++)
	{
		plot(x,y);
		x=x+incx;
		y=y+incy;
	}
}

void plot(float x, float y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

int abs(float n)
{
	int ret;
	if(n<0.0)
	{
		ret=-1*n;
		return ret;
	}
	else if(n>0.0)
	{
		ret=n;
		return ret;
	}
	else
	{
		return 0;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA Line Drawing Algorithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}

#include <iostream>
#include <GL/glut.h>

#define w 640
#define h 480

using namespace std;

void DDAline(float x0, float y0, float x1, float y1);
void plot(float x, float y);
int abs(float n);
void drawPolygon();

int a[30][3], k=0, c;

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
	glClear(GL_COLOR_BUFFER_BIT);
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
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}

	incx=dx/steps;
	incy=dy/steps;
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0; i<steps; i++)
	{
		plot(x,y);
		x=x+incx;
		y=y+incy;
	}
	glFlush();
}

void plot(float x, float y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

int abs(float n)
{
    return ( (n>0.0) ? n : ( n * (-1)));
}

void menu(int item)
{
	if(item==1)
	{
		glColor3f(0.0, 0.0, 0.0);
	}
	if(item==2)
	{
		glColor3f(1.0, 0.0, 0.0);
	}
	if(item==3)
	{
		glColor3f(0.0, 1.0, 0.0);
	}
	if(item==4)
	{
		glColor3f(0.0, 0.0, 1.0);
	}
}

void mouseClick(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			a[k][0]=(float)(x);
			a[k][1]=(float)(480-y);

			glBegin(GL_POINTS);
				glVertex2f(a[k][0],a[k][1]);
			glEnd();
			k++;
			glFlush();
		}

		if(button==GLUT_RIGHT_BUTTON)
		{
			drawPolygon();
			c=k;
			k=0;
			glFlush();
		}
	}
}

void drawPolygon()
{
	int i;
	for(i=0;i<k;i=i+2)
	{
		DDAline(a[i][0], a[i][1], a[i+1][0], a[i+1][1]);
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
	glutMouseFunc(mouseClick);
	myInit();
	glutCreateMenu(menu);
	glutAddMenuEntry("Black", 1);
	glutAddMenuEntry("Red", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Blue", 4);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();
	return 0;
}

/*
// ASSIGNMENT 5
//
// PROBLEM STATEMENT
// Draw a 4x4 chessboard, rotate it by 45 degrees. Use Bresenham's line drawing algorithm and seed-fill algorithm
//
// AUTHOR - Kartik Pingale
*/

#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define w 640
#define h 480
using namespace std;

float boundaryColor[3]={1,0,0},interiorColor[3]={0,0,0},fillColor[3]={1,1,1},readpixel[3];
int X,Y;

void setpixel(int x,int y)
{
	glColor3f(1,1,1);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}
void getpixel(int x,int y,float *color)
{
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}

void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

int sign(int n)
{
	if(n<0)
	return -1;

	if(n>0)
	return 1;

	else
	return 0;
}

void floodfill(int x,int y)
{
	getpixel(x,y,readpixel);
	if(readpixel[0]==interiorColor[0] && readpixel[1]==interiorColor[1] && readpixel[2]==interiorColor[2])
	{
		setpixel(x,y);
		floodfill(x+1,y);
		floodfill(x,y+1);
		floodfill(x-1,y);
		floodfill(x,y-1);
	}
}

void plot(GLint x,GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void simple(float x1,float y1,float x2,float y2)
{

	float x,y,Dx,Dy,e,temp;
	int s1,s2,interchange,i;
	x=x1;
	y=y1;

	Dx=abs(x2-x1);
	Dy=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);

	if(Dy>Dx)
	{
		temp=Dx;
		Dx=Dy;
		Dy=temp;
		interchange=1;
	}

	else
	interchange=0;

	e=2*Dy-Dx;

	for(i=1;i<=Dx;i++)
	{
		plot(x,y);

		while(e>=0)
		{
			if(interchange==1)
			x=x+s1;

			else
			{
				y=y+s2;
			}

			e=e-2*Dx;
		}

		if(interchange==1)
		y=y+s2;

		else
		{
			x=x+s1;
		}

		e=e+2*Dy;
	}
}

void rotation(int x1,int y1,int x2,int y2)
{
	float angle;
	int x3,y3,x4,y4;
	angle=(3.14*45)/180;

	x3=x1*cos(angle)+y1*sin(-angle);
	y3=x1*sin(angle)+y1*cos(angle);
	x4=x2*cos(angle)+y2*sin(-angle);
	y4=x2*sin(angle)+y2*cos(angle);

	simple(x3,y3,x4,y4);
}

void mouseClick(int button,int state,int x,int y)
{
	if(state==GLUT_DOWN && button==GLUT_RIGHT_BUTTON)
	{
		X=x;
		Y=480-y;
		floodfill(X,Y);
	}
}

void myDisplay()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	simple(300,100,402,100);
	simple(400,100,400,200);
	simple(400,200,300,200);
	simple(300,200,300,100);
	simple(325,100,325,200);
	simple(350,100,350,200);
	simple(375,100,375,200);
	simple(400,100,400,200);
	simple(300,125,400,125);
	simple(300,150,400,150);
	simple(300,175,400,175);
	simple(300,200,400,200);

	rotation(300,100,402,100);
	rotation(400,100,400,200);
	rotation(400,200,300,200);
	rotation(300,200,300,100);
	rotation(325,100,325,200);
	rotation(350,100,350,200);
	rotation(375,100,375,200);
	rotation(400,100,400,200);
	rotation(300,125,400,125);
	rotation(300,150,400,150);
	rotation(300,175,400,175);
	rotation(300,200,400,200);

	glEnd();
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640.0,480.0);
	glutInitWindowPosition(100.0,50.0);
	glutCreateWindow("Chess");
	glutMouseFunc(mouseClick);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

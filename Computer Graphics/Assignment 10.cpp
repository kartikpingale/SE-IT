/*
// ASSIGNMENT 10
//
// PROBLEM STATEMENT
// Design an animation sequence (flag hoisting)
//
// AUTHOR - Kartik Pingale
*/

#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define w 500
#define h 500

using namespace std;
int f, c;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
}

class anim
{
public:
	int a[10][2];
	void plot(int x, int y);
	void flag();
	void translate();
	void circle(int y,int x,int k);
	anim()
	{
		a[0][0] = 10;
		a[0][1] = 10;
		a[1][0] = 200;
		a[1][1] = 10;
		a[2][0] = 200;
		a[2][1] = 100;
		a[3][0] = 10;
		a[3][1] = 100;
		a[4][0] = 10;
		a[4][1] = 40;
		a[5][0] = 200;
		a[5][1] = 40;
		a[6][0] = 10;
		a[6][1] = 70;
		a[7][0] = 200;
		a[7][1] = 70;
		a[8][0] = 105;
		a[8][1] = 55;
	}
};

anim a;

void anim::circle(int r,int h1,int k)
{
	float d=3-2*r;
	float x=0;
	float y=r;
	while(x<y)
	{
		if(d<0)
		{
			d=d+4*x+6;
			x=x+1;
		}
		else
		{
			d=d+4*(x-y)+10;
			x=x+1;
			y=y-1;
		}
		plot(x+h1,y+k);
		plot(y+h1,x+k);
		plot(-y+h1,x+k);
		plot(-x+h1,y+k);
		plot(-x+h1,-y+k);
		plot(-y+h1,-x+k);
		plot(y+h1,-x+k);
		plot(x+h1,-y+k);
	}
}

void anim::flag()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
    glVertex2f(a[0][0],a[0][1]);
	glVertex2f(a[1][0],a[1][1]);
	glVertex2f(a[2][0],a[2][1]);
	glVertex2f(a[3][0],a[3][1]);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(10,10);
	glVertex2f(10,500);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(a[4][0],a[4][1]);
	glVertex2f(a[5][0],a[5][1]);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1.0,0.5,0.0);
	glVertex2f(a[6][0],a[6][1]);
	glVertex2f(a[7][0],a[7][1]);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	circle(15,a[8][0],a[8][1]);
    glEnd();
	glFlush();
}

void anim::translate()
{
	if(a[3][1] == 100)
		f = 1;
	if(a[3][1] == 500)
		f = -1;
	if(f == 1)
		c = 5;
	if(f == -1)
		c = -5;

	a[0][1] += c;
	a[1][1] += c;
	a[2][1] += c;
	a[3][1] += c;
	a[4][1] += c;
	a[5][1] += c;
	a[6][1] += c;
	a[7][1] += c;
	a[8][1] += c;
}

void anim::plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void timer(int time)
{
	glutPostRedisplay();
	glutTimerFunc(time,timer,time);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	a.flag();
	a.translate();
	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(300,300);
	glutCreateWindow("Animation");
	timer(10);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}

/*
// ASSIGNMENT 3
//
// PROBLEM STATEMENT
// Draw inscribed & circumscribed circles in triangle
//
// AUTHOR - Kartik Pingale
*/

#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define w 750
#define he 750

using namespace std;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(3.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w,w,-he,he);
}

void plot(float x,float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

int sign(float val)
{
	if(val<0)
	{
		return (-1);
	}
	if(val>0)
	{
		return (1);
	}
	if(val==0)
	{
		return (0);
	}
}

void setpixel(GLint x,GLint y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void Circle1(float r,float h,float k)
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
		plot(x+h,y+k);
		plot(y+h,x+k);
		plot(-y+h,x+k);
		plot(-x+h,y+k);
		plot(-x+h,-y+k);
		plot(-y+h,-x+k);
		plot(y+h,-x+k);
		plot(x+h,-y+k);
	}
}

void Circle2(float r,float h,float k)
{
	float x=0,y=0;
	x=h;
	y=k;
	int i;
	for(i=0;i<360;i++)
	{
		x=h+r*cos(i*3.142/180);
		y=k+r*sin(i*3.142/180);
		plot(x,y);
	}
}

void Circle3(float r,float h,float k)
{
	float x=0;
	float y=r;
	float p=1-r;
	while(x<=y)
	{
		plot(x+h,y+k);
		plot(y+h,x+k);
		plot(-y+h,x+k);
		plot(-x+h,y+k);
		plot(-x+h,-y+k);
		plot(-y+h,-x+k);
		plot(y+h,-x+k);
		plot(x+h,-y+k);
		if(p<0)
		{
			p=p+2*x+3;
		}
		else
		{
			p=p+2*(x-y)+5;
			y--;
		}
		x++;
	}
}

void spiral1(float r,float h,float k)
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
		plot(x+h,y+k);
		plot(y+h,x+k);
		plot(-y+h,x+k);
		plot(-x+h,y+k);
	}
}

void spiral2(float r,float h,float k)
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
		plot(-x+h,-y+k);
		plot(-y+h,-x+k);
		plot(y+h,-x+k);
		plot(x+h,-y+k);
	}
}

void Lines(float x1,float y1,float x2,float y2)
{
	int length;
	float a1=abs(x2-x1);
	float a2=abs(y2-y1);
	if(a1>=a2)
	{
		length=a1;
	}
	else
	{
		length=a2;
	}
	float dx=(x2-x1)/length;
	float dy=(y2-y1)/length;
	float lar;
	if(dx>dy)
	{
		lar=dx;
	}
	else
	{
		lar=dy;
	}
	float x,y;
	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);
	int i=1;
	while(i<=length)
	{
		plot(x,y);
		x=x+dx;
		y=y+dy;
		i++;
	}
}

void menu(int choice)
{
	int n,i;
	if(choice==1)
	{
		Circle1(200,0,0);
	}
	else if(choice==2)
	{
		Circle2(200,0,0);
	}
	else if(choice==3)
	{
		Circle3(200,0,0);
	}
	else if(choice==4)
	{
		Circle1(100,300,200);
		Circle1(100,450,200);
		Circle1(100,230,300);
		Circle1(100,370,300);
		Circle1(100,510,300);
	}
	else if(choice==5)
	{
		Circle1(0, 0, 100);
		Circle1(0, 0, 150);
		Circle1(0, 0, 200);
	}
	else if(choice==6)
	{
		int l,i;
		cout<<"Enter the number of loops:";
		cin>>l;
		for(i=1;i<=l;i++)
		{
			if(i%2==0)
			{
				spiral1(i*50,50,0);
			}
			else
			{
				spiral2(i*50,100,0);
			}
		}

	}
	else if(choice==7)
	{
		Lines(50,50,550,50);
		Lines(550,50,300,480);
		Lines(300,480,50,50);
		Circle1(144,300,194);
		//Circle1(289,300,194);
	}
	else if(choice==8)
	{
		exit(0);
	}
}

void myDisplay(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for(i=-w;i<=w;i+=2)
	{
		setpixel(i,0);
		setpixel(0,i);
	}
	glEnd();
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,50);
	glutCreateWindow("CIRCLE");
	glutDisplayFunc(myDisplay);
	myInit();
	glutCreateMenu(menu);
	glutAddMenuEntry("Circle 1 (Bresenham)",1);
	glutAddMenuEntry("Circle 2 (DDA)",2);
	glutAddMenuEntry("Circle 3 (Mid-Point)",3);
	glutAddMenuEntry("Olympic rings",4);
	glutAddMenuEntry("Concentric Circle",5);
	glutAddMenuEntry("Spiral",6);
	glutAddMenuEntry("Shape",7);
	glutAddMenuEntry("Exit",8);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

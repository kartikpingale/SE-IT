/*
// ASSIGNMENT 7
//
// PROBLEM STATEMENT
// Implement 2D transformation on triangle & rhombus
//
// AUTHOR - Kartik Pingale
*/

#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define w 500
#define h 500
using namespace std;

int xc,yc,count=0,c;
int a[30][3];
int k=0;
float user_mat[5][5],mat[5][5];

void myInit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glPointSize(1.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

void mul(float a[][5],float b[][5],float mat[][5])
{
	int sum=0,i,j,k;

	for(i=0;i<c;i++)
	{
		for(j=0;j<3;j++)
		{
			mat[i][j]=0;
			for(k=0;k<3;k++)
			{
				mat[i][j] += a[i][k] * b[k][j];
			}
		}
	}

}

void plotp(float mat[][5])
{
	int i;
	glColor3f(1.0,0.0,0.0);

	glBegin(GL_LINE_LOOP);
	for(i=0;i<c;i++)
		glVertex2i(mat[i][0],mat[i][1]);

	glEnd();
	glFlush();
}

void setpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void plot(float x,float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

void mouseClick(int button,int state,int x,int y)
{

	int i;

	if(state==GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			a[k][0]=(float)(x-250);
			a[k][1]=(float)(250-y);

			glBegin(GL_POINTS);
			glVertex2f(a[k][0],a[k][1]);
			glEnd();
			k++;
			glFlush();

		}

		if(button==GLUT_RIGHT_BUTTON)
		{
			glBegin(GL_LINE_LOOP);

			for(i=0;i<k;i++)
				glVertex2f(a[i][0],a[i][1]);

			glEnd();
			c=k;
			k=0;
			glFlush();
		}
	}
}

void myDisplay()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	int i;
	for(i=-w;i<=w;i++)
	{
		setpixel(i,0);
		setpixel(0,i);
	}

	glEnd();
	glFlush();
}

void translate(GLint Tx,GLint Ty)
{
	float tr[5][5];
	int i;

	tr[0][0]=1;
	tr[0][1]=0;
	tr[0][2]=0;
	tr[1][0]=0;
	tr[1][1]=1;
	tr[1][2]=0;
	tr[2][0]=Tx;
	tr[2][1]=Ty;
	tr[2][2]=1;

	for(i=0;i<c;i++)
	{
		user_mat[i][0]=a[i][0];
		user_mat[i][1]=a[i][1];
		user_mat[i][2]=1;
	}

	mul(user_mat,tr,mat);
	plotp(mat);
}

void scaling(GLint Sx,GLint Sy)
{
	int i,j;
	float sc[5][5];

	for(i=0;i<c;i++)
		for(j=0;j<c;j++)
			sc[i][j]=0;


	sc[0][0]=Sx;
	sc[1][1]=Sy;
	sc[2][2]=1;



	for(i=0;i<c;i++)
	{
		user_mat[i][0]=a[i][0];
		user_mat[i][1]=a[i][1];
		user_mat[i][2]=1;
	}

	mul(user_mat,sc,mat);
	plotp(mat);

}

void rotation()
{
	float angle,ro[5][5];
	int i,ch;

	cout<<"1.Clockwise Rotation,2.AntiClockwise Rotation : \n";
	cin>>ch;

	cout<<"\nEnter roation Angle : ";
	cin>>angle;

	angle=(3.14*angle)/180;

	if(ch==1)
	{
		ro[0][0]=cos(angle);
		ro[0][1]=-sin(angle);
		ro[0][2]=0;
		ro[1][0]=sin(angle);
		ro[1][1]=cos(angle);
		ro[1][2]=0;
		ro[2][0]=0;
		ro[2][1]=0;
		ro[2][2]=1;
	}

	else
	{
		ro[0][0]=cos(angle);
		ro[0][1]=sin(angle);
		ro[0][2]=0;
		ro[1][0]=-sin(angle);
		ro[1][1]=cos(angle);
		ro[1][2]=0;
		ro[2][0]=0;
		ro[2][1]=0;
		ro[2][2]=1;
	}


	for(i=0;i<c;i++)
	{
		user_mat[i][0]=a[i][0];
		user_mat[i][1]=a[i][1];
		user_mat[i][2]=1;
	}

	mul(user_mat,ro,mat);
	plotp(mat);
}

void reflection()
{
	int ch,i,j;
	GLfloat ref[5][5];

	cout<<"\n1.Reflection about X axis\n2.Reflection about Y axis\n3.Reflection about Origin\n4.Reflection about line x=y";
	cout<<"\nEnter your choice:";
	cin>>ch;

	for(i=0;i<c;i++)
	{
		user_mat[i][0]=a[i][0];
		user_mat[i][1]=a[i][1];
		user_mat[i][2]=1;
	}

	for(i=0;i<c;i++)
		for(j=0;j<c;j++)
			ref[i][j]=0;

	if(ch==1)
	{
		ref[0][0]=1;
		ref[1][1]=-1;
		ref[2][2]=1;

		mul(user_mat,ref,mat);
		plotp(mat);
	}

	if(ch==2)
	{
		ref[0][0]=-1;
		ref[1][1]=1;
		ref[2][2]=1;

		mul(user_mat,ref,mat);
		plotp(mat);
	}

	if(ch==3)
	{
		ref[0][0]=-1;
		ref[1][1]=-1;
		ref[2][2]=1;

		mul(user_mat,ref,mat);
		plotp(mat);
	}

	if(ch==4)
	{
		ref[0][1]=1;
		ref[1][0]=1;
		ref[2][2]=1;

		mul(user_mat,ref,mat);
		plotp(mat);
	}
}

void shear()
{
	int ch,i;
	float sh[30][5],xs,ys;
	cout<<"\n1.X-Shear\n2.Y-Shear";
	cout<<"\nEnter your choice : ";
	cin>>ch;

	for(i=0;i<c;i++)
	{
		user_mat[i][0]=a[i][0];
		user_mat[i][1]=a[i][1];
		user_mat[i][2]=1;
	}

	if(ch==1)
	{
		cout<<"\nEnter X shear factor : ";
		cin>>xs;
		sh[0][0]=1;
		sh[0][1]=0;
		sh[0][2]=0;
		sh[1][0]=xs;
		sh[1][1]=1;
		sh[1][2]=0;
		sh[2][0]=0;
		sh[2][1]=0;
		sh[2][2]=1;
		mul(user_mat,sh,mat);
		//translate();
		plotp(mat);
	}
	if(ch==2)
	{
		cout<<"Enter Y shear factor : ";
		cin>>ys;
		sh[0][0]=1;
		sh[0][1]=ys;
		sh[0][2]=0;
		sh[1][0]=0;
		sh[1][1]=1;
		sh[1][2]=0;
		sh[2][0]=0;
		sh[2][1]=0;
		sh[2][2]=1;
		mul(user_mat,sh,mat);
		plotp(mat);
	}
}

void menu(int item)
{
	GLint Tx,Ty;

	if(item==1)
	{
		cout<<"\nEnter Translation Factor(x) : ";
		cin>>Tx;

		cout<<"\nEnter Translation Factor(y) : ";
		cin>>Ty;

		translate(Tx,Ty);

	}
	if(item==2)
	{
		cout<<"\nEnter Scale Factor(x) : ";
		cin>>Tx;

		cout<<"\nEnter Scale Factor(y) : ";
		cin>>Ty;

		scaling(Tx,Ty);

	}
	if(item==3)
	{
		rotation();
	}

	if(item==4)
	{
		reflection();
	}

	if(item==5)
	{
		shear();
	}

	if(item==6)
	{
		exit(0);
	}
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100.0,50.0);
	glutCreateWindow("Transformation");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouseClick);
	glutCreateMenu(menu);
	glutAddMenuEntry("Translation",1);
	glutAddMenuEntry("Scaling",2);
	glutAddMenuEntry("Rotation",3);
	glutAddMenuEntry("Reflection",4);
	glutAddMenuEntry("Shear",5);
	glutAddMenuEntry("Exit",6);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	myInit();
	glutMainLoop();
	return 0;
}

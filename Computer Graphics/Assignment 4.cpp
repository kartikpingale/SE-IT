/*
// ASSIGNMENT 4
//
// PROBLEM STATEMENT
// Draw a pattern using Bresenham's line drawing algorithm
//
// AUTHOR - Kartik Pingale
*/

#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
#define w 640

int sign(int no)
{
  if(no<0)
   return -1;
   else if(no>0)
     return 1;
     else
      return 0;
}

void plot(int x,int y)
{
  glBegin(GL_POINTS);
   glVertex2i(x,y);
   glEnd();
   glFlush();
}


void bresenhams(int x1,int y1,int x2,int y2)
{
 int Interchange,i;
	float x,y,dx,dy,s1,s2,temp;
		
	x=x1;
	y=y1;
	dx=abs(x2-x1);
	dy=abs(y1-y2);
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	if(dy>=dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		Interchange=1;
	}
	else
	{
		Interchange=0;
	}
	float e=2*dy-dx;
	for(i=0;i<=dx;i++)
	{
		plot(x,y);
		while(e>=0)
		{
			if(Interchange==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
			e=e-2*dx;
		}
		if(Interchange==1)
		{
			y=y+s2;
		}
		else
		{
			x=x+s1;
		}
		e=e+2*dy;
	
	}
}   
   
   void Dash()
{
  int length,i=1;
  float x,y,Dx,Dy;
  float x1,x2,y1,y2;
    cout<<"Enter the starting points\n";
    cin>>x1>>y1;
    cout<<"Enter the end points\n";
    cin>>x2>>y2;

  
  
  if(round(x2-x1) >= round(y2-y1))
   {
     length = round(x2-x1);
     }
     else
     {
       length = round(y2-y1);
     }
          
  Dx=(x2-x1)/length;
  Dy=(y2-y1)/length;
  
  x= x1 + (0.5*sign(Dx));
  y= y1 + (0.5*sign(Dy));
  
   while(i<=length)
   {
     if(i%4 == 0)
      {
       //plot(int(x),int (y));
       x=x+Dx;
       y=y+Dy;
       i++;
      } 
    else
     {
       plot(int(x),int (y));

       x=x+Dx;
       y=y+Dy;
       i++;
     }
   }
}

void Dotted()
{
  int length,i=1;
  float x,y,Dx,Dy;
 float x1,x2,y1,y2;
    cout<<"Enter the starting points\n";
    cin>>x1>>y1;
    cout<<"Enter the end points\n";
    cin>>x2>>y2;

  
  
  if(round(x2-x1) >= round(y2-y1))
   {
     length = round(x2-x1);
     }
     else
     {
       length = round(y2-y1);
     }
          
  Dx=(x2-x1)/length;
  Dy=(y2-y1)/length;
  
  x= x1 + (0.5*sign(Dx));
  y= y1 + (0.5*sign(Dy));
  
   while(i<=length)
   {
     if(i%4 == 0)
      {
       plot(int(x),int (y));
      }
       x=x+Dx;
       y=y+Dy;
       i++;
   } 
}

  void pattern()
  {
    glColor3f(0.0f, 150.0f, 0.0f);
     bresenhams(100,100,300,100);
     bresenhams(100,100,100,200);
     bresenhams(100,200,300,200);
     bresenhams(300,100,300,200);
    glColor3f(255.0f, 0.0f, 0.0f); 
     bresenhams(100,150,200,200);
     bresenhams(200,100,100,150);
     bresenhams(200,100,300,150);
     bresenhams(200,200,300,150);
       
    glColor3f(50.0f, 50.0f, 0.0f); 
     bresenhams(150,125,150,175);
     bresenhams(150,175,250,175);
     bresenhams(250,175,250,125);
     bresenhams(250,125,150,125);
     /*bresenhams();
     bresenhams();
     bresenhams();
     bresenhams();*/
  }    
void myInit(void)
{
	glClearColor(0.0,0.0, 50.0, 0.0);
	glColor3f(255.0f, 255.0f, 255.0f);
	glPointSize(2.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2, w/2,-w/2,w/2);
}

 void axis()
 {
   int i;
    
     for(i = -w;i<w;i++)
      {
        plot(w/2,w);
        plot(w,w/2);
      }
  }
  
 void menu(int item)
 {
 
   if(item==1)
   {
     bresenhams(100,200,300,400);
     }
    else if(item==2)
     {
       Dotted();
       }
    else if(item==3)
     {
       Dash();
       }
    else if(item==4)
     { 
       pattern();
       }
      else
        exit(0);
  }   
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
     
    axis();
     
       //bresenhams(100,200,300,400);
		 glEnd();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(840,100);
	glutCreateWindow("My First Attempt");
	glutDisplayFunc(myDisplay);
	glutCreateMenu(menu);
	glutAddMenuEntry("Solid line",1);
	glutAddMenuEntry("Dotted line",2);
	glutAddMenuEntry("Dash line",3);
	glutAddMenuEntry("Pattern",4);
	glutAddMenuEntry("Exit",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	myInit();
	glutMainLoop();
}

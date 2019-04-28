/*
// ASSIGNMENT 8
//
// PROBLEM STATEMENT
// Implement cube rotation about vertical axis passing through it's centroid
//
// AUTHOR - Kartik Pingale
*/

#include<GL/glut.h>
#include<iostream>
using namespace std;

GLfloat rot=90 ;//rotation angle

void display_func()
{
/*Matrix for the vertices of Cubes*/
	 GLfloat vert[][4]={
		{ 1.0,  1.0,  1.0},
		{-1.0,  1.0,  1.0},
		{-1.0, -1.0,  1.0},
		{ 1.0, -1.0,  1.0},
		{ 1.0,  1.0, -1.0},
		{-1.0,  1.0, -1.0},
		{-1.0, -1.0, -1.0},
		{ 1.0, -1.0, -1.0},
	};
	/*Matrix for the color of sides of Cubes*/
	 GLfloat color[][4]={
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 1.0, 1.0, 0.0},
		{1.0, 0.0, 1.0, 0.0},
		{1.0, 1.0, 0.0, 0.0},
	};

    glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//
	glPushMatrix();//push on stack
    glTranslatef(0.0, 0.0, -15.0); //move
	glRotatef(rot, 0.0, 1.0, 0.0); //rotation

	glTranslatef(0.0, 0.0, -5.0); //move
	glRotatef(rot*2, 1.0, 0.0, 0.0); //rotation

	glBegin(GL_QUADS);
		glColor3fv(color[0]);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[1]);
		glVertex3fv(vert[2]);
		glVertex3fv(vert[3]);

		glColor3fv(color[1]);
		glVertex3fv(vert[4]);
		glVertex3fv(vert[5]);
		glVertex3fv(vert[6]);
		glVertex3fv(vert[7]);

		glColor3fv(color[2]);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[1]);
		glVertex3fv(vert[5]);
		glVertex3fv(vert[4]);

		glColor3fv(color[3]);
		glVertex3fv(vert[2]);
		glVertex3fv(vert[3]);
		glVertex3fv(vert[7]);
		glVertex3fv(vert[6]);

		glColor3fv(color[4]);
		glVertex3fv(vert[3]);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[4]);
		glVertex3fv(vert[7]);

		glColor3fv(color[5]);
		glVertex3fv(vert[1]);
		glVertex3fv(vert[2]);
		glVertex3fv(vert[6]);
		glVertex3fv(vert[5]);

	glEnd();
	glPopMatrix();	//pop out stack
      glFlush();
	glutSwapBuffers();
}

void reshape_func(int width, int height)
{

	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 5000.0);//Perspective projection
}

void idle_func(void)
{
	rot=(90*3.142)/180;
	rot=0.05*(GLfloat)glutGet(GLUT_ELAPSED_TIME); //Returns the amount of time (in milliseconds) from the time you call the () glutInit.
     glutPostRedisplay(); //re-draw the screen glut
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(300,300);
	glutCreateWindow("cuberotate");
	glutDisplayFunc(display_func);
	glutReshapeFunc(reshape_func);
	glutIdleFunc(idle_func);
	glutMainLoop();
	return 0;
}

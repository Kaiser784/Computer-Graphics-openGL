#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
#include "math.h"
#include "string.h"
#define PI 3.14159265f

void initGL() {
   glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}


void circle1(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 200; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {

			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			        y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void circle2(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 200; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f,  0.0f, 0.0f);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			        y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void display()
{   
    glClear(GL_COLOR_BUFFER_BIT);

    //0
    glBegin(GL_QUADS);
        glColor3ub(rand()%255, rand()%255, rand()%255); 
        glVertex2f(-0.75, 0.35);
        glVertex2f(-0.75, -0.35); 
        glVertex2f(-0.25, -0.35);
        glVertex2f(-0.25, 0.35);

    glEnd();

    circle1(-0.50, 0.35, 0.25);
    circle1(-0.50, -0.35, 0.25);

    glBegin(GL_QUADS);      
        glColor3ub(0, 0, 0); 
        glVertex2f(-0.65, 0.30);
        glVertex2f(-0.65, -0.30); 
        glVertex2f(-0.35, -0.30);
        glVertex2f(-0.35, 0.30);

    glEnd();

    circle1(-0.50, 0.30, 0.15);
    circle1(-0.50, -0.30, 0.15);

    //2
    glColor3ub(rand()%255, rand()%255, rand()%255);
    circle1(0.30, 0.20, 0.40);
    glBegin(GL_QUADS);      
        glVertex2f(0.05, 0.00);
        glVertex2f(0.05, -0.50); 
        glVertex2f(0.25, -0.50);
        glVertex2f(0.25, 0.00);

        glVertex2f(0.05, -0.60);
        glVertex2f(0.05, -0.45); 
        glVertex2f(0.70, -0.45);
        glVertex2f(0.70, -0.60);

    glEnd();

    circle2(0.21, 0.20, 0.35);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        initGL();
        display();
        break;

    case 32:
        initGL();
        display();
        break;

    default:
        break;
    }
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON)
    {
        display();
    }

    if(button == GLUT_RIGHT_BUTTON)
    {
        display();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080,1080);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Interactive 02 Numbers");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    initGL();
    glutMainLoop();

    return 0;
}
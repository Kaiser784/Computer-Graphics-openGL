#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f

float xmin = 300, ymin = 300, xmax = 900, ymax = 600;


void myinit(void)
{
    glClearColor(0,0,0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1000, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void illuminate(float x, float y)
{
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

void display() 
{   
    int xx, yx;
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);
    glColor3f(0, 1, 0);

    



    glFlush();
}

void Mouse(int button, int state, int x, int y){
   display();
}

int main(int argc, char **argv)
{   
    srand(time(0));
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Polygon Clipping");
	myinit();
	glutDisplayFunc(display);
    glutMouseFunc(Mouse);

	glutMainLoop();

	return 0;
}

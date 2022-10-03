#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f

float xmin = 300, ymin = 300, xmax = 900, ymax = 600;

const int TOP = 1;
const int BOTTOM = 2;
const int RIGHT = 4;
const int LEFT = 8;

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

void drawClippingWindow()
{   
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
        glColor3f(1, 1, 1);
        glVertex2f(xmin, ymin);
        glVertex2f(xmin, ymax);
        glVertex2f(xmax, ymax);
        glVertex2f(xmax, ymin);
    glEnd();
}

void PointClip()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    int x, y;
    drawClippingWindow();
    for (int i = 0; i < 400; i++)
    {
        x = rand() % 1000;
        y = rand() % 1000;

        //all points are green
        glColor3f(0, 1, 0);
        glPointSize(2);
        illuminate(x, y);

        //if inside window red
        glColor3f(1, 0, 0);
        glPointSize(2);
        if (x >= xmin && x <= xmax)
            if (y >= ymin && y <= ymax)
                illuminate(x, y);
    }

    glFlush();
}



int main(int argc, char **argv)
{   
    srand(time(0));
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Point Clipping");
	myinit();
	glutDisplayFunc(PointClip);

	glutMainLoop();

	return 0;
}

#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
#include "math.h"
#include "string.h"
#define PI 3.14159265f

void initGL() {
   glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

void dda(double x1, double y1, double xn, double yn)
{   
    double xx = x1;
    double yx = y1;

    int dx = xn - x1;
    int dy = yn - y1;

    double steps;

    if(abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    double xin = dx/steps;
    double yin = dy/steps;

    glBegin(GL_POINTS);
    glColor3f(1, 1, 1); 

    for(int i = 0; i < steps ; i++)
    {
        glVertex2i(xx, yx);
        xx = xx + xin;
        yx = yx + yin;
    }
    glEnd();

}

void display()
{   
    glClear(GL_COLOR_BUFFER_BIT);
    // glPointSize(3.0f);

    dda(128,240,224,360);
    dda(224,360,416,360);
    dda(416,360,512,240);
    dda(512,240,416,120);
    dda(416,120,224,120);
    dda(224,120,128,240);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(50,50);
    glutCreateWindow("DDA house");
    gluOrtho2D(-700, 700, -700, 700);

    glutDisplayFunc(display);
    // glutKeyboardFunc(keyboard);
    // glutMouseFunc(mouse);
    initGL();
    glutMainLoop();

    return 0;
}
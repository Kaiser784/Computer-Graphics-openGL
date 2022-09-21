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
    // triangles
    dda(-350,0,350,0);
    dda(350,0,0,700);
    dda(0,700,-350,0);

    //Squares
    dda(-350,0,-350,-700);
    dda(-350,-700,350,-700);
    dda(350,-700,350,0);
    dda(350,0,-350,0);

    dda(-250,-350,-250,-450);
    dda(-250,-450,-150,-450);
    dda(-150,-450,-150,-350);
    dda(-150,-350,-250,-350);

    dda(150,-350,150,-450);
    dda(150,-450,250,-450);
    dda(250,-450,250,-350);
    dda(250,-350,150,-350);

    dda(-50,-350,-50,-700);
    dda(-50,-700,50,-700);
    dda(50,-700,50,-350);
    dda(50,-350,-50,-350);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(50,50);
    glutCreateWindow("DDA Hexagon");
    gluOrtho2D(-1000, 1000, -1000, 1000);

    glutDisplayFunc(display);
    // glutKeyboardFunc(keyboard);
    // glutMouseFunc(mouse);
    initGL();
    glutMainLoop();

    return 0;
}
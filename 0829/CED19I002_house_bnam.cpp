#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
#include "math.h"
#include "string.h"
#define PI 3.14159265f

void initGL() {
   glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

void bnam(double x1, double y1, double xn, double yn)
{   
    double xx = x1;
    double yx = y1;

    int dx = xn - x1;
    int dy = yn - y1;

    int p;

    if(abs(dy) <= abs(dx))
    {
        p = 2*abs(dy) - abs(dx);
        for(int i = 0; i < abs(dx); i++)
        {
            if(p >= 0)
            {
                p += (2*abs(dy) - 2*abs(dx));
                yx += dy/abs(dy);
            }
            else
            {
                p += (2*abs(dy));
            }
            xx += dx/abs(dx);

            glBegin(GL_POINTS);
            glVertex2i(xx, yx);
            glEnd();
        }
    }
    else
    {
        p = 2*abs(dx) - abs(dy);
        for(int i = 0; i < abs(dy); i++)
        {
            if(p >= 0)
            {
                p += (2*abs(dx) - 2*abs(dy));
                xx += dx/abs(dx);
            }
            else
            {
                p += (2*abs(dx));
            }
            yx += dy/abs(dy);

            glBegin(GL_POINTS);
            glVertex2i(xx, yx);
            glEnd();
        }
    }
}

void display()
{   
    glClear(GL_COLOR_BUFFER_BIT);
    // triangles
    bnam(-350,0,350,0);
    bnam(350,0,0,700);
    bnam(0,700,-350,0);

    //Squares
    bnam(-350,0,-350,-700);
    bnam(-350,-700,350,-700);
    bnam(350,-700,350,0);
    bnam(350,0,-350,0);

    bnam(-250,-350,-250,-450);
    bnam(-250,-450,-150,-450);
    bnam(-150,-450,-150,-350);
    bnam(-150,-350,-250,-350);

    bnam(150,-350,150,-450);
    bnam(150,-450,250,-450);
    bnam(250,-450,250,-350);
    bnam(250,-350,150,-350);

    bnam(-50,-350,-50,-700);
    bnam(-50,-700,50,-700);
    bnam(50,-700,50,-350);
    bnam(50,-350,-50,-350);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(50,50);
    glutCreateWindow("bnam Hexagon");
    gluOrtho2D(-1000, 1000, -1000, 1000);

    glutDisplayFunc(display);
    // glutKeyboardFunc(keyboard);
    // glutMouseFunc(mouse);
    initGL();
    glutMainLoop();

    return 0;
}
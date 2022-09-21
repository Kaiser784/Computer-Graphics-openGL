#include <GL/glut.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
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

void illuminate(int xx, int yx)
{
    glBegin(GL_POINTS);
        glVertex2i(xx, yx);
    glEnd();
}

void octants(int cx, int cy, double xx, double yx)
{
    illuminate(cx + xx, cy + yx); //Q1
    illuminate(cx + yx, cy + xx); //Q2
    illuminate(cx - yx, cy + xx); //Q3
    illuminate(cx - xx, cy + yx); //Q4

    illuminate(cx - xx, cy - yx); //Q5
    illuminate(cx - yx, cy - xx); //Q6
    illuminate(cx + yx, cy - xx); //Q7
    illuminate(cx + xx, cy - yx); //Q8
}

void mcd(int cx, int cy, int radius)
{
    double xx = radius;
    double yx = 0;

    double p = 1 - radius;

    int yn = radius/sqrt(2);

    for(int i = 0; i < yn; i++)
    {
        octants(cx, cy, xx, yx);
        if(p<0)
        {
            p += 2*yx + 3;
        }
        else
        {   
            p += 2*yx - 2*xx + 5;
            xx--;
        }
        yx++;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

        //top
        bnam(350,200,0,200);
        bnam(0,200,-200,0);
        bnam(-200,0,400,0);
        bnam(400,0,350,200);

        //bottom
        bnam(400,0,-400,0);
        bnam(-400,0,-400,-200);
        bnam(-400,-200,400,-200);
        bnam(400,-200,400,0);

        //front window
        bnam(150,150,25,150);
        bnam(25,150,-150,0);
        bnam(-150,0,150,0);
        bnam(150,0,150,150);

        //back window
        bnam(300,150,200,150);
        bnam(200,150,200,0);
        bnam(200,0,350,0);
        bnam(350,0,300,150);

    glEnd();
    mcd(200, -200, 100);
    mcd(-200, -200, 100);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(50,50);
    glutCreateWindow("bnam-mld Car");
    gluOrtho2D(-1000, 1000, -1000, 1000);


    glutDisplayFunc(display);
    // glutKeyboardFunc(keyboard);
    // glutMouseFunc(mouse);
    initGL();
    glutMainLoop();

    return 0;
}
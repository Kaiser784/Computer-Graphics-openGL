#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f

double alpha;
double beta;
double rx;
double ry;


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

int check(double xx, double yx)
{   
    double lowerangle;   
    double upperangle;
    double angle = (180/PI)*atan2(yx,xx);
    if(angle < 0)
    {
        angle +=360;
    }

    if(alpha >= 0 && beta >= 0)
    {
        upperangle = alpha+beta;
        if(upperangle > 360)
        {
            upperangle -= 360;
            if(angle >= alpha || angle <= upperangle)
                return 1;
            else
                return 0;
        }
        else
        {
            if(angle >= alpha && angle <= upperangle)
                return 1;
            else
                return 0;
        }
    }
    else if(alpha < 0 && beta >= 0)
    {   
        lowerangle = alpha + 360;
        upperangle = lowerangle+beta;
        if(upperangle > 360)
        {
            upperangle -= 360;
            if(angle >= lowerangle || angle <= upperangle)
                return 1;
            else
                return 0;
        }
        else
        {
            if(angle >= lowerangle && angle <= upperangle)
                return 1;
            else
                return 0;
        }
    }
    else if(alpha >= 0 && beta < 0)
    {
        lowerangle = alpha + beta;
        upperangle = alpha;
        if(lowerangle < 0)
        {
            lowerangle += 360;
            if(angle >= lowerangle || angle <= upperangle)
                return 1;
            else
                return 0;
        }
        else
        {
            if(angle >= lowerangle && angle <= upperangle)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        lowerangle = alpha + beta + 360;
        upperangle = alpha + 360;
        if(lowerangle < 0)
        {
            lowerangle += 360;
            if(angle >= lowerangle || angle <= upperangle)
                return 1;
            else
                return 0;
        }
        else
        {
            if(angle >= lowerangle && angle <= upperangle)
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

void draw(int cx, int cy, int xx, int yx)
{
    if(check(xx,yx))
    {
        illuminate(cx+xx,cy+yx);
    }
    if(check(-xx,yx))
    {
        illuminate(cx-xx,cy+yx);
    }
    if(check(-xx,-yx))
    {
        illuminate(cx-xx,cy-yx);
    }
    if(check(xx,-yx))
    {
        illuminate(cx+xx,cy-yx);
    }
}

void med(int cx, int cy, int rx, int ry)
{   

    //region1 - o2
    double xx = 0;
    double yx = ry;

    double p1 = (ry*ry) - (rx*rx*ry) + (0.25*rx*rx);

    while(!((ry*ry*xx)>=(rx*rx*yx)))
    {
        draw(cx,cy,xx,yx);

        xx++; 
        if(p1 > 0)
        {
            yx--; 
            p1 = p1 + (2*ry*ry)*(xx-1) + (3*ry*ry) - (2*rx*rx*yx); 
        }
        else
        { 
            p1 = p1 + (2*ry*ry)*(xx-1) + (3*ry*ry);
        }
    }

    //region2 o1
    int p2 = ry*ry*(xx+0.5)*(xx+0.5) +
                rx*rx*(yx-1)*(yx-1) +
                (rx*rx*ry*ry);

    while(yx > 0)
    {   
        draw(cx,cy,xx,yx);
        yx--;   
        if(p2>0)
        {   
            p2 = p2 + (rx*rx) - (2*rx*rx*yx);
        }
        else
        {
            xx++;
            p2 = p2 + (rx*rx) - (2*rx*rx*yx) + (2*ry*ry*xx);
        }

    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);
    bnam(-1000,0,1000,0);
    bnam(0,-1000,0,1000);

    rx = 300 + rand() % 500;
    ry = 500 + rand() % 500;

    alpha = -360 + rand() % 720;
    beta = -360 + rand() % 720;

    glColor3f((float)((rand() % 100))/99, (float)((rand() % 100))/99, (float)((rand() % 100))/99);
    med(0,0,rx,ry);

    glFlush();
}

void Mouse(int button, int state, int x, int y){
   display();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    


    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Elliptical Arc");
    gluOrtho2D(-1000, 1000, -1000, 1000);
    glutDisplayFunc(display);
    // glutKeyboardFunc(keyboard);
    glutMouseFunc(Mouse);
    initGL();
    glutMainLoop();

    return 0;
}
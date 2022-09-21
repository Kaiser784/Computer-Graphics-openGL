#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f

double alpha;
double beta;
double radius;


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

void check(int cx, int cy, double xx, double yx)
{   
    double angle;
    angle = (180/PI)*atan2(xx,yx); //q1
    if(angle >= alpha && angle <= beta+alpha)
    {
        illuminate(yx,xx);
    }
    angle = (180/PI)*atan2(yx,xx); //q2
    if(angle >= alpha && angle <= beta+alpha)
    {
        illuminate(xx,yx);
    }
    angle = (180/PI)*atan2(yx,-xx); //q3
    if(angle >= alpha && angle <= beta+alpha)
    {
        illuminate(-xx,yx);
    }
    angle = (180/PI)*atan2(xx,-yx); //q4
    if(angle >= alpha && angle <= beta+alpha)
    {
        illuminate(-yx,xx);
    }
    ////////////////////////////////////////

    angle = (180/PI)*atan2(-xx,-yx)+360; //q5
    if(angle >= alpha && angle <= beta+alpha)
    {
        illuminate(-yx,-xx);
    }
    angle = (180/PI)*atan2(-yx,-xx)+360; //q6
    if(angle >= alpha && angle <= beta+alpha)
    {
        illuminate(-xx,-yx);
    }    
    angle = (180/PI)*atan2(-yx,xx)+360; //q7
    if(angle >= alpha && angle <= beta+alpha)
    {
        illuminate(xx,-yx);
    }
    angle = (180/PI)*atan2(-xx,yx)+360; //q8
    if(angle >= alpha && angle <= beta+alpha)
    {
        illuminate(yx,-xx);
    }
}

void mcd(int cx, int cy, int radius)
{
    double xx = radius;
    double yx = 0;

    double p = 1 - radius;

    int yn = radius/sqrt(2);

    for(int i = 0; i < yn; i++)
    {
        check(cx, cy, xx, yx);
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
    bnam(-1000,0,1000,0);
    bnam(0,-1000,0,1000);

    double ax1 = 0 + radius*(double)cos(alpha*PI/180);
    double ay1 = 0 + radius*(double)sin(alpha*PI/180);

    double axn = 0 + radius*(double)cos((beta+alpha)*PI/180);
    double ayn = 0 + radius*(double)sin((beta+alpha)*PI/180);

    bnam(0,0,ax1,ay1);
    bnam(0,0,axn,ayn);
    mcd(0,0,radius);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    

    cout<< "alpha:";
    cin>>alpha;

    cout<< "beta:";
    cin>>beta;

    cout<< "radius:";
    cin>>radius;

    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(50,50);
    glutCreateWindow("bnam-mcd Arc");
    gluOrtho2D(-1000, 1000, -1000, 1000);
    glutDisplayFunc(display);
    // glutKeyboardFunc(keyboard);
    // glutMouseFunc(mouse);
    initGL();
    glutMainLoop();

    return 0;
}
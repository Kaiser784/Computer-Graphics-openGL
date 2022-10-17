#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f

float xmin = 300, ymin = 300, xmax = 900, ymax = 600;
float xtop = 600, ytop = 750;


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

    //Polygon Window
    int n = rand()%10+3;
    int theta = 360/n;
    int r = 250;

    float xp[n];
    float yp[n];

    for(int i = 0; i < n; i++)
    {
        xp[i] = 500+r*cos((theta*i)*PI/180);
        yp[i] = 500+r*sin((theta*i)*PI/180);
    }

    glColor3f(0, 1, 0);
    glBegin(GL_LINE_LOOP);
    for(int i = n-1; i >= 0; i--)
    { 
        glVertex2d(xp[i], yp[i]);
    }
    glEnd();

    //Random Point
    for(int i = 0; i < 50; i++)
    {
        xx = rand() % 800;
        yx = rand() % 800;
        int flag = 0;

        for(int j = 0; j < n; j++)
        {   
            int p0x = xp[j%n];
            int p0y = yp[j%n];
            int p1x = xp[(j+1)%n];
            int p1y = yp[(j+1)%n];
            
            float side = ((yx-p0y)*(p1x-p0x)) - ((xx-p0x)*(p1y-p0y));

            if(side > 0)
            {
                flag++;
            }
        }
        if(flag == n)
        {
            glColor3f(1.0, 0.0, 0.0);
            illuminate(xx, yx);
        }
        else
        {
            glColor3f(0.0, 1.0, 0.0);
            illuminate(xx, yx);
        }
    }

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

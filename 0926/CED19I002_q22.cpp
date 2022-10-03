#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#include <bits/stdc++.h>
#define PI 3.14159265f

//Liang Barsky Algorithm

float xmin = 300, ymin = 300, xmax = 900, ymax = 600;
float ax, ay, bx, by;

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

void compute(float ax, float ay, float bx, float by)
{
    float dx,dy;
    float nx1, ny1, nx2, ny2;

    dx = bx-ax;
    dy = by-ay;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {ax-xmin, xmax-ax, ay-ymin, ymax-ay};

    float u, u1, u2;

    vector<float> max_elm, min_elm;
    int flag = 0;

    for(int i = 0; i < 4; i++)
    {
        if(p[i]==0 && q[i]<0)
        {   
            //out of the window
            flag = 1;
            break;
        }
    }
    if(flag != 1)
    {
        max_elm.push_back(0);
        min_elm.push_back(1);

        for(int i = 0; i < 4; i++)
        {
            u = (float)q[i]/(float)p[i];

            if(p[i] < 0)
            {
                max_elm.push_back(u);
            }
            else if(p[i] > 0)
            {
                min_elm.push_back(u);
            }
        }

        u1 = *max_element(max_elm.begin(), max_elm.end());
        u2 = *min_element(min_elm.begin(), min_elm.end());

        if(u1 > u2)
        {
            //lies outside
        }
        else
        {
            nx1 = ax + (u1*dx);
            ny1 = ay + (u1*dy);

            nx2 = ax + (u2*dx);
            ny2 = ay + (u2*dy);

            glColor3f(0,1,0);
            glBegin(GL_LINES);
                glVertex2f(nx1,ny1);
                glVertex2f(nx2,ny2);
            glEnd();

        }
    }
}

void display()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	drawClippingWindow();
	glPointSize(5);
	for(int i = 0; i < rand() % 1000; i++)
	{
		ax = rand() % 1000;
		ay = rand() % 1000;
		bx = rand() % 1000;
		by = rand() % 1000;

		//full line in red
		glBegin(GL_LINES);
			glColor3f(1, 0, 0);
			glVertex2f(ax, ay);
			glVertex2f(bx, by);
		glEnd();

		// in region lines to green
		compute(ax,ay,bx,by);
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

	glutCreateWindow("Line Clipping");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(Mouse);

	glutMainLoop();

	return 0;
}

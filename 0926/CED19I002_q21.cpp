#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f

//Cohen Sutherland Algorithm

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

int regioncode(double x, double y)
{
	int code = 0;
	if(y > ymax)
	{	
		code |= TOP;
	}
	else if(y < ymin)
	{	
		code |= BOTTOM;
	}
	if(x > xmax)
	{	
		code |= RIGHT;
	}
	else if(x < xmin)
	{	
		code |= LEFT;
	}
	return code;
}

void compute(double ax, double ay, double bx, double by)
{
	int code1 = regioncode(ax, ay);
	int code2 = regioncode(bx, by);

	bool accept = false;

	while(true)
	{
		if(!(code1 | code2))
		{
			accept = true;
			break;
		}
		else if(code1 & code2)
		{
			break;
		}
		else
		{	
			int codeout;
			float xx,yx;

			if(code1 != 0)
			{
				codeout = code1;
			}
			else
			{
				codeout = code2;
			}
			// y = y1 + slope * (x - x1)
			// x = x1 + (1/slope)* (y - y1)
			if(codeout & LEFT)
			{
				yx = ay + (by-ay)*(xmin-ax)/(bx-ax);
				xx = xmin;
			}
			else if(codeout & RIGHT)
			{
				yx = ay + (by-ay)*(xmax-ax)/(bx-ax);
				xx = xmax;
			}
			else if(codeout & TOP)
			{
				xx = ax + (bx-ax)*(ymax-ay)/(by-ay);
				yx = ymax;
			}
			else if(codeout & BOTTOM)
			{
				xx = ax + (bx-ax)*(ymin-ay)/(by-ay);
				yx = ymin;
			}

			if(codeout == code1)
			{
				ax = xx;
				ay = yx;
				code1 = regioncode(ax,ay);
			}
			else
			{
				bx = xx;
				by = yx;
				code2 = regioncode(bx,by);
			}
		}
	}
	if(accept)
	{
		//inside window green
        glColor3f(0, 1, 0);
		glBegin(GL_LINES);
			glVertex2d(ax, ay);
			glVertex2d(bx, by);
        glEnd();
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

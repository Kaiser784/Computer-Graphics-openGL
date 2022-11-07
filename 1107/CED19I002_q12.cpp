#include <GL/glut.h>
#include<unistd.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f  

int width = 800, height = 500;   

float fillColor[3] = {0.0,0.0,1.0};   
float boundColor[3] = {1.0,1.0,1.0};  

void setPixel(int xx, int yx, float pixel[3])   
{   
    glBegin(GL_POINTS);   
        glColor3fv(pixel);   
        glVertex2i(xx,yx);   
    glEnd();   
    glFlush();   
}   

void getPixel(int x, int y, float pixels[3])   
{   
   glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);   
}   

void boundaryFill4(int x,int y,float fillColor[3],float boundColor[3])   
{   
    float interiorColor[3];
    vector<pair<int, int>> stack;
    pair<int, int> curr;

    stack.push_back({x, y});

    while(stack.size() > 0)
    {
        curr = stack.back();
        stack.pop_back();

        int cx = curr.first, cy = curr.second;
        getPixel(cx, cy, interiorColor);

        if ((interiorColor[0] != boundColor[0] && (interiorColor[1]) != boundColor[1] && (interiorColor[2]) != boundColor[2]))
        {
            setPixel(cx, cy, fillColor);
            stack.push_back({cx, cy+1});
            stack.push_back({cx, cy-1});
            stack.push_back({cx+1, cy});
            stack.push_back({cx-1, cy});
        }
    }
} 
void drawPolygon(int x1, int y1, int x2, int y2)   
{      
     glColor3f(1.0, 1.0, 1.0);   
     glBegin(GL_LINE_LOOP);   
        glVertex2i(x1, y1);    
        glVertex2i(x1, y2);   
        glVertex2i(x2, y2);   
        glVertex2i(x2, y1);      
     glEnd();   
     glFlush();   
}   
void display()   
{   
    glClearColor(0, 0, 0, 1);   
    glClear(GL_COLOR_BUFFER_BIT);   
    drawPolygon(400,200,600,400);  
    boundaryFill4(455,260,fillColor,boundColor);    
    glFlush();   
}   
     
void myinit()   
{      
    glViewport(0,0,width,height);   
    glMatrixMode(GL_PROJECTION);   
    glLoadIdentity();   
    gluOrtho2D(0.0,(GLdouble)width,0.0,(GLdouble)height);   
    glMatrixMode(GL_MODELVIEW);   
}   
int main(int argc, char** argv)   
{   
    glutInit(&argc,argv);   
    glutInitWindowSize(width,height);   
    glutCreateWindow("Boundary-Fill-iterative");   
    glutDisplayFunc(display);   
    myinit();     
    glutMainLoop();   
    return 0;   
}   

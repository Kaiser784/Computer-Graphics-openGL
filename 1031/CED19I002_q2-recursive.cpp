#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f  

int width = 800, height = 500;   

float oldColor[3] = {1.0,0.0,0.0};   
float newColor[3] = {0.0,0.0,1.0};  

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

void floodfill4(int x,int y,float oldcolor[3],float newcolor[3])   
{   
    float color[3];   
    getPixel(x,y,color);   
    if(color[0]==oldcolor[0] && (color[1])==oldcolor[1] && (color[2])==oldcolor[2])   
    {   
        setPixel(x,y,newcolor);   
        floodfill4(x+1,y,oldcolor,newcolor);   
        floodfill4(x-1,y,oldcolor,newcolor);   
        floodfill4(x,y+1,oldcolor,newcolor);   
        floodfill4(x,y-1,oldcolor,newcolor);   
    }   
} 
void drawPolygon(int x1, int y1, int x2, int y2)   
{      
    glColor3f(1.0, 0.0, 0.0);   
    glBegin(GL_POLYGON);   
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
    floodfill4(455,260,oldColor,newColor);    
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
    glutCreateWindow("Flood-Fill-Recursive");   
    glutDisplayFunc(display);   
    myinit();     
    glutMainLoop();   
    return 0;   
}   

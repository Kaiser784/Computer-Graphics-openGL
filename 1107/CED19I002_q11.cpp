#include <GL/glut.h>
#include<unistd.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f  

int width = 800, height = 500;     

void brute(int x, int y, float* fill, float* bound)
{
    float color[3];
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bound[0] || color[1]!=bound[1] || color[2]!=bound[2]) && (color[0]!=fill[0] || color[1]!=fill[1] || color[2]!=fill[2]))
    {
        glColor3f(fill[0], fill[1], fill[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();

        brute(x+1,y,fill,bound);
        brute(x-1,y,fill,bound);
        brute(x,y+1,fill,bound);
        brute(x,y-1,fill,bound);
    }
}

void draw_polygon()
{
    int vertices;
    int xi,yi;

    printf("Enter no of vertices: ");
    cin >> vertices;
    printf("Enter in anti-clockwise order\n");
    
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i < vertices; i++)
    {
        printf("Enter xi:");
        cin >> xi;
        printf("Enter yi:");
        cin >> yi;
        printf("\n");
        glVertex2i(xi,yi);
    }
    glEnd();

}

void display()   
{   
    glClearColor(0, 0, 0, 1);   
    glClear(GL_COLOR_BUFFER_BIT); 

    draw_polygon();
    
    glFlush();   
} 

void mouse(int btn, int state, int x, int y){
    y = height-y;
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            float bound[] = {0,0,1};
            float fill[] = {1,1,1};
            brute(x,y,fill,bound);
        }
    }
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width,height);   
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Brute-Boundary-Fill");   
    
    myinit();     
    glutDisplayFunc(display);  
    glutMouseFunc(mouse); 
    
    glutMainLoop();   
    return 0;   
}   

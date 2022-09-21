#include <GL/glut.h>
#include<unistd.h>
#include <iostream>
using namespace std;
#include "math.h"
#include "string.h"
#define PI 3.14159265f
 
double a;
double mul=0.001;
 
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
 
void parabola(int cx, int cy, double a){
 
	int parameter = 1-(2*abs(a));
    int x=0,y=0;
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    // Region 1

    for(int i=0; i<2*abs(a); i++){

        glVertex2f((mul*x)+cx,(mul*y)+cy);// Q1
        glVertex2f((mul*x*-1)+cx,(mul*y)+cy);// Q2

        x++;
        if(parameter>=0){
            y++;
            parameter = parameter + 2*x+3 - 4*abs(a);
        }
        else{
            parameter = parameter + 2*x+3;
        }
    }
    // Region 2
    parameter = (x+0.5)*(x+0.5)-4*abs(a)*(y+1);
    for(int i=0; i<3*abs(a); i++){

        glVertex2f((mul*x)+cx,(mul*y)+cy);// Q1
        glVertex2f((mul*x*-1)+cx,(mul*y)+cy);// Q2

        y++;
        if(parameter>=0){
            parameter = parameter - 4*abs(a);
        }
        else{
            x++;
            parameter = parameter + 2*x - 4*abs(a);
        }
    }
    glEnd();
}
 
void display() {
   glClear(GL_COLOR_BUFFER_BIT); 
 
    a = 50 + (rand()%100);
    glColor3f((float)((rand() % 100))/99, (float)((rand() % 100))/99, (float)((rand() % 100))/99);

    int cx = 0.01*(rand()%50);
    int cy = 0.01*(rand()%50);

    parabola(cx,cy,a);
 
   glFlush(); 
}

void Mouse(int button, int state, int x, int y){
   display();
}
 
int main(int argc, char** argv) {
    glutInit(&argc, argv);          
    glutInitWindowSize(900, 900);   
    glutInitWindowPosition(50, 50); 
    glutCreateWindow("Parabola");  
    glutDisplayFunc(display);      
    glutMouseFunc(Mouse);
 
    initGL();                       
    glutMainLoop();                
    return 0;

}
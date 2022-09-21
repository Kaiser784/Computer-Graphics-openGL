#include <GL/glut.h>
#include "math.h" 
#define PI 3.14159265f

void initGL() {
   glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

void space()
{
    glBegin(GL_TRIANGLES);          
        glColor3f(0.0f, 0.5f, 1.0f); 
        glVertex2f(-0.35, 0);
        glVertex2f(0.35, 0);
        glVertex2f(0.0, 0.7);   
    glEnd();

    glBegin(GL_QUADS);         
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.35, 0);
        glVertex2f(-0.35, -0.7); 
        glVertex2f(0.35, -0.7);
        glVertex2f(0.35, 0);

        glColor3f(0.0f, 0.0f, 0.0f); 
        glVertex2f(-0.25, -0.35);
        glVertex2f(-0.25, -0.45); 
        glVertex2f(-0.15, -0.45);
        glVertex2f(-0.15, -0.35);

        glColor3f(0.0f, 0.0f, 0.0f); 
        glVertex2f(0.15, -0.35);
        glVertex2f(0.15, -0.45);
        glVertex2f(0.25, -0.45);
        glVertex2f(0.25, -0.35);
         
        glColor3f(0.0f, 0.0f, 0.0f); 
        glVertex2f(-0.05, -0.35);
        glVertex2f(-0.05, -0.70);
        glVertex2f(0.05, -0.70);
        glVertex2f(0.05, -0.35);
          
    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); 
   
    glBegin(GL_TRIANGLES);          
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.35, 0);
        glVertex2f(0.35, 0);
        glVertex2f(0.0, 0.7);   
    glEnd();

    glBegin(GL_QUADS);         
        glColor3f(0.0f, 0.5f, 1.0f); 
        glVertex2f(-0.35, 0);
        glVertex2f(-0.35, -0.7); 
        glVertex2f(0.35, -0.7);
        glVertex2f(0.35, 0);

        glColor3f(1.0f, 1.0f, 1.0f); 
        glVertex2f(-0.25, -0.35);
        glVertex2f(-0.25, -0.45); 
        glVertex2f(-0.15, -0.45);
        glVertex2f(-0.15, -0.35);

        glColor3f(1.0f, 1.0f, 1.0f); 
        glVertex2f(0.15, -0.35);
        glVertex2f(0.15, -0.45);
        glVertex2f(0.25, -0.45);
        glVertex2f(0.25, -0.35);
         
        glColor3f(1.0f, 1.0f, 1.0f); 
        glVertex2f(-0.05, -0.35);
        glVertex2f(-0.05, -0.70);
        glVertex2f(0.05, -0.70);
        glVertex2f(0.05, -0.35);
        
          
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        initGL();
        display();
        break;

    case 32:
        initGL();
        space();
        break;
    
    default:
        break;
    }
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON)
    {
        space();
    }

    if(button == GLUT_RIGHT_BUTTON)
    {
        display();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Interactive House");

    glutInitWindowSize(1080,1080);
    glutInitWindowPosition(50,50);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    initGL();
    glutMainLoop();
    return 0;
}
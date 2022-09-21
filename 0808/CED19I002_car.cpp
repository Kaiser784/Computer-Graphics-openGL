#include <GL/glut.h>
#include<unistd.h>
#include "math.h"
#define PI 3.14159265f

void initGL() {
   glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

void circle1(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3f( 0.0f,  0.0f, 1.0f);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
            if(i%2 == 0)
            {
                glColor3f( 0.0f,  0.0f, 1.0f);
            }
            else
            {
                glColor3f( 1.0f,  0.0f, 0.0f);
            }
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			        y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void circle2(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
        glColor3f( 0.0f,  0.0f, 1.0f);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
            if(i%2 == 0)
            {
                glColor3f( 1.0f,  0.0f, 0.0f);
            }
            else
            {
                glColor3f( 0.0f,  0.0f, 1.0f);
            }
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			        y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void space()
{
    for(int i = 0; i < 100; i++)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);

            //top
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(0.35-(0.01*i),0.2);
            glVertex2f(0.0-(0.01*i),0.2);
            glVertex2f(-0.2-(0.01*i),0.0);
            glVertex2f(0.4-(0.01*i),0.0);

            //bottom
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(0.4-(0.01*i),0.0);
            glVertex2f(-0.4-(0.01*i),0.0);
            glVertex2f(-0.4-(0.01*i),-0.2);
            glVertex2f(0.4-(0.01*i),-0.2);

            //front window
            glColor3f( 0.0f,  0.0f, 1.0f);
            glVertex2f(0.15-(0.01*i),0.15);
            glVertex2f(0.025-(0.01*i),0.15);
            glVertex2f(-0.15-(0.01*i),0.0);
            glVertex2f(0.15-(0.01*i),0.0);

            //back window
            glColor3f( 0.0f,  0.0f, 1.0f);
            glVertex2f(0.30-(0.01*i),0.15);
            glVertex2f(0.20-(0.01*i),0.15);
            glVertex2f(0.20-(0.01*i),0.0);
            glVertex2f(0.35-(0.01*i),0.0);
        glEnd();

        circle1(0.2-(0.01*i), -0.2, 0.1);
        circle1(-0.2-(0.01*i), -0.2, 0.1);

        glFlush();
    }
    
}

void esc()
{
    for(int i = 0; i < 100; i++)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);

            //top
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(0.35+(0.01*i),0.2);
            glVertex2f(0.0+(0.01*i),0.2);
            glVertex2f(-0.2+(0.01*i),0.0);
            glVertex2f(0.4+(0.01*i),0.0);

            //bottom
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(0.4+(0.01*i),0.0);
            glVertex2f(-0.4+(0.01*i),0.0);
            glVertex2f(-0.4+(0.01*i),-0.2);
            glVertex2f(0.4+(0.01*i),-0.2);

            //front window
            glColor3f( 0.0f,  0.0f, 1.0f);
            glVertex2f(0.15+(0.01*i),0.15);
            glVertex2f(0.025+(0.01*i),0.15);
            glVertex2f(-0.15+(0.01*i),0.0);
            glVertex2f(0.15+(0.01*i),0.0);

            //back window
            glColor3f( 0.0f,  0.0f, 1.0f);
            glVertex2f(0.30+(0.01*i),0.15);
            glVertex2f(0.20+(0.01*i),0.15);
            glVertex2f(0.20+(0.01*i),0.0);
            glVertex2f(0.35+(0.01*i),0.0);
        glEnd();

        circle2(0.2+(0.01*i), -0.2, 0.1);
        circle2(-0.2+(0.01*i), -0.2, 0.1);

         glFlush();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

        //top
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.35,0.2);
        glVertex2f(0.0,0.2);
        glVertex2f(-0.2,0.0);
        glVertex2f(0.4,0.0);

        //bottom
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.4,0.0);
        glVertex2f(-0.4,0.0);
        glVertex2f(-0.4,-0.2);
        glVertex2f(0.4,-0.2);

        //front window
        glColor3f( 0.0f,  0.0f, 1.0f);
        glVertex2f(0.15,0.15);
        glVertex2f(0.025,0.15);
        glVertex2f(-0.15,0.0);
        glVertex2f(0.15,0.0);

        //back window
        glColor3f( 0.0f,  0.0f, 1.0f);
        glVertex2f(0.30,0.15);
        glVertex2f(0.20,0.15);
        glVertex2f(0.20,0.0);
        glVertex2f(0.35,0.0);
    glEnd();

    circle1(0.2, -0.2, 0.1);
    circle1(-0.2, -0.2, 0.1);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        initGL();
        esc();
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
        esc();
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
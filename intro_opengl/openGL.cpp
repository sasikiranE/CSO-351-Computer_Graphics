#include <iostream>
#include <GL/glut.h>

void display() {
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// set bg color to black and opaque

	glClear(GL_COLOR_BUFFER_BIT);			// clear the color buffer

	// drawing a square 1 x 1 centered at origin.

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(-0.5f, -0.5f);
	glEnd();

	glFlush();	// render now
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Quadrilateral with OpenGL");
	glutInitWindowSize(1440, 900);
	glutInitWindowPosition(0, 0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

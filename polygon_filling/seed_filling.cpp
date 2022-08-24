#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;
float intCol[3] = {1.0, 0.0, 0.0};
float fillCol[3] = {0.4, 0.0, 0.0};

void setPixel(int X, int Y, float *fillColor) {
    glBegin(GL_POINTS);
    glColor3fv(fillColor);
    glVertex2i(X, Y);
    glEnd();
    glFlush();
}

void getPixel(int x, int y, float *pixels) {
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}

void floodFill8Connected(int x, int y, float *initialColor, float *fillColor) {
    float color[3];
    getPixel(x, y, color);
    if (color[0] == initialColor[0] && color[1] == initialColor[1] &&
        color[2] == initialColor[2]) {
        setPixel(x, y, fillColor);
        floodFill8Connected(x + 1, y, initialColor, fillColor);
        floodFill8Connected(x + 1, y + 1, initialColor, fillColor);
        floodFill8Connected(x, y + 1, initialColor, fillColor);
        floodFill8Connected(x - 1, y + 1, initialColor, fillColor);
        floodFill8Connected(x - 1, y, initialColor, fillColor);
        floodFill8Connected(x - 1, y - 1, initialColor, fillColor);
        floodFill8Connected(x, y - 1, initialColor, fillColor);
        floodFill8Connected(x + 1, y - 1, initialColor, fillColor);
    }
}

void mouseCallback(int buttonClicked, int buttonState, int x, int y) {
    if (buttonClicked == GLUT_LEFT_BUTTON && buttonState == GLUT_DOWN) {
        floodFill8Connected(x, y, intCol, fillCol);
    }
}

void polynomialCircle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
// Hardcoded Pentagon
    glBegin(GL_POLYGON);
    glVertex2i(200, 200);
    glVertex2i(400, 200);
    glVertex2i(400, 300);
    glVertex2i(300, 450);
    glVertex2i(200, 300);
    glEnd();
    glFlush();
}

void vgl_init(int &argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Flood Fill Algorithm");
    glutDisplayFunc(polynomialCircle);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    gluOrtho2D(0, 640, 0, 480);
    glutMouseFunc(mouseCallback);
    glutMainLoop();
}

int main(int argc, char **argv) {
    vgl_init(argc, argv);
}
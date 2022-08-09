#include <iostream>
#include <GL/glut.h>

using namespace std;

int X1, Y1, X2, Y2;

void display(void) {
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    
    int x = X1, y = Y1;

    int p = 2 * dy - dx;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    while (x < X2) {
        if (p >= 0) {
            glVertex2i(x, y);
            y += 1;
            x += 1;
            p += (2 * dy - 2 * dx);
        }
        else {
            glVertex2i(x, y);
            p += 2 * dy;
            x += 1;
        }
    }
    glEnd();
    glFlush();
}

void myInit (void) {
    // Reset background color with black (since all three argument is 0.0)
    glClearColor(0.46, 0.46, 0.46, 1.0);
     
    // Set picture color to green (in RGB model)
    // as only argument corresponding to G (Green) is 1.0 and rest are 0.0
    glColor3f(0.0, 1.0, 0.0);
     
    // Set width of point to one unit
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     
    // Set window size in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
}

int main(int argc, char **argv) {

    cout << "Enter x1 : ";
    cin >> X1;

    cout << "Enter y1 : ";
    cin >> Y1;

    cout << "Enter x2 : ";
    cin >> X2;

    cout << "Enter y2 : ";
    cin >> Y2;

    glutInit(&argc, argv);
     
    // Display mode which is of RGB (Red Green Blue) type
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     
    // Declares window size
    glutInitWindowSize(1360, 768);
     
    // Declares window position which is (0, 0)
    // means lower left corner will indicate position (0, 0)
    glutInitWindowPosition(0, 0);
 
    // Name to window
    glutCreateWindow("Line Using Bresenham's");
 
    // Call to myInit()
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
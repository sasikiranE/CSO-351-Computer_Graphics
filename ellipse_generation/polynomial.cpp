#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

float H, K, A, B;

void plot_four_points(float x, float y) {
    glVertex2i(H + x, K + y);  
    glVertex2i(H - x, K + y);  
    glVertex2i(H - x, K - y);  
    glVertex2i(H + x, K - y);  
}

void display(void) {
    float x, y;
    const float STEP_SIZE = 0.1;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    if (A > B) {
        x = 0, y = B;
        while (x <= A) {
            y = B * sqrt(1 - (x * x) / (A * A));
            plot_four_points(x, y);
            x += STEP_SIZE;
        }
    }
    else {
        x = A, y = 0;
        while (y <= B) {
            x = A * sqrt(1 - (y * y) / (B * B));
            plot_four_points(x, y);
            y += 1;
        }
    }

	glEnd();
	glFlush();
}

void myInit (void) {
	// Reset background color with black (since all three argument is 0.0)
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Set picture color to green (in RGB model)
	// as only argument corresponding to G (Green) is 1.0 and rest are 0.0
	glColor3f(0.0, 0.0, 0.0);

	// Set width of point to one unit
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set window size in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420);
}

int main(int argc, char **argv) {

    cout << "Enter Circle Center (h, k) : ";
    cin >> H >> K;
    cout << "Enter length of major (a) and minor (b) axes : ";
    cin >> A >> B;

	glutInit(&argc, argv);

	// Display mode which is of RGB (Red Green Blue) type
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Declares window size
	glutInitWindowSize(960, 540);

	// Declares window position which is (0, 0)
	// means lower left corner will indicate position (0, 0)
	glutInitWindowPosition(0, 0);

	// Name to window
	glutCreateWindow("Ellipse using polynomial equation");

	// Call to myInit()
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
